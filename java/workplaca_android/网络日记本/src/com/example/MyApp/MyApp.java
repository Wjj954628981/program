package com.example.MyApp;

import com.example.entity.User;

import android.app.Application;

public class MyApp extends Application {

	private User user;

	public User getUser() {
		return user;
	}

	public void setUser(User user) {
		this.user = user;
	}
	
	
}
