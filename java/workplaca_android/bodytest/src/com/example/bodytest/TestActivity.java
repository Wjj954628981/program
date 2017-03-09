package com.example.bodytest;

import java.util.Date;

import android.app.AlertDialog.Builder;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v7.app.ActionBarActivity;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.RadioGroup;
//import android.widget.RadioGroup;
//import android.widget.TextView;
import android.widget.Toast;

public class TestActivity extends ActionBarActivity {

	
	private Date backTime;
	
	private RadioGroup genderGroup ;
	private EditText edtHeight ;
	private EditText edtWeight ;
	//private EditText txtResult ;
	
	private LinearLayout layout;
	
	private Dialog dlgExit;

	
	//private int gender = 0;
				
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        genderGroup = (RadioGroup)findViewById(R.id.genderGroup);
        edtHeight = (EditText)findViewById(R.id.edtHeight);
        edtWeight = (EditText)findViewById(R.id.edtWeight);
        //txtResult = (EditText)findViewById(R.id.txtResult);
        
        createDialog();
        
        
        layout =(LinearLayout) findViewById(R.id.Layout);
        
        
        //设置透明度
        //View v =findViewById(R.id.Layout);
	    //v.getBackground().setAlpha(150);
        

	    /*genderGroup.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
			public void onCheckedChanged(RadioGroup group, int checkedId) {
				if(femaleButton.getId() == checkedId){
					gender = 1;
				}else {
					gender = 0;
				}
			}
	    });*/
        
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
    
    
    public void test(View v){
    	//获得数据
    	
    	//获取当前选择的单项钮
    	RadioButton rdoOperand = (RadioButton) findViewById(genderGroup.getCheckedRadioButtonId());
    	
    	//获取当前单项钮的字符  
    	String operand = rdoOperand.getText().toString();
    	
    	String height = edtHeight.getText().toString();
    	String weight = edtWeight.getText().toString();


    	
    	
    	//提交数据
    	
    	//创建Intent
    	Intent intent = new Intent(TestActivity.this, ResultActivity.class);

    	//创建数据包 
    	Bundle bundle = new Bundle();

    	//填充数据包 
    	bundle.putString("Height", height); 
    	bundle.putString("Weight", weight); 
    	bundle.putString("operand", operand); 

    	//发送数据包
    	intent.putExtras(bundle);

    	//启动Activity
    	startActivity(intent);
  	
    }
    
    public void exit(View v){
    	this.dlgExit.show();
    }
    
    //获得参数并设置背景
    public void changebg(View v){

    	//创建Intent
    	Intent intent = new Intent(TestActivity.this, ChoosebgActivity.class);

    	//启动Activity	
        startActivityForResult(intent, 1);   //requestCode用于标识启动的是哪个Activity 

    	
    }
    
    
    @Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {

		if(resultCode == RESULT_OK){   //操作成功
			//接收返回值
			int bg = data.getIntExtra("bg",0);
			switch(bg){
			case 1:
				layout.setBackgroundResource(R.drawable.bg1);
				break;
			case 2:
				layout.setBackgroundResource(R.drawable.bg2);
				break;
			case 3:
				layout.setBackgroundResource(R.drawable.bg3);
				break;
			}
		}
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

    
    
    @SuppressWarnings("null")
	@Override
	public void onBackPressed() {
		
    	Date currentTime = null;
    	if(backTime==null||currentTime.getTime()-backTime.getTime()>2000){
    		backTime = currentTime;
    		Toast.makeText(getApplicationContext(), "再次点击返回键退出程序", Toast.LENGTH_SHORT).show();
    	}
		super.onBackPressed();
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
