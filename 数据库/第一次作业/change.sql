update employees
set city='new town'
where person_name='Aaron';/*1*/

update works
set salary=salary*1.1
where company_name='Ateck Shower Corporation';/*2*/

update works
set salary=salary*1.1
where person_name in(select manager_name from manages);/*3*/

update works
set salary=case
			when person_name in(select manager_name from manages)and salary<=10000
			then salary*1.1
			when person_name in(select manager_name from manages)and salary>=10000
			then salary*1.03
		end;/*4*/

delete from works
where company_name='Aaron'/*5*/