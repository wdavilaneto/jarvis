/* jslint node: true */
(function () {
    "use strict";
    //var text = "Hello Sir. I am Jarvis.";
    var text = "Rafaela, I'm the program your husband is making";

    //process.env.http_proxy = 'http://127.0.0.1:3128';

    var say = require('say');
    var translate = require('translate');

    // output some text to the console as the callback
    //say.speak('Alex', text, function () {
    //    console.log('text to speech complete');
    //});

    translate.text('pt', text, function(result){
        say.speak('Alex', result);
    });

})();