// Proxy Definition
var globalTunnel = require('global-tunnel');
globalTunnel.initialize({host : '127.0.0.1', port : 3128});

var tts = require('node-tts-api');

var example = "Hello Sir, I'm Jarvis. Loading Modules now...";

tts.getSpeech(example, function(error, link) { return console.log(link); });

globalTunnel.end();