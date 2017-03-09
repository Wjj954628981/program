CREATE TRIGGER reorder_trigger ON inventory
AFTER UPDATE
AS
declare @item numeric(3, 0);
select @item=item from deleted;
if exists (select level 
			from inserted
			where inserted.level<=(select level							
									from minlevel						
									where minlevel.item=@item))
and exists (select level
			from deleted
			where deleted.level>(select level
								from minlevel
								where minlevel.item=@item))
BEGIN
insert into orders
		select item,amount
		from reorder
		where reorder.item=@item
END