const express = require('express');
const bodyParser = require('body-parser');
const storage = require('./modules/storage');

const app = express();

app.set('view engine', 'ejs');
app.use(express.static('public'));
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());


app.get('/', 
	(req, res) => res.sendFile(__dirname + '/views/index.html'));

// app.get('/songs',
//     (req, res) => res.sendFile(__dirname + '/views/songs.html'));

app.get('/songs',
    (req, res) => {
        storage.getAll()
            .then(songArr => {
                res.render('songs', {
                    songArr
                });
            })
            .catch(err => {
                console.log(err);
                res.sendFile(__dirname + '/views/404.html');
            });

    });

app.get('/song/:song_id(\\d+)',
    (req, res, next) => {
        storage.getById(parseInt(req.params.song_id))
            .then(song => {
                res.render('songTemplate', {
                    song
                });
            })
            .catch(err => {
                console.log(err);
                res.sendFile(__dirname + '/views/404.html');
            });
        //console.log(song);
        // if (!song) {
        //     return next("Error!");
        // } else {
        //     res.render('songTemplate', {
        //         song
        //     });
        // }
    });

app.use((req, res) => {
    res.sendFile(__dirname + '/views/404.html');
});

app.listen(3000, () => console.log("UP!"));
