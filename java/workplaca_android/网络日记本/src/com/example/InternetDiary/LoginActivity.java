package com.example.InternetDiary;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import org.apache.http.HttpResponse;
import org.apache.http.HttpStatus;
import org.apache.http.NameValuePair;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.protocol.HTTP;
import org.apache.http.util.EntityUtils;

import android.app.Activity;
import android.app.Fragment;
import android.app.ProgressDialog;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Toast;

import com.example.MyApp.MyApp;
import com.example.entity.User;
import com.google.gson.Gson;

public class LoginActivity extends Activity {

	//声明组件
		private EditText edtUsername;
		private EditText edtPassword;
		private CheckBox chkAutoLogin;
		
		private String url = "http://10.0.2.2:8080/jspdemo/UserLoginServlet";

		private Handler handler;
		
		private String responseText;
		
		private ProgressDialog loginDialog;
		
		@Override
		protected void onCreate(Bundle savedInstanceState) {
			super.onCreate(savedInstanceState);
			setContentView(R.layout.activity_login);
			
			//获取组件
			edtUsername = (EditText) findViewById(R.id.edtUsername);
			edtPassword = (EditText) findViewById(R.id.edtPassword);
			chkAutoLogin = (CheckBox) findViewById(R.id.chkAutoLogin);
			
			//创建进度条对话框
			loginDialog = new ProgressDialog(this);
			loginDialog.setMessage("正在验证用户信息...");
			
			handler = new Handler() {

				@Override
				public void handleMessage(Message msg) {
					
					super.handleMessage(msg);

					//销毁进度条对话框
					loginDialog.dismiss();
					
					if (msg.what == 1) {    
						
						//解析数据
						Gson gson = new Gson();
						User user = gson.fromJson(responseText, User.class);
						
						if(user!=null){   //登录成功
							
							//判断下次是否自动登录
							if(chkAutoLogin.isChecked()){
								
								//保存密码
								SharedPreferences sp = getSharedPreferences("UserInfo", MODE_PRIVATE);
								
								Editor editor = sp.edit();
								
								editor.putString("username", edtUsername.getText().toString());
								editor.putString("password", edtPassword.getText().toString());
								
								editor.commit();
								
							}
							
							//将user对象保存到全局变量中
							MyApp myApp = (MyApp)getApplication();
							myApp.setUser(user);
							
							//跳转到主界面
							Intent intent = new Intent(LoginActivity.this, MainActivity.class);
							startActivity(intent);
							
							//关闭当前页面
							finish();
							
						}else{
							Toast.makeText(getApplicationContext(), "用户名或密码错误，请重新输入", Toast.LENGTH_SHORT).show();
						}
		
						
					}else {
						Toast.makeText(getApplicationContext(), "网络访问失败", Toast.LENGTH_SHORT).show();
					}
				}
			};
		}

		//用户登录
		public void login(View v) {

			//启动进度条对话框
			loginDialog.show();
			
			//启动网络访问线程
			new Thread(new LoginRunner()).start();
		}

		private class LoginRunner implements Runnable {

			@Override
			public void run() {

				//实例化HttpClient对象
				HttpClient client = new DefaultHttpClient();

				//实例化post请求对象
				HttpPost request = new HttpPost(url);

				//发出post请求
				try {

					//封装请求参数
					List<NameValuePair> params = new ArrayList<NameValuePair>();
					params.add(new BasicNameValuePair("username", edtUsername.getText().toString()));
					params.add(new BasicNameValuePair("password", edtPassword.getText().toString()));
					
					//设置请求参数
					request.setEntity(new UrlEncodedFormEntity(params, HTTP.UTF_8));

					//发出post请求
					HttpResponse response = client.execute(request);

					//接收返回数据
					if (response.getStatusLine().getStatusCode() == HttpStatus.SC_OK) {

						responseText = EntityUtils.toString(response.getEntity());
							
						//向主线程发送消息
						handler.sendEmptyMessage(1);
					}

				} catch (ClientProtocolException e) {
					
					e.printStackTrace();
					handler.sendEmptyMessage(-1);
				} catch (IOException e) {
					
					e.printStackTrace();
					handler.sendEmptyMessage(-1);
				}
			}
		}
	
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {

		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.login, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}

	/**
	 * A placeholder fragment containing a simple view.
	 */
	public static class PlaceholderFragment extends Fragment {

		public PlaceholderFragment() {
		}

		@Override
		public View onCreateView(LayoutInflater inflater, ViewGroup container,
				Bundle savedInstanceState) {
			View rootView = inflater.inflate(R.layout.fragment_login,
					container, false);
			return rootView;
		}
	}

}
