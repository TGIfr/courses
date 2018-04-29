'use strict';

const wordArr =[
    'birthday',
    'hedgehog',
    'pizza',
    'helicopter',
    'rainbow',
    'kite',
    'christmas',
    'light',
    'shadow',
    'coffee',
    'magic',
    'cradle',
    'deer',
    'mirror',
    'fight club',
    'monster',
    'мораль сицилийской мафии',
    'cat',
    'balrog',
    'portal',
    'vezha',
    'fma',
    'kpi',
    'sikorsky',




];



const getRandomWord = function(){
 return wordArr[Math.floor(Math.random()*wordArr.length)];
};



module.exports = {
    getRandomWord
};
