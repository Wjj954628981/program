select name,year
from title
where callnumber in(select callnumber
				    from author
                    where lname='Churchill');/*1*/


select name,ISBN
from title
where callnumber in(select callnumber
					from book
                    where borrowermemno in(select memno
										   from member
                                           where fname='Jhon' or fname='Susan'));/*2*/
                                           
                                           
select fname,lname,driverlicno
from member
where memno in(select borrowermemno
			   from book
               where callnumber in(select callnumber
								   from title
                                   where name='Iliad'))
and
      memno in(select borrowermemno
			   from book
               where callnumber in(select callnumber
								   from title
                                   where name='Odyssey'));/*3*/


select fname,lname,driverlicno
from member
where memno in(select borrowermemno
			   from (select borrowermemno,callnumber
					 from book
                     where callnumber in(select callnumber
										 from author
                                         where lname='Collins')
					 union
                     select borrowermemno,callnumber
                     from book
                     where callnumber in(select callnumber
										 from author
                                         where lname='Collins'))as midtab
					 group by borrowermemno
                     having count(borrowermemno)=(select count(lname)
										 from author
                                         where lname='Collins'));/*4*/

                                         
select phonenumber
from member
where memno in(select borrowermemno
			   from book
               where callnumber in(select callnumber
								   from author
                                   where lname='Tanenbaum'));/*5*/
                                   

select member.fname,member.lname,member.memno,book.book_id
from member,book
where member.memno=book.borrowermemno
group by book.book_id, member.fname, member.lname, member.memno
having (select count(book.borrowermemno)
        from book
        where member.memno = book.borrowermemno) > 3
order by count(book.book_id) desc;/*6*/


select Member.Fname,Member.Lname,Member.MemNo
from Member
where Member.MemNo not in(select Member.MemNo  
						  from Member, Book
						  where Member.MemNo = Book.BorrowerMemNo
						  group by Member.MemNo
						  having count(Book.BorrowerMemNo)>=1);/*7*/
                          
                          
select Member.Fname
from Member
where Member.MemNo not in(select Book.BorrowerMemNo
                          from Book
                          where Book.CallNumber=(select Title.CallNumber  
												 from Title
												 where Title.Name='Pitt Roads'))and Member.PhoneNumber like '412%';/*8*/