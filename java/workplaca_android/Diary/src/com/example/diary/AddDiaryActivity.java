package com.example.diary;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.app.Activity;
import android.app.Fragment;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.EditText;
import android.widget.SimpleAdapter;
import android.widget.Spinner;

public class AddDiaryActivity extends Activity {

	
	private Spinner spnWeather;
	
	private EditText edtTheme,edtContent;
	
	private int[] weatherImages ={R.drawable.tq_cloud,R.drawable.tq_sun,R.drawable.tq_yin,R.drawable.tq_rain,R.drawable.tq_snow};

  	private String[] weatherNames = {"多云", "晴朗", "阴天", "下雨", "下雪"};

  	private String weatherImage,theme,content;
  	
  	private List<Map<String, Object>> dataList = new ArrayList<Map<String, Object>>();
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_add);

		spnWeather = (Spinner) findViewById(R.id.spnWeather);
		edtTheme = (EditText) findViewById(R.id.edtTheme);
		edtContent = (EditText) findViewById(R.id.edtContent);
		
		
		
		
		
		//填充数据列表
		fillDataList();
		
		//步骤1---创建适配器
		
		//from数组---Map中的key的值
		//int数组	---小布局中的组件的id
		SimpleAdapter adapter = new SimpleAdapter(this, dataList, R.layout.adddiary,
												new String[]{"weatherImages", "weatherNames"},
												new int[]{R.id.weather, R.id.weathername});
		
		//步骤2---绑定适配器
		spnWeather.setAdapter(adapter);
		
		//绑定事件监听器
		spnWeather.setOnItemSelectedListener(new OnItemSelectedListenerImpl());
		
		
		if (savedInstanceState == null) {
			getFragmentManager().beginTransaction()
					.add(R.id.container, new PlaceholderFragment()).commit();
		}
	}

	public void add(View v){
		//获取发送的Intent
		Intent intent = this.getIntent();

		theme = edtTheme.getText().toString();
		content = edtContent.getText().toString();
		//传递返回值
		intent.putExtra("theme", theme);
		intent.putExtra("content", content);
		intent.putExtra("weatherImage", weatherImage);
		
		//携带intent返回发送界面
		setResult(RESULT_OK, intent);  //resultCode用于标识是否成功返回  RESULT_OK---成功   RESULT_CANCEL---取消
		
		//关闭当前界面
		finish();
	}
	
	
	public void close(View v){
		finish();
	}
	
	
	//填充数据列表
	private void fillDataList(){
		
		for(int i=0; i<weatherNames.length; i++){
			
			Map<String, Object> map = new HashMap<String, Object>();
			
			map.put("weatherImages", weatherImages[i]);
			map.put("weatherNames", weatherNames[i]);
			
			dataList.add(map);
		}
	}
	
	//定义事件监听器
	private class OnItemSelectedListenerImpl implements AdapterView.OnItemSelectedListener{
	
		@Override
		public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {

			Map<String, Object> map = (Map<String, Object>) parent.getItemAtPosition(position);
			
			weatherImage = (String) map.get("weatherImages");
		}

		@Override
		public void onNothingSelected(AdapterView<?> arg0) {
			// TODO Auto-generated method stub
			
		}
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {

		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.register, menu);
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
			View rootView = inflater.inflate(R.layout.fragment_add,
					container, false);
			return rootView;
		}
	}

}
