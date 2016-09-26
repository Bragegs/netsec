var express = require('express');
var router = express.Router();
var CryptoJS = require('crypto-js');
var jwt = require('jsonwebtoken');

var users = {
    // salt is a larger (512-bit for instance)
    // secure random number that is created
    // and used before a new hash is stored
    "brage" : {
      //password = 123
      salt: "oving12_salt_brage",
      hash: "5c4997361f8383439ce8704a97c2832b82e03c25bc0002f3ccc49ebf6efdbfd6ac460bafe9eda3b34f703836cf3594c499ce08bc5262bc7cbfbcba461f04d379"
    }
};

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

router.post('/login', function(req, res, next) {
  // check header or url parameters or post parameters for token
  var token = req.body.token || req.query.token || req.headers['x-access-token'];
  // check if token exists
  if (token) {
    // verifies secret and checks expiration
    jwt.verify(token, "token", function(err, decoded) {
      if (err) {
        checkCredentials(req, res);
      } else {
        res.status(200).send("Token authenticated!")
      }
    });
  } else {
    checkCredentials(req, res);
  }
});

function checkCredentials(req, res) {
  var user = users[req.body.username];

  if( typeof user !== 'undefined' && user) {
      if(user.hash===CryptoJS.PBKDF2(req.body.client_hash , user.salt, {keySize: 512/32, iterations: 1024}).toString(CryptoJS.enc.hex)) {
      // User is authenticated
      // Send an access token so that we do not
      // need to do all this again too soon,
      // it is computationally expensive after all
      var token = jwt.sign(user, 'token', {
          expiresIn: 60*60*24 // expires in 24 hours
        });

      res.json({
          success: true,
          message: 'Success! Here is your token',
          token: token
        });

    } else {
      res.status(401).send('Wrong password!');
    }
  } else {
    res.status(401).send('User not found!');
  }
}
module.exports = router;
