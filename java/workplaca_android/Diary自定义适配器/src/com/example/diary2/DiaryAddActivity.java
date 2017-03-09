package com.example.diary2;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.EditText;
import android.widget.RatingBar;
import android.widget.SimpleAdapter;
import android.widget.Spinner;

public class DiaryAddActivity extends Activity {

	//声明组件
	private Spinner spnWeather;
	
	private EditText edtTitle, edtContent;
	
	private RatingBar rtbMood;
	
	//定义天气信息的数组
	private int[] weatherImages = {R.drawable.tq_sun, R.drawable.tq_cloud, R.drawable.tq_yin, 
								   R.drawable.tq_rain, R.drawable.tq_snow};

	private String[] weatherNames = {"晴朗", "多云", "阴天", "下雨", "下雪"};

	//定义数据列表
	List<Map<String, Object>> dataList = new ArrayList<Map<String, Object>>();
	
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_diary_add);
		
		//获取组件
		this.spnWeather = (Spinner) findViewById(R.id.spnWeather);
		this.edtTitle = (EditText) findViewById(R.id.edtTitle);
		this.edtContent = (EditText) findViewById(R.id.edtContent);
		this.rtbMood = (RatingBar) findViewById(R.id.rtbMood);
		
		//填充数据列表
		fillDataList();
		
		//定义简单适配器
		//参数1---context---上下文：this或getApplicationcontext()
		//参数2---data---填充好的数据---dataList
		//参数3---resource---小布局资源id---R.layout.star_item
		//参数4---from---数据源---是一个String[]数组，存放map的Key new String[]{"key1", "key2"}
		//参数5---to---数据目的---是一个int[]数组，存放布局文件中的组件的资源id new int[]{R.id.xxx, R.id.yyy}
		SimpleAdapter adapter = new SimpleAdapter(this, dataList, R.layout.item_weather,
				                                  new String[]{"weatherName", "weatherImage"}, 
			                                      new int[]{R.id.txtWeather, R.id.imgWeather}
		);
		
		//绑定简单适配器
		this.spnWeather.setAdapter(adapter);
	}

	//填充数据列表
	private void fillDataList() {
		
		for(int i=0; i<weatherImages.length; i++){
			
			Map<String, Object> item = new HashMap<String, Object>();
			
			item.put("weatherName", weatherNames[i]);
			item.put("weatherImage", weatherImages[i]);
			
			dataList.add(item);			
		}
		
	}
	
	public void add(View v){
		
		//接收意图
		Intent intent = this.getIntent();
		
		//创建并填充bundle包
		Bundle bundle = new Bundle();
		
		//获取下拉列表框的当前条目
		Map<String, Object> item = (Map<String, Object>) this.spnWeather.getSelectedItem();
		
		bundle.putInt("weather", Integer.parseInt(item.get("weatherImage").toString()));
		
		bundle.putString("title", this.edtTitle.getText().toString());
		
		bundle.putString("content", this.edtContent.getText().toString());
		
		bundle.putFloat("mood", this.rtbMood.getRating());
		
		intent.putExtras(bundle);
		
		//返回到上一个界面
		this.setResult(RESULT_OK, intent);
		
		//关闭当前界面
		this.finish();
		
	}
	
	public void close(View v){
		
		//关闭当前界面
		this.finish();
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.diary_add, menu);
		return true;
	}

}
