package com.example.bodytest;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.v4.app.Fragment;
import android.support.v7.app.ActionBarActivity;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;

public class WelcomeActivity extends ActionBarActivity {

	
	//声明消息处理器
	private Handler handler;
	
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_welcome);

		//实例化消息处理器
		handler = new Handler(){
			@Override
			public void handleMessage(Message msg) {
				
				//接收消息
				if(msg.what==1){
					
					//在主线程中更新UI
					Intent intent = new Intent(WelcomeActivity.this, TestActivity.class);
					//启动Activity
					startActivity(intent);
					finish();
				}
				
				super.handleMessage(msg);
			}
		};

		
		new Thread(new LateRunner()).start();
		
		if (savedInstanceState == null) {
			getSupportFragmentManager().beginTransaction()
					.add(R.id.container, new PlaceholderFragment()).commit();
		}
	}

	
	private class LateRunner implements Runnable{

		@Override
		public void run() {

				
				//Message msg = new Message();
				//msg.arg1=100;
				//handler.sendMessage(msg);
				
				try {
					Thread.sleep(3000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				//向主线程发送消息
				handler.sendEmptyMessage(1);
		}
		
	}
	
	
	public void into(View v){
		Intent intent = new Intent(WelcomeActivity.this, TestActivity.class);
		//启动Activity
		startActivity(intent);
		finish();
	}
	
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {

		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.welcome, menu);
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
			View rootView = inflater.inflate(R.layout.fragment_welcome,
					container, false);
			return rootView;
		}
	}

}
