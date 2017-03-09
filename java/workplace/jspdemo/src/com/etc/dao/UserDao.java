package com.etc.dao;

import java.util.List;

import com.etc.entity.User;

public interface UserDao {
	//根据用户名和密码查找用户
	User findUser(String username, String password);
	
	//给用户加积分
	boolean updateScore(User user, int score);

	//插入新用户 
	boolean insertUser(User user);
	
	//根据职业性别用户名模糊查询用户
	List<User> findUsers(String username,String gender,String job);
	
	//删除用户
	boolean deleteUser(String userid);
	
	//用户数据更新
	boolean updateUser(String username,String password,String gender,String job,String photo,String userid);
	
	//更具编号查找用户
	User findUserfromuserid(String userid);
}
