const express = require('express');
const bodyParser = require('body-parser');
const storage = require('./modules/storage');
const fs = require('fs');
const busboyBodyParser = require('busboy-body-parser');
const app = express();
const router = require('./routes/index');
const engines = require('consolidate');





//
const faker = require('faker');

//auth
const cookieParser = require('cookie-parser');
const session = require('express-session');
const crypto = require('crypto');
const passport = require('passport');
const LocalStrategy = require('passport-local').Strategy;


/////////


//app.set('view engine', 'ejs');
app.use(express.static('public'));
app.engine('html', require('ejs').renderFile);

//files
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(busboyBodyParser());

//auth
app.use(cookieParser());
app.use(session({
    secret: 'SEGReT$25_',
    resave: false,
    saveUninitialized: true
}));
app.use(passport.initialize());
app.use(passport.session());

//
const serverSalt = "KindaKatzhenDICH";

function sha512(password, salt) {
    const hash = crypto.createHmac('sha512', salt);
    hash.update(password);
    const value = hash.digest('hex');
    return {
        salt: salt,
        passwordHash: value
    };
}

//

passport.use(new LocalStrategy(
    function (username, password, done) {
        let hash = sha512(password, serverSalt).passwordHash;
        //console.log(username, password);
        storage.User.findOne({username: username, passwordHash: hash})
            .then(user => {
                // console.log("dich1");
                // console.log(user);
                // console.log("dich2");
                //if(user != null) console.log("dich");
                done(user  ? null : 'No user 1 ', user);

            });
    }
));

passport.serializeUser(function (user, done) {
    done(null, user.id);
});

passport.deserializeUser(function (id, done) {
    //console.log(id);
    storage.User.findOne({_id : id})
        .then(user => {
           // console.log(user);
            done(user  ? null : 'No user 2 ', user);

        });
});

//





app.get('/', 
	(req, res) => res.render('index.ejs', {
        user: req.user
    })
    );

app.use('/api/v1/', router);

app.get('/register',
    (req, res) => res.render('register.ejs', {
        user: req.user
    }));

app.post('/register',
    async (req, res) => {
        let user = new storage.User({
            username: req.body.username,
            passwordHash: sha512(req.body.password, serverSalt).passwordHash,
            role: req.body.username === 'admin' ? 'admin' : 'student'
        });

        await user.save();
        res.redirect('/');

    });

app.get('/login',
    (req, res) => res.render('login.ejs', {
        user: req.user
    }));

app.get('/logout',
    checkAuth,
    (req, res) => {
        req.logout();
        res.redirect('/');
    });

app.post('/login',
    passport.authenticate('local', {
        successRedirect: '/',
        failureRedirect: '/login'
    }));

function checkAuth(req, res, next) {
    if (!req.user) return res.redirect('404');
    next();
}

app.get('/profile',
    checkAuth,
    async (req, res) => {
        res.render('profile.ejs', {
            user: req.user
        });
    });

function checkAdmin(req, res, next) {
    if (req.user.role !== 'admin') return res.sendStatus(403);
    next();
}

app.get('/admin',
    checkAuth,
    checkAdmin,
    (req, res) => {
        storage.User.find().exec()
            .then(users => {
                res.render('admin.ejs', {
                    user: req.user,
                    users: users
                });
            })
            .catch(() => res.sendStatus(500));
    });


app.get('/add',
    checkAuth,
    (req, res) => res.render('addNewSong.ejs', {
        user: req.user
    }));

app.get('/sec',
    checkAuth,
    checkAdmin,
    (req, res) =>{
    storage.create(faker.address.state(),
        faker.commerce.productName(),
        faker.random.number(),
        faker.lorem.sentence(),
        "http://thecatapi.com/api/images/get"
        );
    res.redirect('/songs');
});

app.post('/addSong',
    checkAuth,
   (req, res) => {
        try {
            let filePath = __dirname + '/public/images/' + req.files.image.name.replace(/ /g,'') ;
            fs.appendFile(filePath, req.files.image.data,   () => {
                storage.create(req.body.name,
                    req.body.author,
                    parseInt(req.body.length),
                    req.body.inform,
                    '/images/' + req.files.image.name.replace(/ /g,'')
                )
                    .then(res => console.log("res\n\n" + res))
                    .catch(err => console.log('err\n\n' + err));
            });
            res.redirect('/add');
        } catch (e) {
            console.log(e);
            res.render('404.ejs');
        }
    });

app.post('/delete',
    checkAuth,
    async(req, res) =>  {
        try {
           let smth =  await storage.remove(req.body.id);
           //console.log(smth);
            res.render('index.ejs');
        } catch (e) {
            console.log(e);
            res.render('404.ejs');
        }
    });

app.get('/songs',
    checkAuth,
    (req, res) => {
        storage.getAll()
            .then(songArrUncleaned => {
                let songArr = songArrUncleaned.filter(e => e !== null);
                //console.log(songArr);
                res.render('songs.ejs', {
                    songArr,
                    user: req.user
                });
            })
            .catch(err => {
                console.log(err);
                res.render('404.ejs');
            });

    });

app.get('/docs/api/v1', (req,res) => res.sendFile(__dirname + '/public/docs/doc.json'));
app.get('/search',
    checkAuth,
    (req, res) => {
        const perPage = 5;

                    res.render('searchRes.html', {
                        perPage,
                        search: req.query.name,
                        user: req.user
                    });

    });



app.get('/song/:song_id',
    checkAuth,
    (req, res, next) => {
        storage.getById(req.params.song_id)
            .then(song => {
                res.render('songTemplate.ejs', {
                    song,
                    user: req.user
                });
            })
            .catch(err => {
                console.log(err);
                res.render('404.ejs');
            });

    });

app.use((req, res) => {
    res.render('404.ejs');
});

app.listen(8080, () => console.log("UP!"));
