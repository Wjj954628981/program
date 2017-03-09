package com.example.spinneruseEdtandList;

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
import android.widget.EditText;
import android.widget.ListView;

public class MainActivity extends Activity {

	
	private EditText edtMain;
	private ListView lvwMain;
	private String[] cityName ={"天津市","北京市","上海市"};
	
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        edtMain = (EditText) findViewById(R.id.edtMain);
        lvwMain = (ListView) findViewById(R.id.lvwMain);
        
        edtMain.setText(cityName[0]);
        lvwMain.setAdapter(new ArrayAdapter<String>(this,
                android.R.layout.simple_list_item_1, cityName));

        lvwMain.setVisibility(View.GONE);
        
        //绑定事件监听器
        lvwMain.setOnItemClickListener(new OnItemClickListenerImpl());
        
        if (savedInstanceState == null) {
            getFragmentManager().beginTransaction()
                    .add(R.id.container, new PlaceholderFragment())
                    .commit();
        }
    }

    public void lvwShow(View v){
    	lvwMain.setVisibility(View.VISIBLE);
    }

    //定义事件监听器
  	private class OnItemClickListenerImpl implements AdapterView.OnItemClickListener{

  		@Override
  		public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
  	
  			String string =  (String) parent.getItemAtPosition(position);
  			edtMain.setText(string);
  			lvwMain.setVisibility(View.GONE);
  			
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
