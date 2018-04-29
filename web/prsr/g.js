let values = require('./convertjson.json');

let newValues = values.map(x => x['Професійна назва роботи']);
console.log(newValues);

let fs = require('fs');
fs.writeFileSync('new.json', JSON.stringify(newValues));