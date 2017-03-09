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

	//�������
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
			
			//��ȡ���
			edtUsername = (EditText) findViewById(R.id.edtUsername);
			edtPassword = (EditText) findViewById(R.id.edtPassword);
			chkAutoLogin = (CheckBox) findViewById(R.id.chkAutoLogin);
			
			//�����������Ի���
			loginDialog = new ProgressDialog(this);
			loginDialog.setMessage("������֤�û���Ϣ...");
			
			handler = new Handler() {

				@Override
				public void handleMessage(Message msg) {
					
					super.handleMessage(msg);

					//���ٽ������Ի���
					loginDialog.dismiss();
					
					if (msg.what == 1) {    
						
						//��������
						Gson gson = new Gson();
						User user = gson.fromJson(responseText, User.class);
						
						if(user!=null){   //��¼�ɹ�
							
							//�ж��´��Ƿ��Զ���¼
							if(chkAutoLogin.isChecked()){
								
								//��������
								SharedPreferences sp = getSharedPreferences("UserInfo", MODE_PRIVATE);
								
								Editor editor = sp.edit();
								
								editor.putString("username", edtUsername.getText().toString());
								editor.putString("password", edtPassword.getText().toString());
								
								editor.commit();
								
							}
							
							//��user���󱣴浽ȫ�ֱ�����
							MyApp myApp = (MyApp)getApplication();
							myApp.setUser(user);
							
							//��ת��������
							Intent intent = new Intent(LoginActivity.this, MainActivity.class);
							startActivity(intent);
							
							//�رյ�ǰҳ��
							finish();
							
						}else{
							Toast.makeText(getApplicationContext(), "�û����������������������", Toast.LENGTH_SHORT).show();
						}
		
						
					}else {
						Toast.makeText(getApplicationContext(), "�������ʧ��", Toast.LENGTH_SHORT).show();
					}
				}
			};
		}

		//�û���¼
		public void login(View v) {

			//�����������Ի���
			loginDialog.show();
			
			//������������߳�
			new Thread(new LoginRunner()).start();
		}

		private class LoginRunner implements Runnable {

			@Override
			public void run() {

				//ʵ����HttpClient����
				HttpClient client = new DefaultHttpClient();

				//ʵ����post�������
				HttpPost request = new HttpPost(url);

				//����post����
				try {

					//��װ�������
					List<NameValuePair> params = new ArrayList<NameValuePair>();
					params.add(new BasicNameValuePair("username", edtUsername.getText().toString()));
					params.add(new BasicNameValuePair("password", edtPassword.getText().toString()));
					
					//�����������
					request.setEntity(new UrlEncodedFormEntity(params, HTTP.UTF_8));

					//����post����
					HttpResponse response = client.execute(request);

					//���շ�������
					if (response.getStatusLine().getStatusCode() == HttpStatus.SC_OK) {

						responseText = EntityUtils.toString(response.getEntity());
							
						//�����̷߳�����Ϣ
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
