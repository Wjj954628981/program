<%@page import="java.util.ArrayList"%>
<%@page import="com.etc.entity.User"%>
<%@page import="java.util.List"%>
<%@page import="com.etc.util.StringUtil"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>人员信息</title>
<script type="text/javascript">
	function delete_confirm(userid){
		if(confirm("确定删除？")){
			location="UserDeleteServlet?userid="+userid;
		}
	}
</script>
</head>
<body>
<%
	List<User> list = (List<User>)session.getAttribute("list");
	String username = (String)session.getAttribute("username");
	String gender = (String)session.getAttribute("gender");
	String job = (String)session.getAttribute("job");

%>
<h1 align="center">信息查询</h1>
<form action="UserQueryServlet" method="post">
	<div align="center">
		姓名<input type="text" name="username" style="width:50px;" value="<%=username%>"/>
		性别<select name="gender">
			<option value="全部性别"<%= "".equals(gender) ? "selected" : "" %>>全部性别</option>
		  	<option value="男" <%= "男".equals(gender) ? "selected" : "" %>>男</option>
		  	<option value="女"<%= "女".equals(gender) ? "selected" : "" %>>女</option>
		 	</select>
		职业<select name="job">
			<option value="全部职业"<%= "全部职业".equals(gender) ? "selected" : "" %>>全部职业</option>
		  	<option value="程序员"<%= "程序员".equals(gender) ? "selected" : "" %>>程序员</option>
		  	<option value="美工"<%= "美工".equals(gender) ? "selected" : "" %>>美工</option>
		   	<option value="项目经理"<%= "项目经理".equals(gender) ? "selected" : "" %>>项目经理</option>
		 	</select>
		<input type="submit" value="查询"/>
	</div>
</form>
<br/>
<table border="1" align="center" width="60%" cellspacing="0">
	<tr bgcolor='#CCCCCC'>
		<td>头像</td>
		<td>人员编号</td>
		<td>姓名</td>
		<td>密码</td>
		<td>得分</td>
		<td>性别</td>
		<td>职业</td>
		<td>注册时间</td>
		<td>操作</td>
	</tr>
<%
	boolean b= true;
	if(b){
		   out.println("<tr bgcolor='#ffffff'>");  
	}else{
		   out.println("<tr bgcolor='#CCCCCC'>");
	}
	for(User user: list){
	   String name = user.getUsername();
	   name = name.replaceAll(username, "<font color=red>"+username+"</font>");
	   String photo = user.getPhoto();
	   photo = "<a href='user_update.jsp?userid="+user.getUserid()+"'><img src='image/photo/" + photo + "'/></a>";
	   out.println("<td>" + photo + "</td><td>"+user.getUserid()+"</td><td>" + name + "</td><td>" + user.getPassword() + "</td><td>" + user.getScore()+ "</td><td>"+user.getGender()+ "</td><td>" + user.getJob() + "</td><td>" +StringUtil.convertDatetime(user.getRegtime(), "yyyy年MM月dd日 HH时mm分ss秒")+ "</td>") ;
	   //空指针错误，解决不掉
          //SimpleDateFormat mt = new SimpleDateFormat("yyyy年MM月dd日 HH时mm分ss秒");
          //out.println("<td>"+mt.format(rs.getTimestamp(8))+"</td>");
       out.println("<td><a href='javascript:delete_confirm("+user.getUserid()+")' style='text-decoration:none;'>删除</a></td>");
	   b=!b;
	   out.println("</tr>");
   }
   out.println("</tr>");
%>
</table>

</body>
</html>