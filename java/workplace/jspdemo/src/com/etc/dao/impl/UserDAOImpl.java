package com.etc.dao.impl;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import com.etc.dao.UserDao;
import com.etc.entity.User;

import TestJDBC.DBManager;

public class UserDAOImpl implements UserDao {

private DBManager dbManager = new DBManager();
	
	@Override
	public User findUser(String username, String password) {
		
		String sql = "select * from user where username = ? and password = ?";
		
		ResultSet rs = dbManager.execQuery(sql, username, password);
		
		try {
			if(rs.next()){   //找到
				
				//创建并填充实体bean
				User user = new User();
				
				user.setUserid(rs.getInt(1));
				user.setUsername(username);
				user.setScore(rs.getInt(4));
				user.setPhoto(rs.getString(5));
				
				return user;
				
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
			
			
		} finally{
			dbManager.closeConnection();
		}
		
		return null;
		
	}

	@Override
	public boolean updateScore(User user, int score) {

		String sql = "update user set score = score + ? where userid = ?";
		
		return dbManager.execUpdate(sql, score, user.getUserid()) > 0;
	
	}

	@Override
	public boolean insertUser(User user) {

		String sql = "insert into user values(null, ? ,? ,10, ?, ? , ?, now())";
		
		return dbManager.execUpdate(sql, user.getUsername(), user.getPassword(), user.getPhoto(),
				user.getGender(), user.getJob()) > 0;
	}
	
	public List<User> findUsers(String username,String gender,String job){
		
		String sql = "select * from user where gender like ? and job like ? and username like ?";
		
		ResultSet rs = dbManager.execQuery(sql,"%"+gender+"%","%"+job+"%","%"+username+"%");
		List<User> list=new ArrayList<User>();
		try {
			while(rs.next()){
				User user = new User();
				user.setUserid(rs.getInt(1));
				user.setUsername(rs.getString(2));
				user.setPassword(rs.getString(3));
				user.setScore(rs.getInt(4));
				user.setPhoto(rs.getString(5));
				user.setGender(rs.getString(6));
				user.setJob(rs.getString(7));
				user.setRegtime(rs.getString(8));
				
				list.add(user);
			}
			return list;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			dbManager.closeConnection();
		}	
			
		return null;
		
	}

	@Override
	public boolean deleteUser(String userid) {
	    String sql = "delete from user where userid = ?";
	    int rows = dbManager.execUpdate(sql, userid);
	    if(rows>0){
		    return true;
	    }else{
	    	return false;
	    }
	}

	@Override
	public boolean updateUser(String username, String password, String gender, String job, String photo, String userid) {
		String sql2 = "update user set username = ?,password = ?, gender = ?,job = ?,photo = ? where userid= ?";
		if(dbManager.execUpdate(sql2,username,password,gender,job,photo,userid)>0){
			return true;
		}else{
			return false;
		}
		
	}

	@Override
	public User findUserfromuserid(String userid) {
		String sql = "select * from user where userid=?";
		
		ResultSet rs = dbManager.execQuery(sql, userid);
		
		try {
			if(rs.next()){   //找到
				
				//创建并填充实体bean
				User user = new User();
				
				user.setUserid(rs.getInt(1));
				user.setUsername(rs.getString(2));
				user.setPassword(rs.getString(3));
				user.setScore(rs.getInt(4));
				user.setPhoto(rs.getString(5));
				user.setGender(rs.getString(6));
				user.setJob(rs.getString(7));
				user.setRegtime(rs.getString(8));
				
				return user;
				
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
			
			
		} finally{
			dbManager.closeConnection();
		}
		
		return null;
	}
}
