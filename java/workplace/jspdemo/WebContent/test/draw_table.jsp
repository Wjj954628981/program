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
	String srow = request.getParameter("row");
	String scol = request.getParameter("col");
	int row,col;
	if(srow==null){
		row=10;
	}else{
		row=Integer.parseInt(srow);
	}
	if(scol==null){
		col=10;
	}else{
		col=Integer.parseInt(scol);
	}
%>

<form method="post">
	绘制<input type="text" name="row" value="<%=row%>" style="width:50px;"/>行<input type="text" name="col" value="<%=col%>"style="width:50px;"/>列表格
	<input type="submit" value="提交"/>
</form>
<table border="1" cellspacing="0" align="center">
<% 
	int data = 1;
	for(int i=1; i<=row ; i++){
		String color = "";
		if(i%2==0){
			color = "#d0d0d0";
		}else{
			color = "#ffffff";
		}
		out.println("<tr bgcolor='" + color + "'>");
		for(int j=1; j<=col ; j++){
			out.println("<td>" + (data++) + "</td>");
		}
		out.println("</tr>");
	}
%>
</table>
</body>
</html>