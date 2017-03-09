create table Persons
(id              varchar(18),
name             varchar(20),
gender           char,
primary key (id),
check(gender in('man','woman')));

create table Users
(id              varchar(18),
psw              varchar(25) not null,
e_mail           varchar(25) not null,
primary key (id),
foreign key (id) references Persons,
unique (e_mail));

create table Supadmin
(id              varchar(18),
primary key (id),
foreign key (id) references Users);

create table Departments
(dept_id         varchar(7),
dept_name        varchar(20),
primary key (dept_id));

create table Admins
(id              varchar(18),
dept_id          varchar(7),
primary key (id),
foreign key (id) references Users,
foreign key (dept_id) references Departments);

create table Ordusers
(id              varchar(18),
primary key (id),
foreign key (id) references Users)

create table Hotels
(h_name       varchar(15),
h_address     varchar(30) not null,
phone_number  varchar(12),
primary key (h_name));

create table Meetings
(m_id         varchar(8),
m_name        varchar(20) not null,
pre_num       int,
max_num       int,
theme         varchar(30),
begin_date    date not null,
begin_time    time not null,
end_date      date,
end_time      time,
m_city        varchar(15) not null,
m_address     varchar(30) not null,
h_name		  varchar(15),
primary key (m_id),
foreign key (h_name) references Hotels);

create table P_attend_m
(users_id     varchar(18),
m_id          varchar(8),
arrive_date   date,
arrive_way    varchar(6),
leave_date    date,
leave_way     varchar(6),
room_number   varchar(5),
primary key (users_id,m_id),
foreign key (users_id) references Users,
foreign key (m_id) references Meetings)

create table acompany_retinue
(users_id     varchar(18),
m_id          varchar(8),
re_id         varchar(18),
roomnumber    varchar(5) not null,
primary key (users_id,m_id,re_id),
foreign key (users_id,m_id) references P_attend_m,
foreign key (re_id) references Persons);