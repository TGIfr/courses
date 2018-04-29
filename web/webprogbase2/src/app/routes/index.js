'use strict';

const express = require('express');
const router = express.Router();
const passport = require('passport');

const User = require('../models/user');
const Room = require('../models/room');
const Image = require('../models/image');
const Word = require('../models/word');


// Home page
router.get('/', function(req, res, next) {
	// If user is already logged in, then redirect to create room
	if(req.isAuthenticated()){
		res.redirect('/createroom');
	}
	else{
		res.render('login', {
			success: req.flash('success')[0],
			errors: req.flash('error'), 
			showRegisterForm: req.flash('showRegisterForm')[0]
		});
	}
});

router.get('/image/:id', async (req, res) =>{
	const id = req.params.id;
	const image = await Image.findById(id);
    res.setHeader('Cache-Control', 'public, max-age=3000000');
    res.contentType(image.contentType);
    res.send(image.data);
});

router.post('/changeAvatar',
    (req, res) => {
	//console.log(req.files);
        if (req.files !== undefined ) {
            const content = req.files.image;
            if (content.name.match(/\.(jpeg|jpg|gif|png)$/) !== null) {
                let format = content.name.split('.').pop();
                Image.create({
                    data: content.data,
                    imageName: content.name,
                    contentType: format
                }, (err, im) => {
                    if (err) throw err;
                    //console.log(im);
                    User.setPicture(req.body.id, im.id, err => console.log(err))
                });
            }
        }
        res.redirect('/');
    });


router.get('/createroom', User.isAuthenticated, async (req, res) => {

	const mainRoom = await Room.mainRoom();

    res.render('createroom', {
        user : req.user,
		mainRoomId: mainRoom.id,
        errors: req.flash('error')
    })

});

router.get('/profile', User.isAuthenticated, async (req, res) => {

    res.render('profile', {
        user : req.user
    })

});


router.post('/createroom', (req, res) => {
	const title = req.body.title;
    Room.findOne({'title': new RegExp('^' + title + '$', 'i')}, function(err, room){
        if(err) throw err;
        if(!room){
            Room.create({
                title: title,
				creator: req.body.creator
            }, function(err, newRoom){
                if(err) {
                	console.log(err);
                	res.redirect('/');
                } else{
                    let url = req.protocol + '://' + req.get('host') + '/chat/';
                	res.render('showRoomLink', {room:newRoom, url:url});
				}
            });
        } else{
            req.flash('error', 'Room with this name already exists.');
            res.redirect('/createroom');
		}
    });
});

// Login
router.post('/login', passport.authenticate('local', { 
	successRedirect: '/createroom',
	failureRedirect: '/',
	failureFlash: true
}));

// Register via username and password
router.post('/register', function(req, res, next) {

    const credentials = {'username': req.body.username, 'password': req.body.password};

    if(credentials.username === '' || credentials.password === ''){
		req.flash('error', 'Missing credentials');
		req.flash('showRegisterForm', true);
		res.redirect('/');
	}else{

		// Check if the username already exists for non-social account
		User.findOne({'username': new RegExp('^' + req.body.username + '$', 'i'), 'socialId': null}, function(err, user){
			if(err) console.log(err);
			if(user){
				req.flash('error', 'Username already exists.');
				req.flash('showRegisterForm', true);
				res.redirect('/');
			}else{
				User.create(credentials, function(err, newUser){
					if(err) throw err;
					req.flash('success', 'Your account has been created. Please log in.');
					res.redirect('/');
				});
			}
		});
	}
});


// Rooms
router.get('/rooms', [User.isAuthenticated, function(req, res, next) {
	Room.find(function(err, rooms){
		if(err) console.log(err);
		res.render('rooms', { rooms });
	});
}]);

router.get('/contacts', (req, res, next) => {

        res.render('contacts');
});

// Chat Room 
router.get('/chat/:id', [User.isAuthenticated, function(req, res, next) {
    const roomId = req.params.id;
    Room.findById(roomId, function(err, room){
		if(err) console.log(err);
		if(!room || req.user.banList.includes(req.params.id)){
			return next(); 
		}
		res.render('chatroom', { user: req.user, room: room });
	});
	
}]);

// Logout
router.get('/logout', function(req, res, next) {
	// remove the req.user property and clear the login session
	req.logout();

	// destroy session data
	req.session = null;

	// redirect to homepage
	res.redirect('/');
});

module.exports = router;