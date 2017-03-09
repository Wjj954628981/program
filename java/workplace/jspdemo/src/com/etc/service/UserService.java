package com.etc.service;

import java.util.List;

import com.etc.entity.User;

public interface UserService {
	//用户登录
	User login(String username, String password);
	
	//用户注册
	User register(User user);
	
	//查询用户
	List<User> findUsers(String username,String gender,String job);
	
	//用户删除
	boolean deleteUser(String userid);
	
	//用户更新
	boolean updateUser(String username,String password,String gender,String job,String photo,String userid);
}
