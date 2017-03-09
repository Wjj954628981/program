DROP TABLE author4 ;
DROP TABLE hold4 ;
DROP TABLE TITLE4 ;
DROP TABLE MEMBER4 ;
DROP TABLE BOOK4;

CREATE TABLE TITLE4
 (callnumber  char(8) NOT NULL,
  isbn        char(8),
  year        datetime,
  name        char(14),
  authorfname char(14),
  authorlname char(14),
  PRIMARY KEY (callnumber)
);

CREATE TABLE MEMBER4
 (libid       char(6) NOT NULL,
  fname       char(14),
  lname       char(14),
  address     char(20),
  phonenumber char(10),
  PRIMARY KEY (libid)
);

CREATE TABLE BOOK4
 (book_id       char(8) NOT NULL,
  edition       char(10),
  status        char(5),
  borrowerid    char(6),
  borrowduedate datetime,
  callnumber    char(8),
  PRIMARY KEY (book_id)
);

INSERT INTO TITLE4 VALUES  ('AB123456', '12345687', '1997/01/01', 'Discrete Maths', 'Shadow', 'Jones');
INSERT INTO TITLE4 VALUES  ('CD456756', '45454598', '1996/01/01', 'Intro to CS', 'Kelvin', 'Smith');
INSERT INTO TITLE4 VALUES  ('EF121221', 'A4245678', '1998/01/01', 'Intro to CE', 'Stella', 'Potter');


INSERT INTO MEMBER4 VALUES  ('123423', 'Jessy', 'Owens', '35 Side Pgh 15255', '4126874534');
INSERT INTO MEMBER4 VALUES  ('A34565', 'Diana', 'Emily', '25 Side Pgh 15245', '4123456452');

INSERT INTO BOOK4 VALUES  ('Q76.98.1', 'first', 'good', 'A34565', '1997-10-10', 'AB123456');
INSERT INTO BOOK4 VALUES  ('Q76.95.6', 'third', 'ok', '123423', '1998-06-06', 'EF121221');



