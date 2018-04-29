'use strict';

const Mongoose  = require('mongoose');


let ImageSchema = new Mongoose.Schema( {
    data: Buffer,
    imageName: String,
    contentType: String
});

let imageModel = Mongoose.model('images', ImageSchema);

module.exports = imageModel;