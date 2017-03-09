package com.etc.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.etc.service.UserService;
import com.etc.service.impl.UserServiceImpl;


public class UserDeleteServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.doPost(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//设置输出内容类型
		response.setContentType("text/html;charset=utf-8");	

		//获取out输出对象---需要输出内容时加此句
		//PrintWriter out = response.getWriter();	   	

		//获取session对象---需要session对象时加此句
	    //HttpSession session = request.getSession();	

		//设置字符编码---需要字符转码时加此句
		request.setCharacterEncoding("utf-8"); 	

		//接收数据
		String userid = request.getParameter("userid");
		
		UserService userService = new UserServiceImpl();
		
		//调用业务方法
		if(userService.deleteUser(userid)){
			response.sendRedirect("UserQueryServlet");
		}
		
	}

}
