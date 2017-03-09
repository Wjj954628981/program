create table person(
	driver_id numeric(18,0),
	name char(10),
	address char(50),
	primary key(driver_id));
create table car(
	license numeric(5,0),
	model char(30),
	year numeric(2,1),
	primary key(license));
create table accident(
	report_number numeric(8,0),
	date date,
	location char(50),
	primary key(report_number));
create table owns(
	driver_id numeric(18,0),
	license numeric(5,0),
	primary key(driver_id,license),
	foreign key(driver_id)references person,
	foreign key(license)references car);
create table participated(
	driver_id numeric(18,0),
	license numeric(5,0),
	report_number numeric(8,0),
	damage_amount numeric(7,0),
	primary key(driver_id,license,report_number),
	foreign key(driver_id)references person,
	foreign key(license)references car,
	foreign key(report_number)references accident);