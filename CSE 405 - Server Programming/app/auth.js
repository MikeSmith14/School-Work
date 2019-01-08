/*
This module exports an Express Router that manages sessions
and login/logout. Requests from non-logged-in users are
redirected to the login page.

This module relies on _username_ being in the session object
to indicate the state of being logged in.

This module places a reference to the session object in
the request object `req`.
*/

const express     = require('express');
const sessions    = require('./sessions.js');
const db          = require('./db.js');

const urlencodedParser = express.urlencoded({ extended: false });
var check = false;
const router = express.Router();

module.exports = router;

router.use(function(req, res, next) {
  sessions.filter(req,res);
  next();
});

router.post('/login', urlencodedParser, function(req, res) {
  let username = req.body['username'];
    let password = req.body['password'];
  db.getUser(username, password, (user) => {
      if (user === null) {
          res.redirect('/loginError.html');
    } else {
      req.session.username = username;
      res.redirect('/');
    }
  });
});

router.post('/logout', function(req, res) {
  delete req.session.username;
  res.redirect('/login.html');
});

router.use(function(req, res, next) {
  if (req.session.hasOwnProperty('username')) {
    next();
  } else {
    res.redirect('/login.html');
  }
});
