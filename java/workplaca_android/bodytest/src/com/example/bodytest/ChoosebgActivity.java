package com.example.bodytest;

import android.content.Intent;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v7.app.ActionBarActivity;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;

public class ChoosebgActivity extends ActionBarActivity {

	
	private int bg = 1;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_choosebg);

		if (savedInstanceState == null) {
			getSupportFragmentManager().beginTransaction()
					.add(R.id.container, new PlaceholderFragment()).commit();
		}
	}

	public void bgchange1(View v){
		bg = 1;
	}
	
	
	public void bgchange2(View v){
		bg = 2;
	}
	
	
	public void bgchange3(View v){
		bg = 3;
	}
	
	
	public void ok(View v){
		//获取发送的Intent
		Intent intent = this.getIntent();

		//传递返回值
		intent.putExtra("bg", bg);
		
		//携带intent返回发送界面
		setResult(RESULT_OK, intent);  //resultCode用于标识是否成功返回  RESULT_OK---成功   RESULT_CANCEL---取消
		
		//关闭当前界面
		finish();
	}
	
	public void no(View v){
		//关闭当前界面
		finish();
	}
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {

		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.choosebg, menu);
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
			View rootView = inflater.inflate(R.layout.fragment_choosebg,
					container, false);
			return rootView;
		}
	}

}
