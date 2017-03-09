create table Publisher(
	Publisher_name char(20),
	Address char(30),
	primary key(Publisher_name));

create table Customer(
	Customer_name char(20),
/*	first_name char(10),
	middle_initial char(10),
	last_name char(10),*/
	Mailing_address char(50),
	Credit_card_number numeric(20,0),
	expiration_date numeric(5,0),
	Phone_number numeric(11,0),
	Email_address char(50),
	primary key(Customer_name));

create table Title(
	Auther char(20),
	Titile char(30),
	ISBN numeric(11,0),
	Publisher_name char(20),
	Edition char(20),
	Date_of_publication date,
	Customer_name char(20),
	Price numeric(4,0),
	Book_description char(100),
	Categories char(100),
	primary key(ISBN),
	foreign key(Publisher_name) references Publisher);

create table Orders(
	Order_number numeric(20,0),
	Customer_name char(20),
	Mailing_address char(50),
	Credit_card_number numeric(20,0),
	Method_of_shipment char,
	date_and_time datetime,
	ISBN numeric(11,0),
	Price numeric(4,0),
	purchase_price numeric(4,0),
	quantity_ourchased numeric(2,0),
	shipping_cost numeric(2,0),
	tax numeric(2,0),
	primary key(Order_number),
	foreign key(ISBN)references Title,
	foreign key(Customer_name)references Customer);

create table Fulfilled_Order(
	Order_number numeric(20,0),
	Date_of_shipment date,
	Tracking_number numeric(20,0),
	date_of_Expected_Delivery date,
	ISBN numeric(11,0),
	quantity_ourchased numeric(2,0),
	primary key(Order_number),
	foreign key(Order_number)references Orders,
	foreign key(ISBN)references Title);