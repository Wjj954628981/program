<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>login</title>
<!--<input type="hidden" name="flag" id="flag" value="<%=request.getParameter("flag")%>">
<script language=javascript>
   if(document.getElmentById("flag").value=='PasswdIsWrong')
   {
        alert('密码为空，重新输入!');
   }
   else if(document.getElmentById("flag").value=='UsernameIsWrong')
   {
       alert('用户名为空，重新输入!');
    }
</script>-->
</head>
<body>
<h1 align="center">login</h1>
<form name="form1" action="UserLoginServlet" method="post">
	<div id="div1" align="center">
		用户名<input type="text" id="username" name="username" style="width:50px;"/>
		<br/>
		密码<input type="password" id="password" name="password" style="width:50px;"/>
		<br/>
		<input type="submit" value="登陆"/>
		<input type="button" value="注册" onclick="location='user_register.jsp';"/>
	</div>
</form>
</body>
</html>