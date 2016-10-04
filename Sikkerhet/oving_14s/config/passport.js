const passport = require('passport');
const GoogleStrategy = require('passport-google-oauth').OAuth2Strategy;

passport.serializeUser(function(user, done) {
  done(null, "123456");
});

passport.deserializeUser(function(user, done) {
  done(null, "123456");
});

passport.use(new GoogleStrategy({
        clientID: '812454777427-47jjg72uekfhgdpq34s5mrdcbequqeie.apps.googleusercontent.com',//process.env.GOOGLE_CLIENT_ID,
        clientSecret: 'DREohO7If_fWA2annUMVY2GD',//process.env.GOOGLE_CLIENT_SECRET,
        callbackURL:  '/auth/google/callback'
    },
    function(accessToken, refreshToken, profile, done) {
      console.log("ACCESSTOKEN: ");
      console.log(accessToken);
      console.log("REFRESHTOKEN: ");
      console.log(refreshToken);
      console.log("GOOGLE-PROFILE: ");
      console.log(profile);
      console.log("VERIFIED: ");
      console.log(done);
        process.nextTick(function () {
            return done(null, profile);
        });
    }
));
//GOOGLE_ID=812454777427-47jjg72uekfhgdpq34s5mrdcbequqeie.apps.googleusercontent.com
//GOOGLE_SECRET=DREohO7If_fWA2annUMVY2GD
