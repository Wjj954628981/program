create procedure p1(@year numeric(4,0))
as
select count(driver_id) as person_count
from accident join participated on accident.report_number=participated.report_number
where date='2011-01-30';

create procedure p2(@name char(10))
as
select count(report_number)as caraccident_count
from participated
where participated.driver_id in(select person.driver_id
								from person
								where person.name=@name);

create procedure p3(@name char(10),@model char(30))
as
delete from owns
where owns.driver_id in(select person.driver_id
						from person
						where person.name=@name)
	and
	  owns.license in(select car.license
						from car
						where car.model=@model);