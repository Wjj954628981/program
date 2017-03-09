select person_name
from works
where company_name='First Bank Corporation';/*1*/

select works.person_name,city
from works,employees
where works.company_name='First Bank Corporation' and employees.person_name=works.person_name;/*2*/

select works.person_name,street,city
from works,employees
where works.salary>10000 and works.person_name=employees.person_name;/*3*/

select person_name
from employees
where city in(select city
			  from company join works on company.company_name=works.company_name
			  where employees.person_name=person_name);/*4*/

select T.person_name
from employees as T,employees as S,manages
where T.street=S.street and T.city=S.city and T.person_name=manages.person_name and S.person_name=manages.manager_name;/*5*/
					    
(select person_name
from works)
except
(select person_name
from works
where works.company_name='First Bank Corporation');/*6*/

select person_name
from works
where salary>all(select salary
				 from works
				 where company_name='Small Bank Corporation');/*7*/