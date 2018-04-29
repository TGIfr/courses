const fs = require('fs');
const datebase = 'storage.json';

// create(x) - додати у сховище новий елемент
// getAll() - отримати списком всі об'єкти зі сховища
// getById(x_id) - отримати елемент зі сховища за ідентифікатором
// update(x) - оновити дані елемента у сховищі
// remove(x_id) - видалити елемент зі сховища за ідентифікатором
function Song(id, name, author, length, date) {
    return{
        name: name,
        author: author,
        length: length,
        id: id,
        date: date,
    };
};

const create = function(id, name, author, length, date){
    let song = new Song(id, name, author, length, date);

    return new Promise(function (resolve, reject) {
        fs.readFile(datebase, (err, buffer) => {
            if(err) reject(err);
            else {
                let arr = JSON.parse(buffer);
                if (!arr[song.id]) {
                    arr[song.id] = song;
                    return fs.writeFile(datebase, JSON.stringify(arr, null, 4), (err) => {
                        if (err) reject(err);
                    });
                } else reject('song already exist');
            }
        });
    });

};
const getAll = () => {
    return new Promise(function (resolve, reject) {
        fs.readFile(datebase, (err, buffer) => {
            if(err) reject(err);
            else {
                resolve(JSON.parse(buffer));
            }
        });
    });
};

const getById = id => {
    return new Promise(function (resolve, reject) {
        fs.readFile(datebase, (err, buffer) => {
            if(err) reject(err);
            else {
                let arr = JSON.parse(buffer);
                if(arr[id]) {
                    resolve(arr[id]);
                } else reject('song with this id not found');
            }
        });
    });
};

const update = (id, name, author, length,  date) => {
    let song = new Song(id, name, author, length, date);

    return new Promise(function (resolve, reject) {
        fs.readFile(datebase, (err, buffer) => {
            if(err) reject(err);
            else {
                let arr = JSON.parse(buffer);
                arr[song.id] = song;
                fs.writeFile(datebase, JSON.stringify(arr, null, 4), (err) => {
                    if (err) reject(err);
                });
                resolve('data updated');
            }
        });
    });

};
const remove = id => {
    return new Promise(function (resolve, reject) {
        fs.readFile(datebase, (err, buffer) => {
            if(err) reject(err);
            else {
                let arr = JSON.parse(buffer);
                if(arr[id]) {
                    arr[id] = null;
                    fs.writeFile(datebase, JSON.stringify(arr, null, 4), (err) => {
                        if (err) reject(err);
                    });
                    resolve('data deleted');
                } else reject('song with this id do not exist');

            }
        });
    });

};


module.exports = {
    create  : create,
    getAll  : getAll,
    getById : getById,
    update  : update,
    remove  : remove
};
