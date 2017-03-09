<%@page import="java.sql.ResultSet"%>
<%@page import="TestJDBC.DBManager"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>update</title>
</head>
<body>
<% 
	request.setCharacterEncoding("utf-8");
	String userid = request.getParameter("userid");
	
	String username = "wjj";
	String password = "wjj";
	String photo = "1.gif";
	String gender = "男";
	String job = "美工";
	
	DBManager dbManager = new DBManager();
	String sql = "select * from user where userid=?";
	ResultSet rs = dbManager.execQuery(sql,userid);
	if(rs.next()){
		username = rs.getString(2);
		password = rs.getString(3);
		photo = rs.getString(5);
		gender = rs.getString(6);
		job = rs.getString(7);
	}
	
    session.setAttribute("userid", userid);
%>
<form action="UserUpdateServlet" method="post">

	<table align="center">
	
		<tr><td colspan="2" align="center"><font color="red"><b>用户<%=userid %>更改信息</b></font></td></tr>
		<tr>
			<td>用户名</td><td><input type="text" name="username" value="<%=username%>"/></td>
		</tr>
		
		<tr>
			<td>密码</td><td><input type="password" name="password" value="<%= password%>"/></td>
		</tr>
		
        	<tr>     	
	 	  <td>性别</td>
	  	  <td>
	   		<input type="radio" name="gender" value="男" <%="男".equals(gender)?"checked" : "" %>/>男
	   		<input type="radio" name="gender" value="女" <%="女".equals(gender)?"checked" : "" %>/>女
	  	  </td>
	 	</tr>		 
	 
		 <tr>     	
		   <td>职业</td>
		   <td>
	   		  <select name="job">
	   			<option value="程序员" <%="程序员".equals(job)?"selected" : "" %>>程序员</option>
	   			<option value="美工" <%="美工".equals(job)?"selected" : "" %>>美工</option>
	   			<option value="项目经理" <%="项目经理".equals(job)?"selected" : "" %>>项目经理</option>
	   		  </select>
	   	</td>
		</tr>	

		<tr>
			<td>头像</td>
			<td>
				<input type="radio" name="photo" value="1.gif" <%="1.gif".equals(photo)?"checked" : "" %>/> <img src="image/photo/1.gif"/> 
				<input type="radio" name="photo" value="2.gif" <%="2.gif".equals(photo)?"checked" : "" %>/> <img src="image/photo/2.gif"/> 
				<input type="radio" name="photo" value="3.gif" <%="3.gif".equals(photo)?"checked" : "" %>/> <img src="image/photo/3.gif"/> 
				<input type="radio" name="photo" value="4.gif" <%="4.gif".equals(photo)?"checked" : "" %>/> <img src="image/photo/4.gif"/> 
				<input type="radio" name="photo" value="5.gif" <%="5.gif".equals(photo)?"checked" : "" %>/> <img src="image/photo/5.gif"/> 
			</td>
		</tr>
		
		<tr>
			<td colspan="2" align="center">
				<input type="submit" value="立即更改" />
			</td>
		</tr>
		
	</table>	

</form>
 
</body>
</html>