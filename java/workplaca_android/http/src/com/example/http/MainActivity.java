package com.example.http;

import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;

import org.apache.http.HttpResponse;
import org.apache.http.HttpStatus;
import org.apache.http.NameValuePair;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.protocol.HTTP;
import org.apache.http.util.EntityUtils;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.Menu;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {

	private String url = "http://10.0.2.2:8080/AndroidNetwork/AndroidServlet";
	
	private EditText edtUsername;
	
	private TextView txtResult;
	
	private String responseText;
	
	private Handler handler;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		
		edtUsername = (EditText) findViewById(R.id.edtUsername);
		txtResult = (TextView) findViewById(R.id.txtResult);
		
		handler = new Handler(){
			@Override
			public void handleMessage(Message msg) {
				super.handleMessage(msg);
				if(msg.what == 1){
					txtResult.setText(responseText);
				}
			}
		};
	}

	public void get(View v){
		txtResult.setText("正在请求get。。。");
		new Thread(new GetRunner()).start();
		
	}
	
	public void post(View v){
		txtResult.setText("正在请求post。。。");
		new Thread(new PostRunner()).start();
	}
	
	private class GetRunner implements Runnable{

		@Override
		public void run() {
			
			String username = edtUsername.getText().toString();
			
			HttpClient client = new DefaultHttpClient();
			
			HttpGet request = new HttpGet(url + "?username=" + username);
			
			try {
				HttpResponse response = client.execute(request);
				
				if (response.getStatusLine().getStatusCode() == HttpStatus.SC_OK) {
					
			           responseText = EntityUtils.toString(response.getEntity());
			           /*Message msg = new Message();
			           msg.obj = responseText;
			           handler.sendMessage(msg);*/
			           handler.sendEmptyMessage(1);
			 	}
							
			} catch (ClientProtocolException e) {
				e.printStackTrace();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
	}
	
	private class PostRunner implements Runnable{

		@Override
		public void run() {
			
			
			String username = edtUsername.getText().toString();
			
			HttpClient client = new DefaultHttpClient();
			 
			HttpPost request = new HttpPost(url);
			
			List<NameValuePair> params = new ArrayList<NameValuePair>();
			
			params.add(new BasicNameValuePair("username", username));

			try {
				request.setEntity(new UrlEncodedFormEntity(params,HTTP.UTF_8));
				
				HttpResponse response = client.execute(request);
				
			 	if (response.getStatusLine().getStatusCode() == HttpStatus.SC_OK) {
				
			           responseText = EntityUtils.toString(response.getEntity());
			           handler.sendEmptyMessage(1);
			 	}
			} catch (UnsupportedEncodingException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (ClientProtocolException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		}
		
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
