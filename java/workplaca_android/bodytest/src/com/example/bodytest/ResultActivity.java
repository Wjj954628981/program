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
		
		
		//��ȡ���͵�Intent
		Intent intent = this.getIntent();

		//��ȡIntent�е����ݰ�
	 	Bundle bundle = intent.getExtras();

		//��ȡ���ݰ��е�����		
		String height = bundle.getString("height");
		String weight = bundle.getString("weight");
		String operand = bundle.getString("operand");
		
		String result="";
    	double styled_weight = 0;
    	
    	double Rheight = Integer.parseInt(height);
    	double Rweight = Integer.parseInt(weight);
    	
    	if("��������".equals(operand)){
    		styled_weight = (Rheight - 80) * 0.7;
    		
    	}else{
    		styled_weight = (Rheight - 70) * 0.6;
    	}
    	
    	if(Rweight > styled_weight){
    		result = "���ı�׼����Ϊ:"+ styled_weight +" ,��ƫ��"+ (Rweight-styled_weight) +"����, ��ע���������,����׸��!";
    	}else if (Rweight < styled_weight){
    		result = "���ı�׼����Ϊ:"+ styled_weight +" ,��ƫ��"+ (styled_weight - Rweight) +"����, ��ע���ǿӪ��,��Զ��!";
    	}else{
    		result = "���ı�׼����Ϊ: "+ styled_weight +"����, �������طǳ���׼,����������ȥ��!";
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
