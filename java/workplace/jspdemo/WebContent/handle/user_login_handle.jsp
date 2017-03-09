<%@page import="com.etc.entity.User"%>
<%@page import="java.sql.SQLException"%>
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
	String username = request.getParameter("username");
	String password = request.getParameter("password");
	DBManager dbManager = new DBManager();
    String sql = "select * from user where username=? and password=?";
    ResultSet rs = dbManager.execQuery(sql,username,password);
    try {
    if(rs.next()){
	    //out.println("登陆成功");
	    User user = new User();
	    user.setUsername(username);
	    user.setScore(rs.getInt(4));
	    user.setPhoto(rs.getString(5));
	    session.setAttribute("user", user);
	   
	    response.sendRedirect("index.jsp");
     }else{
	    //out.println("登陆失败");
	    out.println("<script>alert('用户名或者密码错误');location='user_login.jsp';</script>");
     }
     } catch (SQLException e) {
		e.printStackTrace();
     } finally{
		dbManager.closeConnection();
	 }
%>
</body>
</html>