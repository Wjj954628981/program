package com.example.simpleadapter;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.app.Activity;
import android.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.SimpleAdapter;
import android.widget.Spinner;
import android.widget.Toast;

public class MainActivity extends Activity {

	
	private Spinner spnStar;
	
	//����������Ϣ������
  	private int[] starImages = {R.drawable.star1, R.drawable.star2, R.drawable.star3, R.drawable.star4, 
  			  R.drawable.star5, R.drawable.star6, R.drawable.star7, R.drawable.star8,
  			  R.drawable.star9, R.drawable.star10, R.drawable.star11, R.drawable.star12};

  	private String[] starNames = {"������", "��ţ��", "˫����", "��з��", "ʨ����", "��Ů��", "�����", "��Ы��", "������", "Ħ����", "ˮƿ��", "˫����"};

  	private List<Map<String, Object>> dataList = new ArrayList<Map<String, Object>>();
	
	
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        spnStar = (Spinner) findViewById(R.id.spnStar);
		
		//��������б�
		fillDataList();
		
		//����1---����������
		
		//from����---Map�е�key��ֵ
		//int����	---С�����е������id
		SimpleAdapter adapter = new SimpleAdapter(this, dataList, R.layout.item_star,
												new String[]{"starImage", "starName"},
												new int[]{R.id.imgStar, R.id.txtStar});
		
		//����2---��������
		spnStar.setAdapter(adapter);
		
		//���¼�������
		spnStar.setOnItemSelectedListener(new OnItemSelectedListenerImpl());
        
        
        
        if (savedInstanceState == null) {
            getFragmentManager().beginTransaction()
                    .add(R.id.container, new PlaceholderFragment())
                    .commit();
        }
    }


private void fillDataList(){
		
		for(int i=0; i<starNames.length; i++){
			
			Map<String, Object> map = new HashMap<String, Object>();
			
			map.put("starImage", starImages[i]);
			map.put("starName", starNames[i]);
			
			dataList.add(map);
		}
	}
	
	//�����¼�������
	private class OnItemSelectedListenerImpl implements AdapterView.OnItemSelectedListener{
	
		@Override
		public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {

			Map<String, Object> map = (Map<String, Object>) parent.getItemAtPosition(position);
			
			String starName = (String) map.get("starName");
			
			Toast.makeText(getApplicationContext(), starName, Toast.LENGTH_SHORT).show();
		}
	
		@Override
		public void onNothingSelected(AdapterView<?> arg0) {
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
