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

	//����ؼ�
	private ListView lvwDiary;
	
	
	//��������ͼƬ����
	private int[] weatherImages ={R.drawable.tq_cloud,R.drawable.tq_sun,R.drawable.tq_yin,R.drawable.tq_rain,R.drawable.tq_snow};
	
	//�������������
	private String[] themes = {"�е���ѽ","̫����","��������","����������","զ����ѩ��"};
	
	//�������ݵ�����
	private String[] content = {"���³���ͺ���","�����Ƶô���������","�ٲ������Ҫ������","����ɹ������ǵþ���","����ү��磬̫��������"};
	
	
	private List<Map<String, Object>> diaryList = new ArrayList<Map<String, Object>>();
	
	//������Ԫ��
	Map<String, Object> map;
	
	
	private SimpleAdapter adapter;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        lvwDiary = (ListView) findViewById(R.id.lvwDiary);
        
        //��������б�
  		fillDataList();
  		
  		//����1---����������
  		
  		//from����---Map�е�key��ֵ
  		//int����	---С�����е������id
  		adapter = new SimpleAdapter(this, diaryList, R.layout.diary,
  												new String[]{"weatherImages", "themes","content"},
  												new int[]{R.id.imgWeather, R.id.txtTheme,R.id.txtContent});
  		
  		//����2---��������
  		lvwDiary.setAdapter(adapter);
  		
  		//adapter.notifyDataSetChanged();
  		
  		
  		//���¼�������
  		lvwDiary.setOnItemLongClickListener(new OnItemLongClickListenerImpl());
  		
        
        
        if (savedInstanceState == null) {
            getFragmentManager().beginTransaction()
                    .add(R.id.container, new PlaceholderFragment())
                    .commit();
        }
    }


    @Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {

		if(resultCode == RESULT_OK){   //�����ɹ�

			//���շ���ֵ
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
    
    //��ת��ע��
    public void addDiary(View v){
    	//����Intent
    	Intent intent = new Intent(DiaryActivity.this, AddDiaryActivity.class);

    	//����Activity	
        startActivityForResult(intent, 1);   //requestCode���ڱ�ʶ���������ĸ�Activity 
    }
    
    //�˳�����
    public void exit(View v){
    	System.exit(0);
    }
  
    
    
   	//��������б�
  	private void fillDataList(){
  		
  		for(int i=0; i<weatherImages.length; i++){
  			
  			Map<String, Object> map = new HashMap<String, Object>();
  			
  			map.put("weatherImages", weatherImages[i]);
  			map.put("themes", themes[i]);
  			map.put("content", content[i]);
  			
  			diaryList.add(map);

  		}
  	}
    
  	//ɾ��ȷ�϶Ի���
   /* private void createDialog(){
    	
    	Builder builder = new Builder(this);		

     	builder.setTitle("ɾ��ȷ�϶Ի���");
     	builder.setMessage("�Ƿ�ȷ��ɾ���ռ�");
     	builder.setIcon(R.drawable.question);

     	builder.setPositiveButton("��", new DeleteOnClickListenerImpl());  //�󶨶Ի���ť�����ļ�����
     	builder.setNegativeButton("��", null);
     		
     	this.dlgDelete = builder.create();
    }*/
  	
  	
  	//����Ի���ť�����ļ�����
   	private class DeleteOnClickListenerImpl implements DialogInterface.OnClickListener{

   		@Override
   		public void onClick(DialogInterface dialog, int id) {

   			if(id==Dialog.BUTTON_POSITIVE){
   				//ɾ������Ԫ��
   				diaryList.remove(map);
   				  
   	            adapter.notifyDataSetChanged();  
   				
   			}
   		}		
   	}
  	
   	//����item�����¼�������
  	private class OnItemLongClickListenerImpl implements AdapterView.OnItemLongClickListener{

	@Override
	public boolean onItemLongClick(AdapterView<?>  parent, View view, int position, long id) {
		
		//��ȡ������Ԫ��
		map = (Map<String, Object>) parent.getItemAtPosition(position);
		
		Builder builder = new Builder(DiaryActivity.this);		

     	builder.setTitle("ɾ��ȷ�϶Ի���");
     	builder.setMessage("�Ƿ�ȷ��ɾ���ռ�");
     	builder.setIcon(R.drawable.question);

     	builder.setPositiveButton("��", new DeleteOnClickListenerImpl());  //�󶨶Ի���ť�����ļ�����
     	builder.setNegativeButton("��", null);
     		
     	Dialog dlgDelete = builder.create();
		
		
		//��������
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
