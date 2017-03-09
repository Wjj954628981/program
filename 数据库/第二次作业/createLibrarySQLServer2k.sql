DROP TABLE Author ;
DROP TABLE Book ;
DROP TABLE HOLD ;
DROP TABLE Dependent ;
DROP TABLE Title ;
DROP TABLE Member ;
DROP TABLE Section ;
DROP TABLE Librarian ;

CREATE TABLE Title(
CallNumber VARCHAR(40) NOT NULL,
Name VARCHAR(200),
ISBN VARCHAR(40),
Year DATETIME,
Publisher VARCHAR(80),
PRIMARY KEY (CallNumber),
UNIQUE (ISBN));

CREATE TABLE Author(
CallNumber VARCHAR(40) NOT NULL,
Fname VARCHAR(40) NOT NULL,
MI VARCHAR(10),
Lname VARCHAR(40) NOT NULL,
PRIMARY KEY (CallNumber, Fname, Lname),
FOREIGN KEY (CallNumber) REFERENCES Title(CallNumber));

CREATE TABLE Member(
MemNo NUMERIC(20) NOT NULL,
DriverLicState VARCHAR(20),
DriverLicNo VARCHAR(40),
Fname VARCHAR(20),
MI VARCHAR(10),
Lname VARCHAR(20),
Address VARCHAR(250),
PhoneNumber VARCHAR(15),
PRIMARY KEY (MemNo));

CREATE TABLE HOLD(
MemNo NUMERIC(20) NOT NULL,
CallNumber VARCHAR(40) NOT NULL,
HoldDatetime DATETIME,
PRIMARY KEY (MemNo, CallNumber),
FOREIGN KEY (MemNo) REFERENCES Member(MemNo),
FOREIGN KEY (CallNumber) REFERENCES Title(CallNumber));

CREATE TABLE Librarian(
SSN NUMERIC(20) NOT NULL,
Name VARCHAR(80),
Address VARCHAR(250),
Salary NUMERIC(9,2),
Gender CHAR(1),
Birthday DATETIME,
SuperSSN NUMERIC(20),
Section NUMERIC(20),
PRIMARY KEY (SSN),
FOREIGN KEY (SuperSSN) REFERENCES LIBRARIAN(SSN));


CREATE TABLE Section(
SectNo NUMERIC(20) NOT NULL,
Name VARCHAR(80),
HeadSSN NUMERIC(20),
PRIMARY KEY (SectNo),
FOREIGN KEY (HeadSSN) REFERENCES Librarian(SSN));

CREATE TABLE Dependent(
LibSSN NUMERIC(20) NOT NULL,
Name VARCHAR(40) NOT NULL,
Birthday DATETIME,
Kinship VARCHAR(40),
PRIMARY KEY (LibSSN, Name),
FOREIGN KEY (LibSSN) REFERENCES Librarian(SSN));

CREATE TABLE Book(
Book_ID NUMERIC(20) NOT NULL,
Edition VARCHAR(80),
BorrowerMemNo NUMERIC(20),
BorrowDueDatetime DATETIME,
CallNumber VARCHAR(40),
LibCheck NUMERIC(20),
PRIMARY KEY (Book_ID),
FOREIGN KEY (CallNumber) REFERENCES Title(CallNumber),
FOREIGN KEY (BorrowerMemNo) REFERENCES Member(MemNo),
FOREIGN KEY (LibCheck) REFERENCES Librarian(SSN));

INSERT INTO Title VALUES ('Call123', 'Iliad', 'ISBN123', '1997/01/01', 'Homer Publishing');
INSERT INTO Title VALUES ('Call124', 'Odyssey', 'ISBN124', '1997/01/01', 'Homer Publishing');
INSERT INTO Title VALUES ('Call125', 'Database Systems', 'ISBN125', '1999/01/01', 'AWL');
INSERT INTO Title VALUES ('Call126', 'Financial Accounting', 'ISBN126', '1997/01/01', 'McGrawHill');
INSERT INTO Title VALUES ('Call127', 'Second World War', 'ISBN127', '1986/05/01', 'McGrawHill');
INSERT INTO Title VALUES ('Call128', 'Networks', 'ISBN128', '1986/05/01', 'AWL');
INSERT INTO Title VALUES ('Call129', 'Pitt Roads', 'ISBN129', '1986/05/01', 'AWL');

