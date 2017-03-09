package com.example.diary2;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.app.Activity;
import android.app.AlertDialog.Builder;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.RatingBar;
import android.widget.TextView;
import android.widget.Toast;

public class DiaryListActivity extends Activity {

	//声明组件
	private ListView lvwDiary;

	//定义数据列表
	private List<Map<String, Object>> dataList = new ArrayList<Map<String, Object>>();  
	
	//声明适配器
	//SimpleAdapter adapter;
	MyAdapter adapter;
	
	//当前日记的位置
	private int currentPosition;
	
	//声明对话框
	private Dialog dlgExit, dlgDelete;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_diary_list);
		
		//获取组件
		lvwDiary = (ListView) findViewById(R.id.lvwDiary);
		
		//填充数据列表
		fillDataList(); 
		
		//定义适配器
		//adapter = new SimpleAdapter(getApplicationContext(), dataList, R.layout.item_diary, 
		//							new String[]{"weather", "title", "content", "mood"},    
		//							new int[]{R.id.imgWeather, R.id.txtTitle, R.id.txtContent, R.id.rtbMood}); 
		
		adapter = new MyAdapter();
		
		//绑定适配器
		lvwDiary.setAdapter(adapter);
				
		//绑定长击事件监听器
		lvwDiary.setOnItemLongClickListener(new OnItemLongClickListenerImpl());
		
		//创建对话框
		createDialog();
	}

	//填充数据列表
	private void fillDataList(){
	
		Map<String, Object> item1 = new HashMap<String, Object>();
		item1.put("weather", R.drawable.tq_cloud);
		item1.put("title", "有点热呀");
		item1.put("content", "能下场雨就好了");
		item1.put("mood", 4.0f);
		dataList.add(item1);
		
		Map<String, Object> item2 = new HashMap<String, Object>();
		item2.put("weather", R.drawable.tq_sun);
		item2.put("title", "太热了");
		item2.put("content", "天气闷得喘不过气来");
		item2.put("mood", 2.5f);
		dataList.add(item2);
		
		Map<String, Object> item3 = new HashMap<String, Object>();
		item3.put("weather", R.drawable.tq_yin);
		item3.put("title", "快下雨了");
		item3.put("content", "再不下雨就要死人了");
		item3.put("mood", 5.0f);
		dataList.add(item3);			

		Map<String, Object> item4 = new HashMap<String, Object>();
		item4.put("weather", R.drawable.tq_rain);
		item4.put("title", "终于下雨啦");
		item4.put("content", "求雨成功，我们得救了");
		item4.put("mood", 1.0f);
		dataList.add(item4);	
		
		Map<String, Object> item5 = new HashMap<String, Object>();
		item5.put("weather", R.drawable.tq_snow);
		item5.put("title", "咋又下雪了");
		item5.put("content", "老天爷抽风，太不正常了");
		item5.put("mood", 1.5f);
		dataList.add(item5);
	}
	
	//创建对话框
	private void createDialog() {
		
		Builder builder = new Builder(this);
		
		//设置图标
		builder.setIcon(R.drawable.question);
		
		//设置标题
		builder.setTitle("退出确认对话框");
		
		//设置信息
		builder.setMessage("是否确认退出程序");
		
		//设置操作按钮
		builder.setPositiveButton("是", new OnClickListenerImpl());  
		builder.setNegativeButton("否", null);
		
		//创建确认退出对话框
		this.dlgExit = builder.create();
		
		
		
		//设置图标
		builder.setIcon(R.drawable.question);
		
		//设置标题
		builder.setTitle("删除确认对话框");
		
		//设置信息
		builder.setMessage("是否确认删除日记");
		
		//设置操作按钮
		builder.setPositiveButton("是", new OnClickListenerImpl());  
		builder.setNegativeButton("否", null);
		
		//创建确认删除对话框
		this.dlgDelete = builder.create();
	}

	//定义对话框按钮的事件监听器
	private class OnClickListenerImpl implements DialogInterface.OnClickListener{

		@Override
		public void onClick(DialogInterface dialog, int id) {
			
			if(id==Dialog.BUTTON_POSITIVE){    //确定按钮
				
				if(dialog==dlgExit){   //退出程序对话框
					System.exit(0);					
				}
				
				if(dialog==dlgDelete){ //删除日记对话框
					
					//删除数据列表中的数据项
					dataList.remove(currentPosition);
					
					//通知适配器数据列表已经改变
					adapter.notifyDataSetChanged();
					
					Toast.makeText(getApplicationContext(), "日记删除成功", Toast.LENGTH_SHORT).show();
				}
			}
		}
	}
	
	//定义长击事件监听器
	private class OnItemLongClickListenerImpl implements AdapterView.OnItemLongClickListener{

		@Override
		public boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id) {
			
			//记录当前日记的位置
			currentPosition = position;
					
			//显示删除确认对话框
			dlgDelete.show();
			
			return true;
		}
		
	}
	
	//添加日记
	public void add(View v){
		
		//创建意图
		Intent intent = new Intent(DiaryListActivity.this, DiaryAddActivity.class);
		
		//带返回结果的方式跳转到添加界面
		startActivityForResult(intent, 1);
		
	}
	
	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		super.onActivityResult(requestCode, resultCode, data);
		
		if(requestCode == 1){    //日记添加的跳转
			
			if(resultCode == RESULT_OK){   //添加操作
				
				//获取intent中的数据
				Bundle bundle = data.getExtras();
				
				//添加新的Map集合
				Map<String, Object> item = new HashMap<String, Object>();
				item.put("weather", bundle.getInt("weather"));
				item.put("title", bundle.getString("title"));
				item.put("content", bundle.getString("content"));
				item.put("mood", bundle.getFloat("mood"));
				
				//在列表的顶部添加新日记
				dataList.add(0, item);
				
				//通知适配器数据更新
				adapter.notifyDataSetChanged();
				
				Toast.makeText(getApplicationContext(), "日记添加成功", Toast.LENGTH_SHORT).show();
				
			}
		}
		
	}
	
	//退出程序
	public void exit(View v){
		
		//显示确认退出对话框
		this.dlgExit.show();
	}
	
	//自定义的适配器
	private class MyAdapter extends BaseAdapter{

		//返回数据项 的个数   必须
		@Override
		public int getCount() {
			return dataList.size();
		}

		//返回当前数据项对应的Map  可选
		@Override
		public Object getItem(int position) {
			return dataList.get(position);
		}

		//返回当前数据项的id  可选
		@Override
		public long getItemId(int position) {
			return position;
		}

		//返回当前数据项对应的视图    必须
		@Override
		public View getView(int position, View view, ViewGroup parent) {
			
			//获取view对象
			view = View.inflate(getApplicationContext(), R.layout.item_diary, null);
			
			//获取数据项
			Map<String, Object> map = dataList.get(position);
			
			//根据数据填充view对象
			
			ImageView imgWeather = (ImageView) view.findViewById(R.id.imgWeather);
			imgWeather.setImageResource(Integer.parseInt(map.get("weather").toString()));
			
			RatingBar rtbMood = (RatingBar) view.findViewById(R.id.rtbMood);
			rtbMood.setRating(Float.parseFloat(map.get("mood").toString()));
			
			TextView txtTitle = (TextView) view.findViewById(R.id.txtTitle);
			txtTitle.setText(map.get("title").toString());
			
			TextView txtContent = (TextView) view.findViewById(R.id.txtContent);
			txtContent.setText(map.get("content").toString());
			
			return view;
		}
		
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.diary_list, menu);
		return true;
	}

}
