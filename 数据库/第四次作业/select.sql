select libid,fname as firstName,join_date as joinAt
from member4
where join_date<'1997-11-30'and libid like 'A_____';

select name,isbn,callnumber
from title4
where callnumber in(select callnumber
					from order4, purchase_order4
					where order4.ponum = purchase_order4.ponum
					group by callnumber
					having count(supplier_id)>1and sum(qty)>10
					/*order by sum(qty) desc*/);

select libid,fname
from MEMBER4
where libid in(select lib_id
			   from read_by4,TITLE4
			   where read_by4.callnumber=TITLE4.callnumber
			   group by read_by4.lib_id
			   having count(read_by4.lib_id)<0.05*count(TITLE4.isbn));

