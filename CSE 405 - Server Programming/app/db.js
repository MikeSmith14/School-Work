const pg = require('pg');

process.env.PGDATABASE = 'express';

const pool = new pg.Pool();
pool.on('error', (err, client) => {
    console.log(err.stack);
    process.exit(-1);
});

/*
The _getUser_ function takes a username, password and a callback.
If the function can not find a user with the given username and
password, then it returns null, otherwise it returns an object
containing the user data.
*/ //Modified to allow passing of the 'isadmin' value
function getUser(username, password, cb) {
    pool.connect((err, client, done) => {
        if (err) throw err;
        const q = "select color,isadmin from users " +
            "where username=$1::text and password=$2::text";
        const params = [username, password];
        client.query(q, params, (err, result) => {
            if (err) {
                console.log(err.stack);
                cb(null);
            } else if (result.rows.length === 0) {
                cb(null);
            } else {
                let row = result.rows[0];
                cb({
                    color: row['color'],
                    isadmin: row['isadmin']
                });
            }
            done();
        });
    });
}

//Hijacked this function to also pass the value for the user's
//'isadmin'
function getUserColor(username, cb) {
    pool.connect((err, client, done) => {
        if (err) throw err;
        const q = "select color,isadmin from users where username=$1::text";
        const params = [username];
        client.query(q, params, (err, result) => {
            if (err) {
                console.log(err.stack);
                cb(null);
            } else if (result.rows.length === 0) {
                cb(null);
            } else {
                let row = result.rows[0];
                cb(row['color'], row['isadmin']);
            }
            done();
        });
    });
}

function setUserColor(username, color, cb) {
    pool.connect((err, client, done) => {
        if (err) throw err;
        const q = "update users set color=$1::text where username=$2::text";
        const params = [color, username];
        client.query(q, params, (err, result) => {
            if (err) {
                console.log(err.stack);
            }
            done();
            cb();
        });
    });
}

function getUserPara(username, cb) {
    pool.connect((err, client, done) => {
        if (err) throw err;
        const q = "select msg from users where username=$1::text";
        const params = [username];
        client.query(q, params, (err, result) => {
            if (err) {
                console.log("Error in getUserPara\n");
                console.log(err.stack);
                cb(null);
            } else if (result.rows.length == 0) {
                cb(null);
            } else {
                const row = result.rows[0];
                cb(row['msg']);
            }
            done();
        });
    });
}

function setUserPara(username, msg, cb) {
    pool.connect((err, client, done) => {
        if (err) throw err;
        const q = "update users set msg=$1::text where username=$2::text";
        const param = [msg, username];
        client.query(q, param, (err, result) => {
            if (err) {
                console.log(err.stack);
            }
            done();
            cb();
        });
    });
}

//----------ADMIN FUNCTIONS--------------//

//allows an admin user to change the password of an entered users
//error checking for accessing database, displays on the page if
//the password was changed successfully, or displays that the users
//doesnt exist in the database
function changePassword(username, password, cb) {
    pool.connect((err, client, done) => {
        if (err) throw err;
        const q = "update users set password=$1::text where username=$2::text";
        const param = [password, username];
        client.query(q, param, (err, result) => {
            if (err) {
                console.log(err.stack);
                cb("DB error");
            } else if (result.rowCount === 0) {   //rowCount passes if the row was modified
                cb("Not a real user");
            } else if (result.rowCount === 1) {
                cb("Successfully changed password");
            }
            //cb();
            done();
        });
    });
}

//Uses a for loop to loop through all the users in the database. Returns null
//if the user list is empty
function getUserList(cb) {
    pool.connect((err, client, done) => {
        if (err) throw err;
        const q = "select username from users";
        client.query(q, "", (err, result) => {
            if (err) {
                console.log("Error in getUserList\n");
                console.log(err.stack);
                cb(null);
            } else if (result.rows.length == 0) {
                cb(null);
            } else {
                var aresult = "";
                for (var i = 0; i < result.rows.length; i++) {
                    var row = result.rows[i];
                    aresult += row["username"] + "<br>";
                }
                cb(aresult);
            }
            done();
        });
    });
}

//Allows the admins to delete any user, except the "superuser" 'admin'. To
//prevent loss of control. This function allows displays on the page if
//the function was successful, or if the user does not exist
function deleteUser(username_delete, cb) {
    if (username_delete == 'admin') {
        cb('You are not allowed to delete the"admin" ID!');
        return;
    }
    pool.connect((err, client, done) => {
        if (err) throw err;
        const q = "delete from users where username=$1::text";
        const param = [username_delete];
        client.query(q, param, (err, result) => {
            if (err) {
                console.log(err.stack);
                cb("DB Error");
            } else if (result.rowCount === 0) {
                cb("Not a real user");
            } else if (result.rowCount === 1) {
                cb("Successfully deleted user");
            }
            done();
        });
    });
}

//This function allows the admins to add a new user. It has a check to
//verify that each section is filled in. And displays on the page if the
//user was added correctly.
function addUser(username, password, color, message, admin, cb) {
    if ((username == "") || (password=="") || (color == "") || ( message == "" ) || (admin == "" )){
        cb("All Fields are Required!");
        return;
    }
    pool.connect((err, client, done) => {
        if (err) throw err;
        const q = "insert into users (username, password, color, msg, isadmin ) values ($1,$2,$3,$4,$5)";
        const param = [username, password, color, message, admin];
        client.query(q, param, (err, result) => {
            if (err) {
                console.log(err.stack);
                cb("DB Error");
            }
            cb("Successfully Added User");
            done();
        });
    });
};

exports.getUser = getUser;
exports.getUserColor = getUserColor;
exports.setUserColor = setUserColor;
exports.getUserPara = getUserPara;
exports.setUserPara = setUserPara;
exports.getUserList = getUserList;
exports.changePassword = changePassword;
exports.deleteUser = deleteUser;
exports.addUser = addUser;
