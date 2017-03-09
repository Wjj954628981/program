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

	//�������
	private Spinner spnWeather;
	
	private EditText edtTitle, edtContent;
	
	private RatingBar rtbMood;
	
	//����������Ϣ������
	private int[] weatherImages = {R.drawable.tq_sun, R.drawable.tq_cloud, R.drawable.tq_yin, 
								   R.drawable.tq_rain, R.drawable.tq_snow};

	private String[] weatherNames = {"����", "����", "����", "����", "��ѩ"};

	//���������б�
	List<Map<String, Object>> dataList = new ArrayList<Map<String, Object>>();
	
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_diary_add);
		
		//��ȡ���
		this.spnWeather = (Spinner) findViewById(R.id.spnWeather);
		this.edtTitle = (EditText) findViewById(R.id.edtTitle);
		this.edtContent = (EditText) findViewById(R.id.edtContent);
		this.rtbMood = (RatingBar) findViewById(R.id.rtbMood);
		
		//��������б�
		fillDataList();
		
		//�����������
		//����1---context---�����ģ�this��getApplicationcontext()
		//����2---data---���õ�����---dataList
		//����3---resource---С������Դid---R.layout.star_item
		//����4---from---����Դ---��һ��String[]���飬���map��Key new String[]{"key1", "key2"}
		//����5---to---����Ŀ��---��һ��int[]���飬��Ų����ļ��е��������Դid new int[]{R.id.xxx, R.id.yyy}
		SimpleAdapter adapter = new SimpleAdapter(this, dataList, R.layout.item_weather,
				                                  new String[]{"weatherName", "weatherImage"}, 
			                                      new int[]{R.id.txtWeather, R.id.imgWeather}
		);
		
		//�󶨼�������
		this.spnWeather.setAdapter(adapter);
	}

	//��������б�
	private void fillDataList() {
		
		for(int i=0; i<weatherImages.length; i++){
			
			Map<String, Object> item = new HashMap<String, Object>();
			
			item.put("weatherName", weatherNames[i]);
			item.put("weatherImage", weatherImages[i]);
			
			dataList.add(item);			
		}
		
	}
	
	public void add(View v){
		
		//������ͼ
		Intent intent = this.getIntent();
		
		//���������bundle��
		Bundle bundle = new Bundle();
		
		//��ȡ�����б��ĵ�ǰ��Ŀ
		Map<String, Object> item = (Map<String, Object>) this.spnWeather.getSelectedItem();
		
		bundle.putInt("weather", Integer.parseInt(item.get("weatherImage").toString()));
		
		bundle.putString("title", this.edtTitle.getText().toString());
		
		bundle.putString("content", this.edtContent.getText().toString());
		
		bundle.putFloat("mood", this.rtbMood.getRating());
		
		intent.putExtras(bundle);
		
		//���ص���һ������
		this.setResult(RESULT_OK, intent);
		
		//�رյ�ǰ����
		this.finish();
		
	}
	
	public void close(View v){
		
		//�رյ�ǰ����
		this.finish();
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.diary_add, menu);
		return true;
	}

}
