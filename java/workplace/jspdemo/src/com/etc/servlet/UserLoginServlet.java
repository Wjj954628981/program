package com.etc.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.etc.entity.User;
import com.etc.service.UserService;
import com.etc.service.impl.UserServiceImpl;
import com.google.gson.Gson;

public class UserLoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.doPost(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//设置输出内容类型
		response.setContentType("text/html;charset=utf-8");	

		//获取out输出对象---需要输出内容时加此句
		PrintWriter out = response.getWriter();	   	

		//获取session对象---需要session对象时加此句
	    HttpSession session = request.getSession();	

		//设置字符编码---需要字符转码时加此句
		request.setCharacterEncoding("utf-8"); 	

		//接收数据
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		
		
		if(username!=null){
			if(password!=null){
				//组合业务对象
				UserService userService = new UserServiceImpl();
				
				//调用业务方法
				User user = userService.login(username, password);
				
			//	if(user!=null){    //登录成功
					
						
					/*web项目对象保存在session中
					//将用户对象保存在session属性范围中
						session.setAttribute("user", user);		
					
						//跳转到主页
						response.sendRedirect("index.jsp");*/
					
					//android项目对象保存在gson中
				 Gson gson = new Gson();		


			     String userjson = gson.toJson(user);
			     
			     out.println(userjson);
					
				 out.flush();

						
				//}else{
					//String userjson = "";
					//out.println("<script>alert('用户名或密码错误，请重新输入');location='user_login.jsp'</script>");		
				//}
			    }else{
			    	//out.println("<html><body load=\"alert('密码为空，重新输入');\"></body></html>");
					//out.println("javascript:alert('密码为空，重新输入');");
					//out.println("<script language='javascript'>alert('密码为空，重新输入');</script>"); 
				    //response.sendRedirect("user_login.jsp?flag=PasswdIsWrong");
				    //out.println("<script language='javascript'>alert('密码为空，重新输入!');window.open('a.jsp','_self')</script>");
			}
		}else{
			//out.println("javascript:alert('用户名为空，重新输入');");
			//response.sendRedirect("user_login.jsp?flag=UsernameIsWrong");
			//out.println("<html><body load=\"alert('用户名为空，重新输入');\"></body></html>");
			//out.println("<script language='javascript'>alert('用户名为空，重新输入!');window.location='a.jsp'</script>");
		}
	}

}