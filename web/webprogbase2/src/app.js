'use strict';

// Chat application dependencies
const express = require('express');
const app = express();
const path = require('path');
const bodyParser = require('body-parser');
const flash = require('connect-flash');
const busboyBodyParser = require('busboy-body-parser');

// Chat application components
const routes = require('./app/routes');
const session = require('./app/session');
const passport = require('./app/auth');
const ioServer = require('./app/socket')(app);

// Set the port number
const port = process.env.PORT || 3000;

// View engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');

// Middlewares
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(busboyBodyParser({ limit: '500kb' }));
app.use(express.static('public'));

app.use(session);
app.use(passport.initialize());
app.use(passport.session());
app.use(flash());

app.use('/', routes);


// Middleware to catch 404 errors
app.use(function(req, res, next) {
    res.render('404');
});

ioServer.listen(port);