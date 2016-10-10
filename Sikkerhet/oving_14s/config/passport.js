const passport = require('passport');
const GoogleStrategy = require('passport-google-oauth').OAuth2Strategy;
const TwitterStrategy = require('passport-twitter').Strategy;

passport.serializeUser(function(user, done) {
  done(null, "123456");
});

passport.deserializeUser(function(user, done) {
  done(null, "123456");
});

passport.use(new GoogleStrategy({
      clientID: '812454777427-47jjg72uekfhgdpq34s5mrdcbequqeie.apps.googleusercontent.com',
      clientSecret: 'DREohO7If_fWA2annUMVY2GD',
      callbackURL: '/auth/google/callback',
      scope: ['profile', 'email']
    },
    function(accessToken, refreshToken, params, profile, done) {
      console.log('accessToken', accessToken);
      console.log('params', params);

    //  console.log('profile', profile);
      process.nextTick(function () {
          return done(null, profile);
      });
   }
));


passport.use(new TwitterStrategy({
    consumerKey: "uMw3QE5BZBsIIvYwf7CVwHx7N",
    consumerSecret: "b8Cfu50qi1Boe9opTByhGoRYLY8UJoc78YWcQlBusevoVb9Psk",
    callbackURL: "http://localhost:3000/"
  },
  function(token, tokenSecret, profile, cb) {
    console.log('accessToken', token);
    console.log('cb', cb);
    console.log('profile', profile);
    process.nextTick(function () {
        return done(null, profile);
    });    /*User.findOrCreate({ twitterId: profile.id }, function (err, user) {
      return cb(err, user);
    });*/
  }
));
