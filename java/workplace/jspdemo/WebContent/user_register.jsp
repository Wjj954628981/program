<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>register</title>
</head>
<body>

<form action="UserRegisterServlet" method="post">

	<table align="center">
	
		<tr><td colspan="2" align="center"><font color="red"><b>新用户注册</b></font></td></tr>
		<tr>
			<td>用户名</td><td><input type="text" name="username" /></td>
		</tr>
		
		<tr>
			<td>密码</td><td><input type="password" name="password" /></td>
		</tr>
		
        	<tr>     	
	 	  <td>性别</td>
	  	  <td>
	   		<input type="radio" name="gender" value="男" checked/>男
	   		<input type="radio" name="gender" value="女" />女
	  	  </td>
	 	</tr>		 
	 
		 <tr>     	
		   <td>职业</td>
		   <td>
	   		  <select name="job">
	   			<option value="程序员">程序员</option>
	   			<option value="美工">美工</option>
	   			<option value="项目经理">项目经理</option>
	   		  </select>
	   	</td>
		</tr>	

		<tr>
			<td>头像</td>
			<td>
				<input type="radio" name="photo" value="1.gif" checked/> <img src="image/photo/1.gif"/> 
				<input type="radio" name="photo" value="2.gif" /> <img src="image/photo/2.gif"/> 
				<input type="radio" name="photo" value="3.gif" /> <img src="image/photo/3.gif"/> 
				<input type="radio" name="photo" value="4.gif" /> <img src="image/photo/4.gif"/> 
				<input type="radio" name="photo" value="5.gif" /> <img src="image/photo/5.gif"/> 
			</td>
		</tr>
		
		<tr>
			<td colspan="2" align="center">
				<input type="submit" value="立即注册" />
				<input type="reset" value="重新填写" />
			</td>
		</tr>
		
	</table>	

</form>
 
</body>
</html>