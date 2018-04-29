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

let userSchema = mongoose.Schema({
    username: String,
    passwordHash: String,
    role: String
});

let song = mongoose.model('song', songSchema);
let User = mongoose.model('User', userSchema);


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

};
const getAll = async() => {
    return await song.find().exec();

};

const getById = async id => {
    //console.log("dich");
    return  await song.findOne({_id:id});


};

const update = async (name, author, length, id,  info, img) => {
    return await song.update({ _id: id }, { $set: {
        name: name ,
        author:author,
        length:length,
        info:info,
        img:img }
    }, callback);


};
const remove = async id => {
    let res =  await song.findByIdAndRemove({_id:id});
    console.log("removed");
    console.log(res);

};


module.exports = {
    create  : create,
    getAll  : getAll,
    getById : getById,
    update  : update,
    remove  : remove,
    User: User




};
