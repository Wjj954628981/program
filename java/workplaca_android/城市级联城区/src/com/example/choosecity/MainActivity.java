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
			{"和平区","南开区","河西区"},
			{"东城区","西城区","海淀区"},
			{"黄埔区","杨浦区","普陀区"}			
	};
	
	//当前选中的城市名称
	private String cityName;
	
	
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        spnCity = (Spinner) findViewById(R.id.spnCity);
        spnDistrict = (Spinner) findViewById(R.id.spnDistrict);
        
      //绑定下拉列表框选中的事件监听器
  		this.spnCity.setOnItemSelectedListener(new OnItemSelectedListenerImpl());
  		this.spnDistrict.setOnItemSelectedListener(new OnItemSelectedListenerImpl());
        
        if (savedInstanceState == null) {
            getFragmentManager().beginTransaction()
                    .add(R.id.container, new PlaceholderFragment())
                    .commit();
        }
    }

    
  //定义城市下拉列表框选中的事件监听器
  	private class OnItemSelectedListenerImpl implements AdapterView.OnItemSelectedListener{
  	
  		@Override
  		public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
  		
  			switch(parent.getId()){
  			
  				case R.id.spnCity:
  				
  					//定义数组适配器
  					ArrayAdapter<String> adapter = new ArrayAdapter<String>(MainActivity.this, 
  							android.R.layout.simple_list_item_1, areaList[position]);
  					
  					//绑定数组适配器
  					spnDistrict.setAdapter(adapter);
  					
  					//获取城市的名称
  					cityName = parent.getItemAtPosition(position).toString();
  					
  					break;
  				
  				case R.id.spnDistrict:
  				
  					//获取城区的名称
  					String areaName = parent.getItemAtPosition(position).toString();
  					
  					//显示城市和城区的名称
  					String result = "您位于" + cityName + areaName;
  					
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
