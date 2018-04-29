const storage = require('./modules/storage');
const prompt = require('prompt');




prompt.start();

const schema = {
    properties: {
        func: {
            description: 'Enter any function of storage or exit to stop the program\n',
            pattern: /^[a-zA-Z\s\-]+$/,
            required: true
        },
        id: {
            pattern: /^[0-9]+$/,
            message: 'id must be only numbers',
            required: false
        },
        name: {
            pattern: /^[a-zA-Z\s\-]+$/,
            message: 'Name must be only letters, spaces, or dashes',
            required: false
        },
        author: {
            pattern: /^[a-zA-Z\s\-]+$/,
            message: 'author must be only letters, spaces, or dashes',
            required: false
        },

        length: {
            pattern: /^[0-9]+$/,
            message: 'length must be only numbers',
            required: false
        },



    }
};

const askQuestion = ()=> {
    prompt.get(schema, function (err, result) {
        if(err){
            console.log(err);
            askQuestion();
        }
        //
        // Log the results.
        //
        // console.log('Command-line input received:');
        // console.log('  proxy: ' + result.func);
        // console.log('  credentials: ' + result.id);

        switch(result.func){
            case 'exit':
                console.log(`Exit.`);
                return;
                break;
            case 'create':
                if(result.id){
                    storage.create(result.id ,result.name , result.author , result.length, new Date().toISOString())
                        .then(res => console.log("res\n\n" + res))
                        .catch(err => console.log('err\n\n' + err));
                }
                break;
            case 'getAll':
                storage.getAll()
                    .then( data => console.log(data))
                    .catch(err => console.log(err));
                break;
            case 'getById':
                storage.getById(result.id)
                    .then(data => console.log(data))
                    .catch(err => console.log(err));
                break;
            case 'update':
                if(result.id){
                    storage.update(result.id ,result.name , result.author , result.length, new Date().toISOString())
                        .then(res => console.log("res\n\n" + res))
                        .catch(err => console.log('err\n\n' + err));
                }
                break;
            case 'remove':
                if(result.id){
                    storage.remove(result.id)
                        .then(res => console.log("res\n\n" + res))
                        .catch(err => console.log('err\n\n' + err));
                }
                break;
            default:
                console.log('unknown function \n better luck next time');


        }

        askQuestion();
    });
};

askQuestion();


// function processInput(buffer) {
//     let inputString = buffer.toString().trim();
//     console.log(`You've entered: '${inputString}'`);
//     if (inputString) {
//         // @todo process input
//         eval(inputString)
//             .then( data => console.log(data))
//             .catch(err => console.log(err));
//         askQuestion();  // ask the question again
//     } else {
//         // exit
//         console.log(`Exit.`);
//
//     }
// }



//
// Get two properties from the user: username and email
//
// prompt.get(['username', 'email'], function (err, result) {
//     //
//     // Log the results.
//     //
//     console.log('Command-line input received:');
//     console.log('  username: ' + result.username);
//     console.log('  email: ' + result.email);
// });

// storage.create('Sorry', 'Nothing but Thieves', 220, 3, new Date().toISOString())
//     .then(res => console.log("res\n\n" + res))
//     .catch(err => console.log('err\n\n' + err));
//
// storage.getAll()
//     .then( data => console.log(data))
//     .catch(err => console.log(err));
//
// storage.getById(3)
//     .then( data => console.log(data))
//     .catch(err => console.log(err));
//
//
//
//
//
//
// storage.update('Sorry', 'NbT', 456, 3, new Date().toISOString())
//     .then( data => console.log(data))
//     .catch(err => console.log(err));



