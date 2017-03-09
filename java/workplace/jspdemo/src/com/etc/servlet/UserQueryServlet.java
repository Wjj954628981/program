package com.etc.servlet;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.etc.entity.User;
import com.etc.service.UserService;
import com.etc.service.impl.UserServiceImpl;

public class UserQueryServlet extends HttpServlet {
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
	    HttpSession session = request.getSession();	

		//设置字符编码---需要字符转码时加此句
		request.setCharacterEncoding("utf-8"); 

		//接收数据
		String username = request.getParameter("username");
		String gender = request.getParameter("gender");
		String job = request.getParameter("job");
		if(username==null){
			username = "";
		}
		if(gender==null||"全部性别".equals(gender)){
			gender="";
		}
		if(job==null||"全部职业".equals(job)){
			job="";
		}
		
		//组合业务对象
		UserService userService = new UserServiceImpl();
		
		//调用业务方法
		List<User> list = userService.findUsers(username,gender,job);
		
		//保存用户列表
		session.setAttribute("list", list);
		
		//保存输入的数据
		session.setAttribute("username", username);
		session.setAttribute("gender", gender);
		session.setAttribute("job", job);
		
		//跳转到查询页面
		response.sendRedirect("user_query.jsp");
	}

}
