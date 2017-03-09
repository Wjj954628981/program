package com.example.diary;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.app.Activity;
import android.app.Dialog;
import android.app.Fragment;
import android.app.AlertDialog.Builder;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.SimpleAdapter;

public class DiaryActivity extends Activity {

	//定义控件
	private ListView lvwDiary;
	
	
	//定义天气图片数组
	private int[] weatherImages ={R.drawable.tq_cloud,R.drawable.tq_sun,R.drawable.tq_yin,R.drawable.tq_rain,R.drawable.tq_snow};
	
	//定义主题的数组
	private String[] themes = {"有点热呀","太热了","快下雨了","终于下雨了","咋又下雪了"};
	
	//定义内容的数组
	private String[] content = {"能下场雨就好了","天气闷得喘不过气来","再不下雨就要死人了","求雨成功，我们得救了","老天爷抽风，太不正常了"};
	
	
	private List<Map<String, Object>> diaryList = new ArrayList<Map<String, Object>>();
	
	//长击的元素
	Map<String, Object> map;
	
	
	private SimpleAdapter adapter;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        lvwDiary = (ListView) findViewById(R.id.lvwDiary);
        
        //填充数据列表
  		fillDataList();
  		
  		//步骤1---创建适配器
  		
  		//from数组---Map中的key的值
  		//int数组	---小布局中的组件的id
  		adapter = new SimpleAdapter(this, diaryList, R.layout.diary,
  												new String[]{"weatherImages", "themes","content"},
  												new int[]{R.id.imgWeather, R.id.txtTheme,R.id.txtContent});
  		
  		//步骤2---绑定适配器
  		lvwDiary.setAdapter(adapter);
  		
  		//adapter.notifyDataSetChanged();
  		
  		
  		//绑定事件监听器
  		lvwDiary.setOnItemLongClickListener(new OnItemLongClickListenerImpl());
  		
        
        
        if (savedInstanceState == null) {
            getFragmentManager().beginTransaction()
                    .add(R.id.container, new PlaceholderFragment())
                    .commit();
        }
    }


    @Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {

		if(resultCode == RESULT_OK){   //操作成功

			//接收返回值
			String theme = data.getStringExtra("theme");
			String content = data.getStringExtra("content");
			String weatherImage = data.getStringExtra("weatherImage");

			Map<String, Object> map = new HashMap<String, Object>();
  			
  			map.put("weatherImages", weatherImage);
  			map.put("themes", theme);
  			map.put("content", content);
  			
  			diaryList.add(map);
  			
            adapter.notifyDataSetChanged();  
			
		}
    }
    
    //跳转到注册
    public void addDiary(View v){
    	//创建Intent
    	Intent intent = new Intent(DiaryActivity.this, AddDiaryActivity.class);

    	//启动Activity	
        startActivityForResult(intent, 1);   //requestCode用于标识启动的是哪个Activity 
    }
    
    //退出程序
    public void exit(View v){
    	System.exit(0);
    }
  
    
    
   	//填充数据列表
  	private void fillDataList(){
  		
  		for(int i=0; i<weatherImages.length; i++){
  			
  			Map<String, Object> map = new HashMap<String, Object>();
  			
  			map.put("weatherImages", weatherImages[i]);
  			map.put("themes", themes[i]);
  			map.put("content", content[i]);
  			
  			diaryList.add(map);

  		}
  	}
    
  	//删除确认对话框
   /* private void createDialog(){
    	
    	Builder builder = new Builder(this);		

     	builder.setTitle("删除确认对话框");
     	builder.setMessage("是否确认删除日记");
     	builder.setIcon(R.drawable.question);

     	builder.setPositiveButton("是", new DeleteOnClickListenerImpl());  //绑定对话框按钮单击的监听器
     	builder.setNegativeButton("否", null);
     		
     	this.dlgDelete = builder.create();
    }*/
  	
  	
  	//定义对话框按钮单击的监听器
   	private class DeleteOnClickListenerImpl implements DialogInterface.OnClickListener{

   		@Override
   		public void onClick(DialogInterface dialog, int id) {

   			if(id==Dialog.BUTTON_POSITIVE){
   				//删除长击元素
   				diaryList.remove(map);
   				  
   	            adapter.notifyDataSetChanged();  
   				
   			}
   		}		
   	}
  	
   	//定义item长击事件监听器
  	private class OnItemLongClickListenerImpl implements AdapterView.OnItemLongClickListener{

	@Override
	public boolean onItemLongClick(AdapterView<?>  parent, View view, int position, long id) {
		
		//获取长击的元素
		map = (Map<String, Object>) parent.getItemAtPosition(position);
		
		Builder builder = new Builder(DiaryActivity.this);		

     	builder.setTitle("删除确认对话框");
     	builder.setMessage("是否确认删除日记");
     	builder.setIcon(R.drawable.question);

     	builder.setPositiveButton("是", new DeleteOnClickListenerImpl());  //绑定对话框按钮单击的监听器
     	builder.setNegativeButton("否", null);
     		
     	Dialog dlgDelete = builder.create();
		
		
		//弹出窗体
		dlgDelete.show();
		
		
		return false;
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
            View rootView = inflater.inflate(R.layout.fragment_main, container, false);
            return rootView;
        }
    }

}
