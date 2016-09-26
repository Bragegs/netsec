//var ProgressBar = require('progressbar.js');

var circle;

window.onload = function onLoad() {
  circle = new ProgressBar.Circle('#progress', {
      color: '#555',
      trailColor: '#eee',
      strokeWidth: 20,
      duration: 2500,
      easing: 'easeInOut'
  });
  document.getElementById("progress").style.display = "none";
};

function handleLogin(){
  document.getElementById("submitButton").style.display = "none";
  document.getElementById("progress").style.display = "";

  circle.animate(0.15, {duration: 1},null);

  var username = document.getElementById("username").value;
  var password = document.getElementById("password").value;

  //Since this is one-threaded -> sets timeout for circle-animation to begin before PBKDF2
  setTimeout(function() {
    var salt="oving12_salt_"+username;
    var options={keySize: 512/32, iterations: 1024};
    client_hash=CryptoJS.PBKDF2(password, salt, options);

    $.post('login' , { username: username, client_hash: client_hash.toString(CryptoJS.enc.hex), token: window.localStorage.accessToken},
    function(returnedData){
        animateCircle("#4F8A10");
        var token = returnedData.token
        if (!(token === undefined) && !(token === null)) {
          // To delete localStorage in chrome -> chrome://settings/cookies#cont
          window.localStorage.accessToken = returnedData.token;
        }
        console.log(returnedData);
    }).fail(function(error){
      console.log(error.responseText);
        animateCircle("#D8000C");
    });
  }, 50);
}

function animateCircle(toColor){
  circle.animate(1.0, {
      duration: 1200,
      easing: 'easeInOut',
      from: { color: '#eee' },
      to: { color: toColor },
      step: function(state, circle, attachment) {
        circle.path.setAttribute('stroke', state.color);
      }
  }, function() {
    setTimeout(function() {
      circle.animate(0.0, {duration: 300, easing: 'easeInOut'}, function(){
        document.getElementById("progress").style.display = "none";
        document.getElementById("submitButton").style.display = "";
      });
    }, 1000);
  });
}