INSERT INTO Member VALUES (123, 'PA', '123', 'John', '', 'Summers', '4615 Forbes Ave, Pittsburgh, PA 15213', '412-268-0001');
INSERT INTO Member VALUES (124, 'GA', '124', 'Jon', '', 'Butterworth', '10 Fifth Ave, Atlanta, GA 30332', '404-894-0001');
INSERT INTO Member VALUES (125, 'PA', '125', 'Susan', 'B', 'Carlione', '4600 Verona Road, Pittsburgh, PA 15217', '412-200-0001');
INSERT INTO Member VALUES (126, 'NC', '126', 'Mohammed', '', 'Ismail', '250 Peachtree Street, Salem, NC 15213', '421-268-0001');
INSERT INTO Member VALUES (127, 'PA', '127', 'Asterio', '', 'Tanaka', '415 Craig Street, Pittsburgh, PA 15213', '412-220-0001');

INSERT INTO Author VALUES ('Call123', 'Hello', '', 'Homer');
INSERT INTO Author VALUES ('Call124', 'Hello', '', 'Homer');
INSERT INTO Author VALUES ('Call125', 'Jack', '', 'Collins');
INSERT INTO Author VALUES ('Call126', 'Jack', '', 'Collins');
INSERT INTO Author VALUES ('Call127', 'Winston', '', 'Churchill');
INSERT INTO Author VALUES ('Call127', 'John', '', 'Keegan');
INSERT INTO Author VALUES ('Call128', 'Jeff', '', 'Tanenbaum');
INSERT INTO Author VALUES ('Call129', 'Carlos', '', 'Tanaka');

INSERT INTO HOLD VALUES (123, 'Call123', '2000-10-10');


INSERT INTO Librarian VALUES (201, 'Ashoka Savasere', '4615 Forbes Ave, Pittsburgh, PA 15213', 40000, 'F', '1972-06-02', NULL, 1);
INSERT INTO Librarian VALUES (202, 'Alfred Watkins', '4615 Forbes Ave, Pittsburgh, PA 15213', 40000, 'M', '1972-07-02', NULL, 1);
INSERT INTO Librarian VALUES (203, 'Yong-Chul Oh', '4600 Forbes Ave, Pittsburgh, PA 15213', 40000, 'M', '1960-06-02', NULL, 1);
INSERT INTO Librarian VALUES (204, 'Shamkant Navathe', '4615 Forbes Ave, Pittsburgh, PA 15213', 40000, 'M', '1975-06-02', NULL, 2);

INSERT INTO Book VALUES (123, '1', 123, '2000-12-12', 'Call123', 202);
INSERT INTO Book VALUES (223, '1', 125, '2000-11-11', 'Call123', 201);
INSERT INTO Book VALUES (124, '1', 124, '2000-06-09', 'Call124', 201);
INSERT INTO Book VALUES (224, '1', 125, '2000-11-11', 'Call124', 201);
INSERT INTO Book VALUES (125, '1', 125, '2000-11-11', 'Call125', 201);
INSERT INTO Book VALUES (225, '1', NULL, NULL, 'Call125', NULL);
INSERT INTO Book VALUES (126, '1', 125, '2000-11-11', 'Call126', 201);
INSERT INTO Book VALUES (226, '1', 124, '2000-06-09', 'Call126', 202);
INSERT INTO Book VALUES (326, '1', 124, '2000-06-09', 'Call126', 202);
INSERT INTO Book VALUES (127, '1', NULl, NULL, 'Call127', NULL);
INSERT INTO Book VALUES (128, '1', 125, '2000-11-11', 'Call128', 201);
INSERT INTO Book VALUES (228, '1', 126, '2000-10-10', 'Call128', 202);
INSERT INTO Book VALUES (129, '1', 123, '2000-12-12', 'Call129', 202);
INSERT INTO Book VALUES (229, '1', 125, '2000-12-12', 'Call129', 202);

INSERT INTO Section VALUES (1, 'CheckOut', 201);
INSERT INTO Section VALUES (2, 'Reference', 204);

ALTER TABLE Librarian
ADD CONSTRAINT LibSection FOREIGN KEY (Section) REFERENCES Section(SectNo);

INSERT INTO Dependent VALUES (203, 'Luc Whang', '1998-11-11', 'Son');
