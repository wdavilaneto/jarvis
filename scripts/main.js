/* jslint node: true */
(function () {
    "use strict";
    process.env.http_proxy = 'http://127.0.0.1:3128';

    var text = "Hello Sir. I am Jarvis.";
    var GoogleTTS = require('google-tts');
    //GoogleTTS.convert(text , 'hello');
    GoogleTTS.play(text);

})();
