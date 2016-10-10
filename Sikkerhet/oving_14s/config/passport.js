const passport = require('passport');
const GoogleStrategy = require('passport-google-oauth').OAuth2Strategy;

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
/*
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
*/
//GOOGLE_ID=812454777427-47jjg72uekfhgdpq34s5mrdcbequqeie.apps.googleusercontent.com
//GOOGLE_SECRET=DREohO7If_fWA2annUMVY2GD
//https://accounts.google.com/ServiceLogin?passive=1209600&continue=https://accounts.google.com/o/oauth2/v2/auth?access_type%3Doffline%26approval_prompt%3Dforce%26scope%3Dhttps://www.googleapis.com/auth/userinfo.profile%2Bhttps://www.googleapis.com/auth/userinfo.email%26response_type%3Dcode%26redirect_uri%3Dhttp://localhost:3000/auth/google/callback%26client_id%3D812454777427-47jjg72uekfhgdpq34s5mrdcbequqeie.apps.googleusercontent.com%26from_login%3D1%26as%3D41096fb7246f6b74&oauth=1&sarp=1&scc=1
