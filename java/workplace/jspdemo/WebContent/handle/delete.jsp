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
	String userid = request.getParameter("userid");
	DBManager dbManager = new DBManager();
    String sql = "delete from user where userid = ?";
    int rows = dbManager.execUpdate(sql, userid);
    if(rows>0){
	    response.sendRedirect("UserQueryServlet");
    }
%>
</body>
</html>