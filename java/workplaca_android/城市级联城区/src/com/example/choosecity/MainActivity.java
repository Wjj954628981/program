package com.example.choosecity;

import android.app.Activity;
import android.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.Toast;

public class MainActivity extends Activity {

	
	private Spinner spnCity,spnDistrict;
	private String[][] areaList = new String[][]{
			{"��ƽ��","�Ͽ���","������"},
			{"������","������","������"},
			{"������","������","������"}			
	};
	
	//��ǰѡ�еĳ�������
	private String cityName;
	
	
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        spnCity = (Spinner) findViewById(R.id.spnCity);
        spnDistrict = (Spinner) findViewById(R.id.spnDistrict);
        
      //�������б��ѡ�е��¼�������
  		this.spnCity.setOnItemSelectedListener(new OnItemSelectedListenerImpl());
  		this.spnDistrict.setOnItemSelectedListener(new OnItemSelectedListenerImpl());
        
        if (savedInstanceState == null) {
            getFragmentManager().beginTransaction()
                    .add(R.id.container, new PlaceholderFragment())
                    .commit();
        }
    }

    
  //������������б��ѡ�е��¼�������
  	private class OnItemSelectedListenerImpl implements AdapterView.OnItemSelectedListener{
  	
  		@Override
  		public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
  		
  			switch(parent.getId()){
  			
  				case R.id.spnCity:
  				
  					//��������������
  					ArrayAdapter<String> adapter = new ArrayAdapter<String>(MainActivity.this, 
  							android.R.layout.simple_list_item_1, areaList[position]);
  					
  					//������������
  					spnDistrict.setAdapter(adapter);
  					
  					//��ȡ���е�����
  					cityName = parent.getItemAtPosition(position).toString();
  					
  					break;
  				
  				case R.id.spnDistrict:
  				
  					//��ȡ����������
  					String areaName = parent.getItemAtPosition(position).toString();
  					
  					//��ʾ���кͳ���������
  					String result = "��λ��" + cityName + areaName;
  					
  					Toast.makeText(getApplicationContext(), result, Toast.LENGTH_SHORT).show();
  					
  					break;
  			}
  				
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
