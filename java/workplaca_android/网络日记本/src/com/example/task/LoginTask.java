package com.example.task;

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

import android.database.CursorJoiner.Result;
import android.os.AsyncTask;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.ImageView;

public class LoginTask extends AsyncTask<String, Void, String> {

	private EditText edtUsername;
	private EditText edtPassword;
	private CheckBox chkAutoLogin;
	
	public LoginTask(EditText edtUsername, EditText edtPassword, CheckBox chkAutoLogin){
		this.edtUsername = edtUsername;
		this.edtPassword = edtPassword;
		this.chkAutoLogin = chkAutoLogin;
	}
	
	@Override
	protected String doInBackground(String... arg0) {

		String url = "http://10.0.2.2:8080/jspdemo/UserLoginServlet";
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

				String responseText = EntityUtils.toString(response.getEntity());
					
			}

		} catch (ClientProtocolException e) {
			
			e.printStackTrace();
		} catch (IOException e) {
			
			e.printStackTrace();
		}
		return null;
	}
	@Override
	protected void onPostExecute(String result) {
		// TODO Auto-generated method stub
		super.onPostExecute(result);
	}

}
