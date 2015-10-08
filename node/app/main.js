/* jslint node: true */
(function() {
  "use strict";
  var text = "Hello Sir. I am Jarvis.";

  process.env.http_proxy = 'http://127.0.0.1:3128';

  var LightTTS = require('say.js');
  LightTTS.set_opts({api_name : 'google', lang : 'en'});

  // GoogleTTS.convert(text , 'hello');
  LightTTS.say(text);
  
  var stuff =  {
    name:"walter",age:32
  };


})();
