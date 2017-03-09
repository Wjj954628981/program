<%@page import="java.sql.ResultSet"%>
<%@page import="TestJDBC.DBManager"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<% 
	request.setCharacterEncoding("utf-8");
	String userid = (String)session.getAttribute("userid");
	String username = request.getParameter("username");
	String password = request.getParameter("password");
	String gender = request.getParameter("gender");
	String job = request.getParameter("job");
	String photo = request.getParameter("photo");
	out.println("<p>"+userid+"</p>");
	DBManager dbManager = new DBManager();
	String sql = "select * from user where userid=?";
	ResultSet rs = dbManager.execQuery(sql,userid);
	if(rs.next()){
		String sql2 = "update user set username = ?,password = ?, gender = ?,job = ?,photo = ? where userid= ?";
		if(dbManager.execUpdate(sql2,username,password,gender,job,photo,userid)>0){
			response.sendRedirect("UserQueryServlet");
		}
	}
%>
</body>
</html>