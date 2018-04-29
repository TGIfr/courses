'use strict';

const userModel = require('../database').models.user;

const create = function (data, callback) {
    const newUser = new userModel(data);
    newUser.save(callback);
};

const findOne = function (data, callback) {
    userModel.findOne(data, callback);
};

const findById = function (id, callback) {
    userModel.findById(id, callback);
};

const setPicture = function(id, imageId, callback){
    const path = '/image/' + imageId;
    userModel.findByIdAndUpdate(id, { $set: { picture: path }}, callback);
};

const updateGames = function(id, won, callback){
    userModel.findByIdAndUpdate(id, { $inc: { totalGames: 1, wonGames: won?1:0 }}, callback);
};



/**
 * A middleware allows user to get access to pages ONLY if the user is already logged in.
 *
 */
const isAuthenticated = function (req, res, next) {
    if (req.isAuthenticated()) {
        next();
    } else {
        res.redirect('/');
    }
};

module.exports = {
    create,
    findOne,
    findById,
    isAuthenticated,
    setPicture,
    updateGames
};
