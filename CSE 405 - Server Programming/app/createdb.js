const pg = require('pg');

process.env.PGDATABASE = 'express';

const pool = new pg.Pool();

pool.on('error', (err, client) => {
	console.log(err.stack);
	process.exit(-1);
});

pool.connect((err, client, done) => {
	if (err) throw err;
	client.query('DROP TABLE IF EXISTS users', (err)=>{
		if (err) throw err;
	});
	//created a 5th field for each row "isadmin" 1 for admin, 0 for not
	const q = 'create table users (           ' +
            '  username varchar(225) primary key, ' +
            '  password varchar(225) not null,    ' +
            '  color char(6),                     ' +
            '  msg text,                          ' +
            '  isadmin int                        ' +
            ')                                    ' ;
  client.query(q, (err) => {
    if (err) throw err;
    insertUser(client, done);
  });
});

function insertUser(client, done) {
	const q = "Insert into users values ('fred', '1234', '0000FF', 'Enter text here.','0')";
	client.query(q, (err) => {
		if (err) throw err;
    });
//Added the second user manually in the database.
  const q1 = "Insert into users values ('admin', '1234', '0000FF', 'Enter text here.','1')";
  client.query(q1, (err) => {
    if (err) throw err;
    done();
    pool.end();
    });
}
