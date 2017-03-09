create table employees
 (person_name varchar(10),
 street varchar(30),
 city varchar(10),
 primary key(person_name));
create table company
 (company_name varchar(50),
 city varchar(10),
 primary key(company_name));
create table works
 (person_name varchar(10),
 company_name varchar(50),
 salary numeric(12,2),
 primary key(person_name,company_name),
 foreign key(person_name)references employees,
 foreign key(company_name)references company);
create table manages
 (person_name varchar(10),
 manager_name varchar(10),
 primary key(person_name,manager_name),
 foreign key(person_name)references employees);