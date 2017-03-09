package com.example.login;

import android.app.AlertDialog.Builder;
import android.app.Dialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v7.app.ActionBarActivity;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends ActionBarActivity {

	private EditText edtUsername, edtPasswowrd;
	
	private Dialog dlgExit;
	

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        

    	edtUsername = (EditText) findViewById(R.id.edtUsername);
        edtPasswowrd = (EditText) findViewById(R.id.edtPassword);
    	
        createDialog();
        
        if (savedInstanceState == null) {
            getSupportFragmentManager().beginTransaction()
                    .add(R.id.container, new PlaceholderFragment())
                    .commit();
        }
    }

    
    private void createDialog(){
    	
    	Builder builder = new Builder(this);		

     	builder.setTitle("退出确认框");
     	builder.setMessage("是否确认退出程序");
     	builder.setIcon(R.drawable.question);

     	builder.setPositiveButton("是", new ExitOnClickListenerImpl());  //绑定对话框按钮单击的监听器
     	builder.setNegativeButton("否", null);
     		
     	this.dlgExit = builder.create();
    }
	public void login(View v){
    	
    	String username = edtUsername.getText().toString();
    	String passwowrd = edtPasswowrd.getText().toString();
    	
    	if("etc".equals(username) && "123".equals(passwowrd)){
    		Toast.makeText(getApplicationContext(), "登录成功", Toast.LENGTH_SHORT).show();
    	}else{
    		Toast.makeText(getApplicationContext(), "登录失败", Toast.LENGTH_SHORT).show();
    	}
    	
    }
    
    public void exit(View v){
    	
    	this.dlgExit.show();
    }
    
    //定义对话框按钮单击的监听器
	private class ExitOnClickListenerImpl implements DialogInterface.OnClickListener{

		@Override
		public void onClick(DialogInterface dialog, int id) {

			if(id==Dialog.BUTTON_POSITIVE){
				System.exit(0);
			}
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
