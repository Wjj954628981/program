<%@page import="com.etc.entity.User"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>index</title>
</head>
<body>
<%
	User user = (User)session.getAttribute("user");
	String photo = "image/photo/"+user.getPhoto();
%>
<img src="<%=photo%>">欢迎【<%=user.getUsername() %>】来到首页，您的积分为【<%=user.getScore() %>】分
<br/>
<a href="UserQueryServlet">查询所有人员</a>
</body>
</html>