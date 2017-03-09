<%@page import="com.etc.entity.User"%>
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
	String gender = request.getParameter("gender");
	String job = request.getParameter("job");
	String photo = request.getParameter("photo");
	
	if(username!=""){
		if(password!=""){
			
			DBManager dbManager = new DBManager();
			String sql = "insert into user values(null,?,?,default,?,?,?,default)";
			if(dbManager.execUpdate(sql,username,password,photo,gender,job)>0){
				String sql2 = "select * from user where username=? and password=?";
			    ResultSet rs = dbManager.execQuery(sql2,username,password);
			    if(rs.next()){
			    	User user = new User();
					user.setUsername(rs.getString(2));
					user.setScore(rs.getInt(4));
					user.setPhoto(rs.getString(5));
					session.setAttribute("user", user);
					dbManager.closeConnection();
					//javascript跳转	
					//out.println("<script>alert('注册成功');location='index.jsp';</script>");
					
					//立即跳转
					//response.sendRedirect("index.jsp");
					
					//延迟跳转
					response.setHeader("refresh", "3,url=index.jsp");
					out.println("<font color='red' size='10'>恭喜，注册成功系统将在三秒后跳转到主页</font><br/>");
					out.println("如果没有跳转，请点击<a href='index.jsp'>这里</a>");
			    }
			}else{
				out.println("<script>alert('注册失败');history.back(-1);</script>");
			}
			}else{
				out.println("<script>alert('注册失败，请设置密码');history.back(-1);</script>");
			}
		}else{
			out.println("<script>alert('注册失败，请输入用户名');location='user_register.jsp';</script>");
		}
%>
</body>
</html>