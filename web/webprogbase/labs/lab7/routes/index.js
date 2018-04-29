const express = require('express');
const router = express.Router();
const auth = require('basic-auth');
const storage = require('../modules/storage');
const fs = require('fs');

router.post('/addSong', (req, res) => {
    const user = findUser(req);
    if(!user){
        res.render('/401');
        return;
    }
    try {
        let filePath = __dirname + '/public/images/' + req.files.image.name.replace(/ /g,'') ?
            req.files.image.name.replace(/ /g,'') : '0.jpg';
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
        res.json({message: 'successfully added'});
    } catch (e) {
        console.log(e);
        res.render('/404');
    }


});

router.delete('/delete/:id', async(req, res) =>  {
        const user = findUser(req);
        if(!user){
            res.render('/401');
            return;
        }

        try {
            let smth =  await storage.remove(req.params.id);
            //console.log(smth);
            res.message('successfully deleted');
        } catch (e) {
            console.log(e);
            res.render('/404');
        }
    });

router.get('/songs/:page(\\d+)', (req, res) => {
    const user = findUser(req);
    if(!user){
        res.render('/401');
        return;
    }
    const perPage = 5;
        storage.getAll()
            .then(songArrUncleaned => {
                let songArr = songArrUncleaned.filter(e => e !== null );
                if (!songArr || songArr.length === 0){
                    res.json({err : 'not found'});
                    return;
                }
                let curPage = req.params.page;
                let part = songArr.slice((curPage - 1)*perPage, (curPage - 1)*perPage + perPage);
                if(part.length === 0){
                    console.log( songArr);
                    console.log(part);
                    res.json({err : 'not found'});
                } else {
                    res.json({
                        part: part,
                        perPage: perPage,
                        pages: Math.ceil(songArr.length / perPage)
                    });
                }
            })
            .catch(err => {
                console.log(err);
                res.render('/404');
            });
    });

router.get('/search/:page(\\d+)', (req, res) => {
    const user = findUser(req);
    if(!user){
        res.render('/401');
        return;
    }

        const perPage = 5;
        storage.getAll()
            .then(songArrUncleaned => {
                let songArr = songArrUncleaned.filter(e => e !== null && e.name.includes(req.query.name));
                if (!songArr || songArr.length === 0){
                    res.render('/404');
                    return;
                }
                let curPage = req.params.page;
                let part = songArr.slice((curPage - 1)*perPage, (curPage - 1)*perPage + perPage);
                if(part.length === 0){
                    console.log( songArr);
                    console.log(part);
                    res.render('/404');
                } else {
                    res.json({
                        part: part,
                        perPage: perPage,
                        pages: Math.ceil(songArr.length / perPage)
                    });
                }
            })
            .catch(err => {
                console.log(err);
                res.render('/404');
            });

    });

router.put('/update/:id', (req, res) =>
    {
        const user = findUser(req);
        if(!user){
            res.render('/401');
            return;
        }
        try {
            let filePath = __dirname + '/public/images/' + req.files.image.name.replace(/ /g,'') ?
                req.files.image.name.replace(/ /g,'') : '0.jpg';
            fs.appendFile(filePath, req.files.image.data,   () => {
                storage.update(req.body.name,
                    req.body.author,
                    parseInt(req.body.length),
                    req.params.id,
                    req.body.inform,
                    '/images/' + req.files.image.name.replace(/ /g,'')
                )
                    .then(res => console.log("res\n\n" + res))
                    .catch(err => console.log('err\n\n' + err));
            });
            res.json({message: 'successfully updated'});
        } catch (e) {
            console.log(e);
            res.render('/404');
        }

    }
);

router.get('/song/:song_id', (req, res, next) => {
    const user = findUser(req);
    if(!user){
        res.render('/401');
        return;
    }
        storage.getById(req.params.song_id)
            .then(song => {
                res.json(song);
            })
            .catch(err => {
                console.log(err);
                res.render('/404');
            });

    });

const findUser = function (req) {
    const credentials = auth(req);
    if(!user ){
        return null;
    } else {
        storage.User.findOne({username: credentials.name, passwordHash: credentials.pass})
            .then(user => {
                return user ? user : null;
            });
    }
};

router.get('/404', (req, res) => {
    res.json({message: 'page not found'});
});
router.get('/401', (req, res) => {
    res.json({message: 'unauthorised'});
});

module.exports = router;