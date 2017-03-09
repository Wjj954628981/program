package com.etc.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.etc.service.UserService;
import com.etc.service.impl.UserServiceImpl;


public class UserUpdateServlet extends HttpServlet {
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
		String userid = (String)session.getAttribute("userid");
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		String gender = request.getParameter("gender");
		String job = request.getParameter("job");
		String photo = request.getParameter("photo");
		out.println("<p>"+userid+"</p>");
		
		UserService userService = new UserServiceImpl();
		userService.updateUser(username,password,gender,job,photo,userid);
		response.sendRedirect("UserQueryServlet");
		
	}

}
