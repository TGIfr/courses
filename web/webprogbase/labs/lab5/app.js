const express = require('express');
const bodyParser = require('body-parser');
const storage = require('./modules/storage');
const fs = require('fs');
const busboyBodyParser = require('busboy-body-parser');
const app = express();

const faker = require('faker');



app.set('view engine', 'ejs');
app.use(express.static('public'));
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(busboyBodyParser());

app.get('/', 
	(req, res) => res.render('index')
    );

app.get('/add',
    (req, res) => res.render('addNewSong'));

app.get('/sec', (req, res) =>{
    storage.create(faker.address.state(),
        faker.commerce.productName(),
        faker.random.number(),
        faker.lorem.sentence(),
        "http://thecatapi.com/api/images/get"
        );
    res.redirect('/songs');
});

app.post('/addSong',
   (req, res) => {
        try {
            let filePath = __dirname + '/public/images/' + req.files.image.name.replace(/ /g,'') ;


            fs.appendFile(filePath, req.files.image.data,   () => {
                storage.create(req.body.name, req.body.author, parseInt(req.body.length),
                    req.body.inform, '/images/' + req.files.image.name.replace(/ /g,''))
                    .then(res => console.log("res\n\n" + res))
                    .catch(err => console.log('err\n\n' + err));

            });

            res.redirect('/add');


        } catch (e) {
            console.log(e);
            res.render('404');
        }

    });

app.post('/delete',
    async(req, res) =>  {
        try {

           let smth =  await storage.remove(req.body.id);
           //console.log(smth);
            res.render('index');

        } catch (e) {
            console.log(e);
            res.render('404');
        }

    });
app.get('/songs',
    (req, res) => {
        storage.getAll()
            .then(songArrUncleaned => {
                let songArr = songArrUncleaned.filter(e => e !== null);
                console.log(songArr);
                res.render('songs', {
                    songArr
                });
            })
            .catch(err => {
                console.log(err);
                res.render('404');
            });

    });

app.get('/search/:page(\\d+)',

    (req, res) => {
        const perPage = 5;
        storage.getAll()
            .then(songArrUncleaned => {

                let songArr = songArrUncleaned.filter(e => e !== null && e.name.includes(req.query.name));
                if (!songArr || songArr.length === 0){

                    res.render('searchFailed', {
                        search: req.query.name
                    });
                    return;
                }
                let curPage = req.params.page;
                let part = songArr.slice((curPage - 1)*perPage, (curPage - 1)*perPage + perPage);
                if(part.length === 0){
                    console.log( songArr);
                    console.log(part);
                    res.render('404');
                } else {
                    res.render('searchRes', {
                        part,
                        perPage,
                        pages: Math.ceil(songArr.length / perPage),
                        search: req.query.name,
                        curPage: req.params.page
                    });
                }
            })
            .catch(err => {
                console.log(err);
                res.render('404');
            });

    });



app.get('/song/:song_id',
    (req, res, next) => {
        storage.getById(req.params.song_id)
            .then(song => {
                res.render('songTemplate', {
                    song
                });
            })
            .catch(err => {
                console.log(err);
                res.render('404');
            });

    });

app.use((req, res) => {
    res.render('404');
});

app.listen(3000, () => console.log("UP!"));
