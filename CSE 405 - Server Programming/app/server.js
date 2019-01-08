const http = require('http');
const qs = require('querystring');
const express = require('express');
const sessions = require('./sessions.js');
const db = require('./db.js');
const auth = require('./auth.js');
const engine = require('./engine.js');

const port = 8000;

const app = express();
const static = express.static('views');
const urlencodedParser = express.urlencoded({ extended: false });

app.use(static);
app.use(auth);

app.engine('html', engine);
app.set('views', './views');

//Upon accessing the home page the app checks for the users color, message
//and if the current user is an admin. If it is admin, then make it visible
app.get('/', function (req, res) {
    const username = req.session.username;
    var params = { color: '', message: '', isadmin: '' };
    db.getUserColor(username, (color, isadmin) => {
        params.color = color;
        if (isadmin == 1)
            params.isadmin = 'visible'
        else
            params.isadmin = 'hidden';
        db.getUserPara(username, (message) => {
            params.message = message;
            res.render('home.html', { params: params });
        });
    });
});

app.post('/color', urlencodedParser, (req, res) => {
    const username = req.session.username;
    const color = req.body.color;
    db.setUserColor(username, color, () => {
        res.redirect('/');
    });
});

app.get('/color.html', function (req, res) {
    let username = req.session.username;
    db.getUserColor(username, (color) => {
        const params = { color: color, red: '', green: '', blue: '' };
        if (color === 'FF0000') {
            params.red = 'checked';
        } else if (color === '00FF00') {
            params.green = 'checked';
        } else {
            params.blue = 'checked';
        }
        res.render('color.html', { params: params });
    });
});

app.post('/msg', urlencodedParser, (req, res) => {
    const username = req.session.username;
    const message = req.body.message_box;
    db.setUserPara(username, message, () => {
        res.redirect('/');
    });
});

app.post('/home', urlencodedParser, function (req, res) {
    res.redirect('/');
});

//---------ADMIN FUNCTIONS--------------//

//This function allows admins to access the admin menu, has a
//secruity check to make sure the user is admin. If not it bounces back
//to the home page.
app.post('/adminmenu', urlencodedParser, (req, res) => {
    const username = req.session.username;
    var params = { color: '', message: '', isadmin: '' };
    db.getUserColor(username, (color, isadmin) => {
        if (isadmin == '0') {       //this keeps none admins from hitting page...
            res.redirect('/')
        } else {
            res.render('menu.html', { params: params });
        }
    });
});

//Upon request in the admin menu, it will send the required parameters
//for the function to list the users
app.post('/list', urlencodedParser, (req, res) => {
    const username = req.session.username;
    var params = { color: '', message: '', isadmin: '' };
    db.getUserList((userlist) => {
        params.userlist = userlist;
        res.render('list.html', { params: params });
    });
});

//Upon request in the admin menu, it will send the required parameters
//for the function delete users
app.post('/deleteuser', urlencodedParser, (req, res) => {
    const username_delete = req.body.username_box;
    var params = { message: '' };
    if (typeof username_delete != 'undefined') {  //This catches 1st landing on page.
        db.deleteUser(username_delete, (message) => {
            params.message = message;
            res.render('deleteUser.html', { params: params });
        });
    } else {
        res.render('deleteUser.html', { params: params });
    }
});

//Upon request in the admin menu, it will send the required parameters
//for the function to change a specified users password
app.post('/changePw', urlencodedParser, (req, res) => {
    const username = req.body.username_box;
    const password = req.body.password_box;
    var params = { message: '' };
    if (typeof username != 'undefined') {  //This catches 1st landing on page.
        db.changePassword(username, password, (message) => {
            params.message = message;
            res.render('changepass.html', { params: params });
        });
    } else {
        res.render('changepass.html', { params: params });
    }
});

//Upon request in the admin menu, it will send the required parameters
//for the function to add a user
app.post('/adduser', urlencodedParser, (req, res) => {
    const username = req.body.username_box;
    const password = req.body.password_box;
    const color = req.body.color_box;
    const message = req.body.msg_box;
    const admin = req.body.admin_box;
    var params = { username: '', password: '', color: '', message: '', admin: '',dbmessage:'' };
    if (typeof username != 'undefined') {  //This catches 1st landing on page.
        db.addUser(username, password, color, message, admin, (dbmessage) => {
            params.username = username;
            params.password = password;
            params.color = color;
            params.message = message;
            params.admin = admin;
            params.dbmessage = dbmessage;
            res.render('addUser.html', { params: params });
        });
    } else {
        res.render('addUser.html', { params: params });
    }
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}/`);
});
