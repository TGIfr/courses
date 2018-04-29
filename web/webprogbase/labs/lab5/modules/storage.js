const fs = require('fs');
const datebase = 'storage.json';

const mongoose = require('mongoose');
mongoose.connect('mongodb://localhost/songs', {
    useMongoClient: true,
    /* other options */
});

const db = mongoose.connection;

db.on('error', console.error.bind(console, 'connection error:'));

db.once('open', function() {
    console.log("connected to DB");
});

let songSchema = mongoose.Schema({
    name: String,
    author: String,
    length: Number,
    info: String,
    img: String
});

let song = mongoose.model('song', songSchema);

// create(x) - додати у сховище новий елемент
// getAll() - отримати списком всі об'єкти зі сховища
// getById(x_id) - отримати елемент зі сховища за ідентифікатором
// update(x) - оновити дані елемента у сховищі
// remove(x_id) - видалити елемент зі сховища за ідентифікатором


const create = async function(name, author, length, info, img){

let Song = new song({
    name: name,
    author: author,
    length: length,
    info: info,
    img:img
});
try{
    let result = await Song.save();
    //console.log(result);
} catch(e){
    console.log(e);
}

    // return new Promise(function (resolve, reject) {
    //     fs.readFile(datebase, (err, buffer) => {
    //         if(err) reject(err);
    //         else {
    //             let arr = JSON.parse(buffer);
    //             let song = new Song(arr.length, name, author, length, new Date().toISOString(), info, img);
    //             if (!arr[song.id]) {
    //                 arr[song.id] = song;
    //                 return fs.writeFile(datebase, JSON.stringify(arr, null, 4), (err) => {
    //                     if (err) reject(err);
    //                 });
    //             } else reject('song already exist');
    //         }
    //     });
    // });

};
const getAll = async() => {
    return await song.find().exec();
    // return new Promise(function (resolve, reject) {
    //     fs.readFile(datebase, (err, buffer) => {
    //         if(err) reject(err);
    //         else {
    //             resolve(JSON.parse(buffer));
    //         }
    //     });
    // });
};

const getById = async id => {
    //console.log("dich");
    return  await song.findOne({_id:id});

    // return new Promise(function (resolve, reject) {
    //     fs.readFile(datebase, (err, buffer) => {
    //         if(err) reject(err);
    //         else {
    //             let arr = JSON.parse(buffer);
    //             if(arr[id]) {
    //                 resolve(arr[id]);
    //             } else reject('song with this id not found');
    //         }
    //     });
    // });
};

const update = async (name, author, length, id,  info, img) => {
    return await song.update({ _id: id }, { $set: { name: name },
        $set: {author:author  },
        $set: { length:length },
        $set: { info:info },
        $set: { img:img }
    }, callback);
    //let foundSong =  await song.findById(id);
    // let song = new Song(id, name, author, length, new Date().toISOString(), info, img);
    //
    // return new Promise(function (resolve, reject) {
    //     fs.readFile(datebase, (err, buffer) => {
    //         if(err) reject(err);
    //         else {
    //             let arr = JSON.parse(buffer);
    //             arr[song.id] = song;
    //             fs.writeFile(datebase, JSON.stringify(arr, null, 4), (err) => {
    //                 if (err) reject(err);
    //             });
    //             resolve('data updated');
    //         }
    //     });
    // });

};
const remove = async id => {
    let res =  await song.findByIdAndRemove({_id:id});
    console.log("removed");
    console.log(res);
    // return new Promise(function (resolve, reject) {
    //     fs.readFile(datebase, (err, buffer) => {
    //         if(err) reject(err);
    //         else {
    //             let arr = JSON.parse(buffer);
    //             if(arr[id]) {
    //                 arr[id] = null;
    //                 fs.writeFile(datebase, JSON.stringify(arr, null, 4), (err) => {
    //                     if (err) reject(err);
    //                 });
    //                 resolve('data deleted');
    //             } else reject('song with this id do not exist');
    //
    //         }
    //     });
    // });

};


module.exports = {
    create  : create,
    getAll  : getAll,
    getById : getById,
    update  : update,
    remove  : remove




};
