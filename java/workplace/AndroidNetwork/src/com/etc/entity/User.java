package com.etc.entity;

import java.io.Serializable;
import java.sql.Date;

public class User implements Serializable {

	private String username;
	
	private String password;
	
	private Date date;
	
	private String Theme;
	
	private String content;
	
	
	
	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public Date getDate() {
		return date;
	}

	public void setDate(Date date) {
		this.date = date;
	}

	public String getTheme() {
		return Theme;
	}

	public void setTheme(String theme) {
		Theme = theme;
	}

	public String getContent() {
		return content;
	}

	public void setContent(String content) {
		this.content = content;
	}

	public User(String username, String password, Date date, String theme, String content) {
		super();
		this.username = username;
		this.password = password;
		this.date = date;
		Theme = theme;
		this.content = content;
	}

	public User(){
		
	}
	
	
}
