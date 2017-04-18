angular.module('starter.services', [])
.factory('Chats', function() {  
  // Might use a resource here that returns a JSON array
  // var mysql = require('mysql');
  // var connection = mysql.createConnection({
  //   dialect:'mysql',
  //   host:'localhost',
  //   username:'root',
  //   password:'1996wangjiajie.',
  //   database:'test',
  //   port:'3306'
  // });
  // connection.connect();
  // var chatsMysql = 'select * from chats';
  //var chats;
  // connection.query(chatsMysql,function(err, chats){
  //   if(err){
  //     console.log('[select error] -', err.message);
  //     return;
  //   }
  //   console.log(chats);
  // });
  // Some fake testing data
  var chats = [{
    id: 0,
    name: 'Ben Sparrow',
    lastText: 'You on your way?',
    face: 'img/ben.png'
  }, {
    id: 1,
    name: 'Max Lynx',
    lastText: 'Hey, it\'s me',
    face: 'img/max.png'
  }, {
    id: 2,
    name: 'Adam Bradleyson',
    lastText: 'I should buy a boat',
    face: 'img/adam.jpg'
  }, {
    id: 3,
    name: 'Perry Governor',
    lastText: 'Look at my mukluks!',
    face: 'img/perry.png'
  }, {
    id: 4,
    name: 'Mike Harrington',
    lastText: 'This is wicked good ice cream.',
    face: 'img/mike.png'
  }];

  return {
    all: function() {
      return chats;
    },
    remove: function(chat) {
      chats.splice(chats.indexOf(chat), 1);
    },
    get: function(chatId) {
      for (var i = 0; i < chats.length; i++) {
        if (chats[i].id === parseInt(chatId)) {
          return chats[i];
        }
      }
      return null;
    }
  };
});
