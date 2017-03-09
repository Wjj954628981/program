create table team(
	t_name char(10),
	colors char(10),
	p_count numeric(3,0),
	c_count numeric(3,0),
	primary key(t_name));

create table player(
	p_name char(10),
	p_age numeric(2,0),
	t_name char(10),
	primary key(p_name),
	foreign key(t_name)references team);

create table coach(
	c_name char(10),
	c_age numeric(2,0),
	t_name char(10),
	primary key(c_name),
	foreign key(t_name)references team);

create table game(
	host char(10),
	vistor char(10),
	number numeric(3,0),
	g_count numeric(2,0),
	date date,
	score char(10),
	time numeric(4,0),
	primary key(number),
	foreign key(host)references team,
	foreign key(vistor)references team);

create table stadium(
	s_name char(10),
	size numeric(10,0),
	location char(20),
	primary key(s_name));

create table practice(
	t_name char(10),
	s_name char(10),
	date date,
	primary key(t_name,s_name),
	foreign key(t_name)references team,
	foreign key(s_name)references stadium);
