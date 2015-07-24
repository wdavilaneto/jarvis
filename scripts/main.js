/* jslint node: true */
(function () {
    "use strict";

    // Proxy Definition
    var globalTunnel = require('global-tunnel');
    globalTunnel.initialize({
        host: '127.0.0.1',
        port: 3128,
        sockets: 50 // optional pool size for each http and https
    });

    var tts = require('node-google-text-to-speech');
    var fs = require('fs');
    var Player = require('player');

    var languageLocale = "en";
    var hello_text = "Hello Sir. I am Jarvis.";

    var tts = require('node-google-text-to-speech')

    tts.translate(languageLocale, hello_text, function (result) {
        if (result.success) { //check for success

            fs.writeFile("hello.mp3", result.audio, function(err) {
                if (err) {
                    console.log(err);
                }
                else {
                    console.log("The file was saved!");
                    //var player = new Player("./hello.mp3");
                    //player.play();
                    //player.stop();
                }
            });


        }
    });
    globalTunnel.end();
})();
