'use strict';

const app = {

    chat: function (roomId, username) {

        const socket = io({transports: ['websocket']});

        const canvas = $('.whiteboard')[0];
        const colors = $('.color');
        let context = canvas.getContext('2d');

        const current = {
            color: 'black'
        };
        let drawing = false;

        let gameMode = 'chat';

        $(document).ready(function () {
            $("canvas").mousedown(onMouseDown);

            $("canvas").mouseup(onMouseUp);

            $("canvas").mouseout(onMouseUp);

            $("canvas").mousemove(function (e) {
                throttle(onMouseMove(e), 10)
            });

        });

        for (let i = 0; i < colors.length; i++) {
            colors[i].addEventListener('click', onColorUpdate, false);
        }

        socket.on('drawing', onDrawingEvent);

        //window.addEventListener('resize', onResize, false);
        onResize();


        function drawLine(x0, y0, x1, y1, color, emit) {
            context.beginPath();
            context.moveTo(x0, y0);
            context.lineTo(x1, y1);
            context.strokeStyle = color;
            context.lineWidth = 5;
            context.closePath();
            context.stroke();
            if (!emit) {
                return;
            }
            const w = canvas.width;
            const h = canvas.height;

            socket.emit('drawing', roomId, {
                x0: x0 / w,
                y0: y0 / h,
                x1: x1 / w,
                y1: y1 / h,
                color: color
            });
        }

        function onMouseDown(e) {
            drawing = true;
            current.x = e.pageX - canvas.offsetLeft;
            current.y = e.pageY - canvas.offsetTop;
        }

        function onMouseUp(e) {
            if (!drawing || gameMode === 'chat') {
                return;
            }
            drawing = false;
            drawLine(current.x, current.y, e.pageX - canvas.offsetLeft, e.pageY - canvas.offsetTop, current.color, true);
        }

        function onMouseMove(e) {
            if (!drawing || gameMode === 'chat') {
                return;
            }
            drawLine(current.x, current.y, e.pageX - canvas.offsetLeft, e.pageY - canvas.offsetTop, current.color, true);
            current.x = e.pageX - canvas.offsetLeft;
            current.y = e.pageY - canvas.offsetTop;
        }

        function onColorUpdate(e) {
            current.color = e.target.className.split(' ')[1];
        }

        // limit the number of events per second
        function throttle(callback, delay) {
            let previousCall = new Date().getTime();
            return function () {
                const time = new Date().getTime();

                if ((time - previousCall) >= delay) {
                    previousCall = time;
                    callback.apply(null, arguments);
                }
            };
        }

        function onDrawingEvent(data) {
            const w = canvas.width;
            const h = canvas.height;
            drawLine(data.x0 * w, data.y0 * h, data.x1 * w, data.y1 * h, data.color);
        }

        // make the canvas fill its parent
        function onResize() {
            canvas.width = $("#drawing").width();
            canvas.height = $("#drawing").height();
            //context = canvas.getContext('2d');
        }

        function clearCanvas(){
            context.clearRect(0, 0, canvas.width, canvas.height);
        }

        // When socket connects, join the current chatroom
        socket.on('connect', function () {

            socket.emit('join', roomId);

            // Update users list upon emitting updateUsersList event
            socket.on('updateUsersList', function (users, clear) {

                $('.container p.message').remove();
                if (users.error != null) {
                    $('.container').html(`<p class="message error">${users.error}</p>`);
                } else {
                    //console.log(users);
                    $(".ban").unbind('submit');
                    app.helpers.updateUsersList(users, clear, username);
                    $(".ban").submit(function( event ) {
                        socket.emit('tryBan' ,roomId, event.currentTarget[0].value);
                        event.preventDefault();
                    });
                }
            });



            //ban case
            socket.on('ban', () => window.location.href='/');

            $("#clearCanvas").click(()=>{
                if(gameMode !== 'chat') {
                    clearCanvas();
                    socket.emit('clearCanvas', roomId);
                }
            });

            socket.on('currentGameMode', function(game){
                if(game.isGoing){
                    gameMode = game.painter === username? 'paint' : 'chat';
                    if(game.painter === username)
                        app.helpers.serverMessage('The word is: ' + game.word);
                } else{
                    gameMode = 'default'
                }

                let  message = gameMode !== 'default'? 'You gonna ' + gameMode + ' now' :
                        'Well, just help yourself. Also you can enter /start';

                app.helpers.serverMessage(message);
                if(Math.random() > 0.8 && gameMode === 'default')
                    app.helpers.serverMessage('/start is kinda a red pill. Think about it..' );

            });

            socket.on('serverMessage', data => {app.helpers.serverMessage(data); console.log('SERER MESSAGE ON')});

            socket.on('clearCanvas', () => clearCanvas());

            // Whenever the user hits the save button, emit newMessage event.
            $(".chat-message button").on('click', function (e) {
                //chatting is not allowed for painter
                if(gameMode === 'paint') return;

                const textareaEle = $("textarea[name='message']");
                const messageContent = textareaEle.val().trim();
                if (messageContent !== '') {
                    const message = {
                        content: messageContent,
                        username: username,
                        date: Date.now()
                    };

                    socket.emit('newMessage', roomId, message);
                    textareaEle.val('');
                    app.helpers.addMessage(message);
                }
            });

            // Whenever a user leaves the current room, remove the user from users list
            socket.on('removeUser', function (userId) {
                $('li#user-' + userId).remove();
                app.helpers.updateNumOfUsers();
            });

            // Append a new message
            socket.on('addMessage', function (message) {
                app.helpers.addMessage(message);
            });
        });
    },

    helpers: {

        serverMessage: function(data){
            const message = {
                content: data,
                username: 'SERVER',
                date: Date.now()
            };
            console.log('SERVER MESSAGE');
            console.log(data);
            app.helpers.addMessage(message);
        },

        encodeHTML: function (str) {
            return $('<div />').text(str).html();
        },

        // Update users list
        updateUsersList: function (users, clear, username) {
            if (users.constructor !== Array) {
                users = [users];
            }

            let creator = $('#roomCreatorHolder').val();
            let html = '';
            for (const user of users) {
                let curUsername = user.username;
                user.username = this.encodeHTML(user.username);
                html += `<li class="clearfix" id="user-${user._id}">
                     <img src="${user.picture}" alt="${user.username}" />
                     <div class="about">
                        <div class="name">${user.username}</div>
                        <div class="status"><i class="fa fa-circle online"></i> online</div>
                     </div>`;
                if((username === creator || username === 'admin') && username !== curUsername && curUsername !== 'admin'){
                    html += `<div ><form class="ban" action="#" ">
                                  <input hidden value="${user._id}" name="id">
                                  <button type="submit" class="fa fa-ban" aria-hidden="true"
                                   style="background-color: rgb(226, 98, 92)"></button>
                                </form> </div>`;
                }
                html += '</li>';
            }

            if (html === '') {
                return;
            }

            if (clear != null && clear == true) {
                $('.users-list ul').html('').html(html);
            } else {
                $('.users-list ul').prepend(html);
            }

            this.updateNumOfUsers();
        },

        // Adding a new message to chat history
        addMessage: function (message) {
            console.log('add message');
            console.log(message);
            message.date = (new Date(message.date)).toLocaleString();
            message.username = this.encodeHTML(message.username);
            message.content = this.encodeHTML(message.content);

            const html = `<li>
                    <div class="message-data">
                      <span class="message-data-name">${message.username}</span>
                      <span class="message-data-time">${message.date}</span>
                    </div>
                    <div class="message my-message" dir="auto">${message.content}</div>
                  </li>`;
            $(html).hide().appendTo('.chat-history ul').slideDown(200);

            // Keep scroll bar down
            $(".chat-history").animate({scrollTop: $('.chat-history')[0].scrollHeight}, 800);
        },


        // Update number of online users in the current room
        // This method MUST be called after adding, or removing list element(s)
        updateNumOfUsers: function () {
            const num = $('.users-list ul li').length;
            $('.chat-num-users').text(num + " User(s)");
        }
    }
};
