package com.wordsworth.struts;

public class LoginAction {
	private String username;
	private String userpassword;

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}
	
	public String getUserpassword() {
		return userpassword;
	}

	public void setUserpassword(String userpassword) {
		this.userpassword = userpassword;
	}
	
	public String execute() throws Exception {
		String result = "error";
		if ("admin".equals(username) && "admin".equals(userpassword)) {
			result = "success";
		}
		return result;
	}

}
