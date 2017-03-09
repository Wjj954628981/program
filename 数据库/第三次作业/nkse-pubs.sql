EXEC sp_adduser 'nkse';
grant select to nkse;
grant insert to nkse;
deny update to nkse;
deny delete to nkse;