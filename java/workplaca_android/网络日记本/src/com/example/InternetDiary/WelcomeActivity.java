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
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;

import com.example.MyApp.MyApp;
import com.example.entity.User;
import com.google.gson.Gson;

public class WelcomeActivity extends Activity {

	private String url = "http://10.0.2.2:8080/jspdemo/UserLoginServlet";

	private String username, password;
	
	private String responseText;

	private Handler handler;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_welcome);
		
		//�ж��Ƿ��Զ���¼	
		isAutoLogin();
		
		handler = new Handler(){
			
			@Override
			public void handleMessage(Message msg) {
				
				if(msg.what == 1){   //��¼��֤
					
					Gson gson = new Gson();
					
					User user = gson.fromJson(responseText, User.class);

					if (user != null) {		// ��¼�ɹ�
						
						//��user���󱣴浽ȫ�ֱ�����
						MyApp myApp = (MyApp)getApplication();
						myApp.setUser(user);

						//��ת��������
						Intent intent = new Intent(WelcomeActivity.this, MainActivity.class);
						startActivity(intent);
						finish();

					} else {   //��¼ʧ��
						
						//��ת����¼����
						Intent intent = new Intent(WelcomeActivity.this, LoginActivity.class);
						startActivity(intent);
						finish();
					}
					
				}else if(msg.what == 2){   //�ӳ���ת����¼����
					
					//��ת��������
					Intent intent = new Intent(WelcomeActivity.this, LoginActivity.class);
					
					startActivity(intent);
					finish();
					
				}else{
					
					//��ת����¼����
					Intent intent = new Intent(WelcomeActivity.this, LoginActivity.class);
					startActivity(intent);
					finish();
				}
			}
		};
		
	}

	//�ж��Ƿ��Զ���¼
	private void isAutoLogin() {

		SharedPreferences sp = getSharedPreferences("UserInfo", MODE_PRIVATE);

		if (sp.contains("username") && sp.contains("password")) {
			username = sp.getString("username", null);
			password = sp.getString("password", null);
			new Thread(new LoginRunner()).start();
		} else {
			new Thread(new WelcomeRunner()).start();
		}
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
				params.add(new BasicNameValuePair("username", username));
				params.add(new BasicNameValuePair("password", password));
				
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
	
	private class WelcomeRunner implements Runnable{

		@Override
		public void run() {

			try {
				Thread.sleep(3000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			
			handler.sendEmptyMessage(2);
			
		}
	}
	

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
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
            View rootView = inflater.inflate(R.layout.fragment_welcome, container, false);
            return rootView;
        }
    }

}
