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

	//�������
	private ListView lvwDiary;

	//���������б�
	private List<Map<String, Object>> dataList = new ArrayList<Map<String, Object>>();  
	
	//����������
	//SimpleAdapter adapter;
	MyAdapter adapter;
	
	//��ǰ�ռǵ�λ��
	private int currentPosition;
	
	//�����Ի���
	private Dialog dlgExit, dlgDelete;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_diary_list);
		
		//��ȡ���
		lvwDiary = (ListView) findViewById(R.id.lvwDiary);
		
		//��������б�
		fillDataList(); 
		
		//����������
		//adapter = new SimpleAdapter(getApplicationContext(), dataList, R.layout.item_diary, 
		//							new String[]{"weather", "title", "content", "mood"},    
		//							new int[]{R.id.imgWeather, R.id.txtTitle, R.id.txtContent, R.id.rtbMood}); 
		
		adapter = new MyAdapter();
		
		//��������
		lvwDiary.setAdapter(adapter);
				
		//�󶨳����¼�������
		lvwDiary.setOnItemLongClickListener(new OnItemLongClickListenerImpl());
		
		//�����Ի���
		createDialog();
	}

	//��������б�
	private void fillDataList(){
	
		Map<String, Object> item1 = new HashMap<String, Object>();
		item1.put("weather", R.drawable.tq_cloud);
		item1.put("title", "�е���ѽ");
		item1.put("content", "���³���ͺ���");
		item1.put("mood", 4.0f);
		dataList.add(item1);
		
		Map<String, Object> item2 = new HashMap<String, Object>();
		item2.put("weather", R.drawable.tq_sun);
		item2.put("title", "̫����");
		item2.put("content", "�����Ƶô���������");
		item2.put("mood", 2.5f);
		dataList.add(item2);
		
		Map<String, Object> item3 = new HashMap<String, Object>();
		item3.put("weather", R.drawable.tq_yin);
		item3.put("title", "��������");
		item3.put("content", "�ٲ������Ҫ������");
		item3.put("mood", 5.0f);
		dataList.add(item3);			

		Map<String, Object> item4 = new HashMap<String, Object>();
		item4.put("weather", R.drawable.tq_rain);
		item4.put("title", "����������");
		item4.put("content", "����ɹ������ǵþ���");
		item4.put("mood", 1.0f);
		dataList.add(item4);	
		
		Map<String, Object> item5 = new HashMap<String, Object>();
		item5.put("weather", R.drawable.tq_snow);
		item5.put("title", "զ����ѩ��");
		item5.put("content", "����ү��磬̫��������");
		item5.put("mood", 1.5f);
		dataList.add(item5);
	}
	
	//�����Ի���
	private void createDialog() {
		
		Builder builder = new Builder(this);
		
		//����ͼ��
		builder.setIcon(R.drawable.question);
		
		//���ñ���
		builder.setTitle("�˳�ȷ�϶Ի���");
		
		//������Ϣ
		builder.setMessage("�Ƿ�ȷ���˳�����");
		
		//���ò�����ť
		builder.setPositiveButton("��", new OnClickListenerImpl());  
		builder.setNegativeButton("��", null);
		
		//����ȷ���˳��Ի���
		this.dlgExit = builder.create();
		
		
		
		//����ͼ��
		builder.setIcon(R.drawable.question);
		
		//���ñ���
		builder.setTitle("ɾ��ȷ�϶Ի���");
		
		//������Ϣ
		builder.setMessage("�Ƿ�ȷ��ɾ���ռ�");
		
		//���ò�����ť
		builder.setPositiveButton("��", new OnClickListenerImpl());  
		builder.setNegativeButton("��", null);
		
		//����ȷ��ɾ���Ի���
		this.dlgDelete = builder.create();
	}

	//����Ի���ť���¼�������
	private class OnClickListenerImpl implements DialogInterface.OnClickListener{

		@Override
		public void onClick(DialogInterface dialog, int id) {
			
			if(id==Dialog.BUTTON_POSITIVE){    //ȷ����ť
				
				if(dialog==dlgExit){   //�˳�����Ի���
					System.exit(0);					
				}
				
				if(dialog==dlgDelete){ //ɾ���ռǶԻ���
					
					//ɾ�������б��е�������
					dataList.remove(currentPosition);
					
					//֪ͨ�����������б��Ѿ��ı�
					adapter.notifyDataSetChanged();
					
					Toast.makeText(getApplicationContext(), "�ռ�ɾ���ɹ�", Toast.LENGTH_SHORT).show();
				}
			}
		}
	}
	
	//���峤���¼�������
	private class OnItemLongClickListenerImpl implements AdapterView.OnItemLongClickListener{

		@Override
		public boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id) {
			
			//��¼��ǰ�ռǵ�λ��
			currentPosition = position;
					
			//��ʾɾ��ȷ�϶Ի���
			dlgDelete.show();
			
			return true;
		}
		
	}
	
	//����ռ�
	public void add(View v){
		
		//������ͼ
		Intent intent = new Intent(DiaryListActivity.this, DiaryAddActivity.class);
		
		//�����ؽ���ķ�ʽ��ת����ӽ���
		startActivityForResult(intent, 1);
		
	}
	
	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		super.onActivityResult(requestCode, resultCode, data);
		
		if(requestCode == 1){    //�ռ���ӵ���ת
			
			if(resultCode == RESULT_OK){   //��Ӳ���
				
				//��ȡintent�е�����
				Bundle bundle = data.getExtras();
				
				//����µ�Map����
				Map<String, Object> item = new HashMap<String, Object>();
				item.put("weather", bundle.getInt("weather"));
				item.put("title", bundle.getString("title"));
				item.put("content", bundle.getString("content"));
				item.put("mood", bundle.getFloat("mood"));
				
				//���б�Ķ���������ռ�
				dataList.add(0, item);
				
				//֪ͨ���������ݸ���
				adapter.notifyDataSetChanged();
				
				Toast.makeText(getApplicationContext(), "�ռ���ӳɹ�", Toast.LENGTH_SHORT).show();
				
			}
		}
		
	}
	
	//�˳�����
	public void exit(View v){
		
		//��ʾȷ���˳��Ի���
		this.dlgExit.show();
	}
	
	//�Զ����������
	private class MyAdapter extends BaseAdapter{

		//���������� �ĸ���   ����
		@Override
		public int getCount() {
			return dataList.size();
		}

		//���ص�ǰ�������Ӧ��Map  ��ѡ
		@Override
		public Object getItem(int position) {
			return dataList.get(position);
		}

		//���ص�ǰ�������id  ��ѡ
		@Override
		public long getItemId(int position) {
			return position;
		}

		//���ص�ǰ�������Ӧ����ͼ    ����
		@Override
		public View getView(int position, View view, ViewGroup parent) {
			
			//��ȡview����
			view = View.inflate(getApplicationContext(), R.layout.item_diary, null);
			
			//��ȡ������
			Map<String, Object> map = dataList.get(position);
			
			//�����������view����
			
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
