create table inventory(
	item numeric(3,0),
	level numeric(5,0)
	primary key(item));
create table minlevel(
	item numeric(3,0),
	level numeric(5,0)
	primary key(item,level),
	foreign key(item)references inventory);
create table reorder(
	item numeric(3,0),
	amount numeric(5,0),
	primary key(item,amount),
	foreign key(item)references inventory);
create table orders(
	item numeric(3,0),
	amount numeric(5,0),
	primary key(item,amount),
	foreign key(item)references inventory);