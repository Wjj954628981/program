EXEC sp_addlogin 'nkse';
EXEC sp_adduser 'nkse';
grant select to nkse;
deny update to nkse;
deny insert to nkse;
deny delete to nkse;