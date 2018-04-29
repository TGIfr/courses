'use strict';


const Room = require('../models/room');
const Word = require("../models/word");

/**
 * Encapsulates all code for emitting and listening to socket events
 *
 */
const ioEvents = function (io) {


    io.sockets.on('connection', function (socket) {

        // Join a chatroom
        socket.on('join', function (roomId) {
            Room.findById(roomId, function (err, room) {
                if (err) throw err;
                if (!room) {
                    // Assuming that you already checked in router that chatroom exists
                    // Then, if a room doesn't exist here, return an error to inform the client-side.
                    socket.emit('updateUsersList', {error: 'Room doesnt exist.'});
                } else {
                    // Check if user exists in the session
                    if (socket.request.session.passport == null) {
                        return;
                    }

                    Room.addUser(room, socket, function (err, newRoom) {

                        // Join the room channel
                        socket.join(newRoom.id);

                        Room.getUsers(newRoom, socket, function (err, users, cuntUserInRoom) {
                            if (err) throw err;

                            //console.log(users);

                            // Return list of all user connected to the room to the current user
                            socket.emit('updateUsersList', users, true);

                            //sends current game mode
                            socket.emit('currentGameMode', {
                                    isGoing: newRoom.painter !== null,
                                    painter: newRoom.painter,
                                    word: newRoom.currentWord
                                }
                            );

                            // Return the current user to other connecting sockets in the room
                            // ONLY if the user wasn't connected already to the current room
                            if (cuntUserInRoom === 1) {
                                socket.broadcast.to(newRoom.id).emit('updateUsersList', users[users.length - 1]);
                            }
                        });
                    });
                }
            });
        });

        socket.on('tryBan', function (roomId, idToBan) {
            Room.findById(roomId, function (err, room) {
                if (err) throw err;
                if (room) {

                    Room.getUsers(room, socket, function (err, users, cuntUserInRoom) {
                        if (err) throw err;

                        let userToBan = users.find(x => x.id === idToBan);

                        //user now is unable to get back to this room
                        userToBan.banList.push(roomId);
                        userToBan.save();

                        //disconnect user(just go to index, lol)
                        Room.getAllSocketIdOfUser(room, idToBan).forEach(soc => {
                                socket.to(soc.socketId).emit('ban');
                            }
                        );

                    });
                }

            });
        });
        // When a socket exits
        socket.on('disconnect', function () {

            // Check if user exists in the session
            if (socket.request.session.passport == null) {
                return;
            }

            // Find the room to which the socket is connected to,
            // and remove the current user + socket from this room
            Room.removeUser(socket, function (err, room, userId, cuntUserInRoom) {
                if (err) throw err;

                // Leave the room channel
                socket.leave(room.id);

                // Return the user id ONLY if the user was connected to the current room using one socket
                // The user id will be then used to remove the user from users list on chatroom page
                if (cuntUserInRoom === 1) {
                    socket.broadcast.to(room.id).emit('removeUser', userId);
                }
            });
        });

        // When a new message arrives
        socket.on('newMessage', function (roomId, message) {
            const maxRounds = 7;

            Room.findById(roomId, function (err, room) {
                if (err) throw err;
                if (room) {
                    // room.currentWord = null;
                    // room.painter = null;
                    // room.save(function (err) {
                    //     if (err) console.log(err);
                    //     // saved!
                    // });
                    Room.getUsers(room, socket, function (err, users, cuntUserInRoom) {
                        if (room.painter === null && message.content.includes('/start')) {

                            //console.log('sterter');
                            if (err) console.log(err);
                            if (users.length >= 2) {
                                room.points = [];
                                room.currentRound = 0;
                                rounder(room, users);
                            } else {
                                io.sockets.in(roomId).emit('serverMessage', "it's a bit too lonely here");
                                //console.log('lonely');
                            }

                        } else if (message.content.toLowerCase().includes(room.currentWord)) {
                            //console.log('gotcha right word');
                            if(room.points.find(x => x.username === message.username)){
                                room.points = room.points.map(x => {
                                    if(x.username === message.username){
                                        x.points += 5;
                                    }
                                    return x;
                                })
                            } else {
                                room.points.push({username: message.username, points: 5});
                            }

                            if(room.points.find(x => x.username === room.painter)){
                                room.points = room.points.map(x => {
                                    if(x.username === room.painter){
                                        x.points += 3;
                                    }
                                    return x;
                                });


                            } else {
                                room.points.push({username: room.painter, points: 3});
                            }
                            //console.log(room.points);
                            io.sockets.in(roomId).emit('serverMessage', `${message.username} + 5,${room.painter} + 3 `);
                            rounder(room, users);
                        }
                    });
                }
            });

            const rounder = function (room, users) {
                //console.log('rounder');
                if(users.length < 1 || room.currentRound === maxRounds){
                    finishGame(room, users);
                    return;
                }

                //game data sets
                room.currentRound++;
                let user = users[Math.floor(Math.random()*users.length)];
                let word = Word.getRandomWord();
                room.painter = user.username;
                room.currentWord = word;

                //send messages
                io.sockets.in(roomId).emit('currentGameMode', {
                        isGoing: room.painter !== null,
                        painter: room.painter,
                        word: room.currentWord
                    }
                );
                if(room.currentRound !== 1)
                sendLeaderboard(room);
                room.save(function (err) {
                    if (err) console.log(err);
                    // saved!
                });

                setTimeout(timerFunc, 60000, room.currentRound);
            };

            const timerFunc = function(currentRound){
                //console.log('timer func');
                console.log(currentRound);
                Room.findById(roomId, function (err, room) {
                    if (err) throw err;
                    if (room) {

                        Room.getUsers(room, socket, function (err, users, cuntUserInRoom) {
                            if(room.currentRound === currentRound){
                                rounder(room, users);
                                //console.log('worked');
                            }

                        });
                    }
                });
            };
            const sendLeaderboard = function(room){
                let arr = room.points;
                arr.sort(function(a, b) {
                    return b.points - a.points;
                });
                let res = 'LB:';
                for(let i  = 0; i < 3; i++){
                    if(arr[i]){
                         res += ` ${i}. ${arr[i].username} ${arr[i].points}`;
                    }
                }
                if(res !== 'LB:'){
                    io.sockets.in(room.id).emit('serverMessage', res);
                }
            };


            const finishGame = function (room, users) {
                sendLeaderboard(room);

                //console.log('finisher');
                room.points.sort(function(a, b) {
                    return b.points - a.points;
                });

                users.forEach(x => {
                    x.totalGames++;
                    if(x !== undefined && room.points[0] !== undefined && x.username === room.points[0].username ) {
                        x.wonGames++;
                        io.sockets.in(room.id).emit('serverMessage',
                            `${room.points[0].username} has won with ${room.points[0].points}`);
                    }
                    x.save();
                });
                room.currentRound = 0;
                room.painter = null;
                room.currentWord = null;
                room.points = [];

                io.sockets.in(roomId).emit('currentGameMode', {
                        isGoing: room.painter !== null,
                        painter: room.painter,
                        word: room.currentWord
                    }
                );

                room.save(function (err) {
                    if (err) console.log(err);
                    // saved!
                });
            };


            //check game state
            //check on /start
            //start game(set curword painter
            //else check on guessed word
            //if guessed increase points, check if to finish game(if so, set painter and word to null
            //


            //rounder set word, painter, send messages about round, TIMER

            // No need to emit 'addMessage' to the current socket
            // As the new message will be added manually in 'main.js' file
            // socket.emit('addMessage', message);

            socket.broadcast.to(roomId).emit('addMessage', message);
        });

        socket.on('drawing', (roomId, data) => socket.broadcast.to(roomId).emit('drawing', data));

        socket.on('clearCanvas', roomId => socket.broadcast.to(roomId).emit('clearCanvas'));

    });
};

const checkIfMainExist = function () {
    Room.findOne({'title': 'main'}, function (err, room) {
        if (err) throw err;
        if (!room) {
            Room.create({
                title: 'main',
                creator: 'admin'
            }, function (err) {
                if (err) throw err;
            });
        }
    });
};

/**
 * Initialize Socket.io
 */
const init = function (app) {

    const server = require('http').Server(app);
    const io = require('socket.io')(server);

    checkIfMainExist();

    // Force Socket.io to ONLY use "websockets"; No Long Polling.
    io.set('transports', ['websocket']);

    // Allow sockets to access session data
    io.use((socket, next) => {
        require('../session')(socket.request, {}, next);
    });

    // Define all Events
    ioEvents(io);

    // The server object will be then used to list to a port number
    return server;
};

module.exports = init;