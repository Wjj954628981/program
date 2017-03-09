package com.etc.service.impl;

import java.util.List;

import com.etc.dao.impl.UserDAOImpl;
import com.etc.entity.User;
import com.etc.service.UserService;

public class UserServiceImpl implements UserService {

private UserDAOImpl userDAO = new UserDAOImpl();
	
	@Override
	public User login(String username, String password) {

		//先查找用户
		User user = userDAO.findUser(username, password);
				
		if(user!=null){   //查找成功
			
			if(userDAO.updateScore(user, 1)){   //加分成功
				
				//给当前对象加分
				user.setScore(user.getScore() + 1);
				
				return user;
			}
		}
		
		return null;
	}

	@Override
	public User register(User user) {

		//先插入用户
		if(userDAO.insertUser(user)){
			
			//直接登录
			user = userDAO.findUser(user.getUsername(), user.getPassword());
			
			return user;
		}
		
		return null;
	}

	public List<User> findUsers(String username,String gender,String job){
		
		return userDAO.findUsers(username, gender, job);
		
	}

	@Override
	public boolean deleteUser(String userid) {
		// TODO Auto-generated method stub
		return userDAO.deleteUser(userid);
	}

	@Override
	public boolean updateUser(String username,String password,String gender,String job,String photo,String userid) {
		// TODO Auto-generated method stub
		User user = userDAO.findUserfromuserid(userid);
		if(user!=null){
			userDAO.updateUser(username, password,gender, job, photo, userid);
			return true;
		}
		return false;
	}

}
