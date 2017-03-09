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
import android.widget.EditText;

public class ResultActivity extends ActionBarActivity {

	
	private EditText txtResult ;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		
		
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_result);

		txtResult = (EditText)findViewById(R.id.txtResult);
		
		
		//获取发送的Intent
		Intent intent = this.getIntent();

		//获取Intent中的数据包
	 	Bundle bundle = intent.getExtras();

		//获取数据包中的数据		
		String height = bundle.getString("height");
		String weight = bundle.getString("weight");
		String operand = bundle.getString("operand");
		
		String result="";
    	double styled_weight = 0;
    	
    	double Rheight = Integer.parseInt(height);
    	double Rweight = Integer.parseInt(weight);
    	
    	if("我是男生".equals(operand)){
    		styled_weight = (Rheight - 80) * 0.7;
    		
    	}else{
    		styled_weight = (Rheight - 70) * 0.6;
    	}
    	
    	if(Rweight > styled_weight){
    		result = "您的标准体重为:"+ styled_weight +" ,您偏胖"+ (Rweight-styled_weight) +"公斤, 请注意锻炼身体,减掉赘肉!";
    	}else if (Rweight < styled_weight){
    		result = "您的标准体重为:"+ styled_weight +" ,您偏瘦"+ (styled_weight - Rweight) +"公斤, 请注意加强营养,多吃多喝!";
    	}else{
    		result = "您的标准体重为: "+ styled_weight +"公斤, 您的体重非常标准,继续保持下去吧!";
    	}
    	
    	txtResult.setText(result);

		
		if (savedInstanceState == null) {
			getSupportFragmentManager().beginTransaction()
					.add(R.id.container, new PlaceholderFragment()).commit();
		}
	}

	
	public void close(View v){
		finish();
	}
	
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {

		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.result, menu);
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
			View rootView = inflater.inflate(R.layout.fragment_result,
					container, false);
			return rootView;
		}
	}

}
