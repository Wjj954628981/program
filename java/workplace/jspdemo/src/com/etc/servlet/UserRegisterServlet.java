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


public class UserRegisterServlet extends HttpServlet {
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
		request.setCharacterEncoding("utf-8");
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		String gender = request.getParameter("gender");
		String job = request.getParameter("job");
		String photo = request.getParameter("photo");


		if(username!=null||"".equals(username)){
			if(password!=null||"".equals(password)){
				//创建并填充实体bean
				User user = new User();
				
				user.setUsername(username);
				user.setPassword(password);
				user.setGender(gender);
				user.setJob(job);
				user.setPhoto(photo);
				
				//组合业务对象
				UserService userService = new UserServiceImpl();
				
				//调用业务方法
				user = userService.register(user);
				
				if(user!=null){   //注册成功
					
					//将用户对象保存在session属性范围中
					session.setAttribute("user", user);		
								
					//延迟跳转
					response.setHeader("refresh", "3;url=index.jsp");
					out.println("<font color='red' size='10'>恭喜，注册成功，系统将在三秒后跳转到主页</font><br/>");
					out.println("如果没有跳转，请点击<a href='index.jsp'>这里</a>");
							
				}else{
					
					out.println("<script>alert('注册失败，请重新输入');history.back()</script>");		
				}

			}else{
				//out.println("<script>alert('注册失败，密码为空，请输入密码');history.back(-1);</script>");
				response.sendRedirect("user_register.jsp");
			}
		}else{
			//out.println("<script>alert('注册失败，用户名为空，请输入用户名');history.back(-1);</script>");
			response.sendRedirect("user_register.jsp");
		}
	}
}
