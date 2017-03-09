insert into person values('140203199611240030','Tom','Shanxi-First Avenue');
insert into person values('140203199611243247','Marry','Tianjin-Second Avenue');
insert into person values('140203199611243758','Jack','Shanghai-Third Avenue');
insert into person values('140203199611153578','Nancy','Guangzhou-Fourth Avenue');
insert into person values('140203199709117325','Janet','Beijing-Fifth Avenue');

insert into car values('10000','Buick','2.5');
insert into car values('10001','Ford','3');
insert into car values('10002','TOYOTA','1.5');
insert into car values('10003','Chevrolet','1');
insert into car values('10004','Volkswagen','5');
insert into car values('10005','HONDA','4');
insert into car values('10006','KIA','4.5');

insert into accident values('10000000','2006-11-12','Shanxi');
insert into accident values('10000001','2007-06-02','Beijing');
insert into accident values('10000002','2011-01-30','Shanghai');
insert into accident values('10000003','2011-11-22','Chengdu');

insert into owns values('140203199611240030','10000');
insert into owns values('140203199611240030','10005');
insert into owns values('140203199611243247','10001');
insert into owns values('140203199611243758','10002');
insert into owns values('140203199611153578','10003');
insert into owns values('140203199611153578','10006');
insert into owns values('140203199709117325','10004');

insert into participated values('140203199611240030','10000','10000000','20000');
insert into participated values('140203199611240030','10005','10000001','15000');
insert into participated values('140203199611243247','10001','10000003','5000');
insert into participated values('140203199611243758','10002','10000001','15000');
insert into participated values('140203199611153578','10003','10000002','25000');
insert into participated values('140203199709117325','10004','10000002','25000');