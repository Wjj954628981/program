CREATE TABLE purchase_order4(
	ponum	char(8),
	qty	int,
	orderdate	date,
	duedate	date,
	receiveddate	date,
	PRIMARY KEY (ponum));

CREATE TABLE supplier4(
	supplier_id	char(6),
	name	char(20),
	address	char(20),
	PRIMARY KEY (supplier_id));

CREATE TABLE read_by4(
	callnumber char(8),
	lib_id	char(6),
	timesread	int,
	PRIMARY KEY	(callnumber, lib_id),
	FOREIGN KEY  (lib_id) REFERENCES member4(libid),
	FOREIGN KEY  (callnumber) REFERENCES title4(callnumber));

CREATE TABLE order4(
	callnumber	char(8),
	ponum	char(8),
	supplier_id	char(6),
	PRIMARY KEY (callnumber, ponum, supplier_id),
	FOREIGN KEY	(callnumber) REFERENCES title4(callnumber),
	FOREIGN KEY	(ponum) REFERENCES purchase_order4(ponum),
	FOREIGN KEY	(supplier_id) REFERENCES supplier4(supplier_id));

ALTER TABLE title4
ADD CONSTRAINT al_key1 UNIQUE (isbn);
ALTER TABLE title4
ADD CONSTRAINT al_key2 UNIQUE (name);

ALTER TABLE member4
ADD join_date date;
ALTER TABLE member4
ADD gender char(2);

ALTER TABLE read_by4
ADD CONSTRAINT Counter CHECK (timesread >= 0);