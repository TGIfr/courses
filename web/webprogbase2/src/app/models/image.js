'use strict';

const imageModel = require('../database').models.image;

const create = function (data, callback) {
    const newImage = new imageModel(data);
    newImage.save(callback);
};


const findById = async function (id) {
    return await imageModel.findById(id);
};



module.exports = {
    create,
    findById
};
