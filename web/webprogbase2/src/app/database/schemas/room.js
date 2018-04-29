'use strict';

const Mongoose  = require('mongoose');

/**
 * Each connection object represents a user connected through a unique socket.
 * Each connection object composed of {userId + socketId}. Both of them together are unique.
 *
 */
let RoomSchema = new Mongoose.Schema({
    title: { type: String, required: true },
    connections: { type: [{ userId: String, socketId: String }]},
    creator: {type:String, required: true},
    painter: {type:String, default: ''},
    points: [{ username: String, points: {type: Number, default: 0} }],
    currentWord: {type:String, default: ''},
    currentRound: {type: Number, default: 0}
});

let roomModel = Mongoose.model('rooms', RoomSchema);

module.exports = roomModel;