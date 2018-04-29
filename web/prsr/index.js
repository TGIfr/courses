var fs = require('fs');
var obj;
var res = [];
fs.readFile('convertjson.json', 'utf8', function (err, data) {
    if (err) throw err;
    obj = JSON.parse(data);
    for(var dich of obj){
        res.push(dich['Професійна назва роботи']);
        //console.log(dich['Професійна назва роботи']);
    }
    console.log(res);
    fs.writeFile('myjsonfile.json', JSON.stringify(res), 'utf8', ()=>console.log('wrtn'));
});