package com.etc.starbrowser;

import javax.security.auth.Destroyable;

import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.v4.app.Fragment;
import android.support.v7.app.ActionBarActivity;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends ActionBarActivity {

	private boolean flag = false;
	
	
	//定义下标
	private int i=0;
	
	//定义星座图片的数组
	private int[] starImages = {R.drawable.star1, R.drawable.star2, R.drawable.star3, R.drawable.star4, 
				  R.drawable.star5, R.drawable.star6, R.drawable.star7, R.drawable.star8,
				  R.drawable.star9, R.drawable.star10,  R.drawable.star11, R.drawable.star12};

	//定义星座名称的数组
	private String[] starNames = {"白羊座", "金牛座", "双子座", "巨蟹座", "狮子座", "处女座", "天秤座", "天蝎座", "射手座", "摩羯座", "水瓶座", "双鱼座"};
	
	
	//声明消息处理器
	private Handler handler;
	
	private ImageView img;
	private TextView txtName;
	private LinearLayout layout;
	private Button btnFirst,btnForward,btnNext,btnLast,btnRecovery,btnExit;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        
      

    	//实例化消息处理器
    	handler = new Handler(){
    		public void handleMessage(Message msg){
    			if(i < starNames.length - 1){
		  			i++;
		  		
		  		}else{
		  			i = 0;
		  		}
				//接收消息
				if(msg.what==1){
					select();
				}
				super.handleMessage(msg);
			
    		}
    	};
    	
    	

        
        img = (ImageView)findViewById(R.id.img);
        txtName = (TextView)findViewById(R.id.txtName);
        layout =(LinearLayout)findViewById(R.id.layout);
        
        btnFirst = (Button)findViewById(R.id.btnFirst);
        btnForward = (Button)findViewById(R.id.btnForward);
        btnNext = (Button)findViewById(R.id.btnNext);
        btnLast = (Button)findViewById(R.id.btnLast);
        btnRecovery = (Button)findViewById(R.id.btnRecovery);
        btnExit = (Button)findViewById(R.id.btnExit);
        
        btnFirst.setOnClickListener(new OnClickListenerImpl());
        btnForward.setOnClickListener(new OnClickListenerImpl());
        btnNext.setOnClickListener(new OnClickListenerImpl());
        btnLast.setOnClickListener(new OnClickListenerImpl());
        btnRecovery.setOnClickListener(new OnClickListenerImpl());
        btnExit.setOnClickListener(new OnClickListenerImpl());
        img.setOnClickListener(new OnClickListenerImpl());
        
        
        if (savedInstanceState == null) {
            getSupportFragmentManager().beginTransaction()
                    .add(R.id.container, new PlaceholderFragment())
                    .commit();
        }
        
        img.setOnLongClickListener(new View.OnLongClickListener() {
			
			@Override
			public boolean onLongClick(View v) {
				// TODO Auto-generated method stub
				layout.setBackgroundResource(starImages[i]);
				Toast.makeText(getApplicationContext(), "背景图设置成功", Toast.LENGTH_SHORT).show();
				return true;
			}
		});
    }

    private class ChangeRunner implements Runnable{

		@Override
		public void run() {	
			
			while(flag){
				
				//Message msg = new Message();
				//msg.arg1=flag;
				//handler.sendMessage(msg);
				//向主线程发送消息
				try {
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				handler.sendEmptyMessage(1);
			}
		}
	}
    
    
    
    private void select(){
    	img.setImageResource(starImages[i]);
    	txtName.setText(starNames[i]);
    }
    
    private class OnClickListenerImpl implements View.OnClickListener{

		@Override
		public void onClick(View v) {
			switch(v.getId()){
				case R.id.btnFirst:
					i=0;
			    	select();
			    	break;
				case R.id.btnForward:
					if(i>=1){
				    	i = i-1;
				    }else if(i==0){
				    	i = 0;
				    }
				    select();
			    	break;
				case R.id.btnNext:
					if(i<=10){
						i = i+1;
					}else if(i==11){
						i = 11;
					}
					select();
			    	break;
				case R.id.btnLast:
					i=11;
					select();
			    	break;
				case R.id.btnRecovery:
					v.setBackgroundResource(R.drawable.bg);
					break;
				case R.id.btnExit:
					System.exit(0);
					break;
				case R.id.img:
					/*if(i < starNames.length - 1){
			  			i++;
			  		}else{
			  			i = 0;
			  		}
					select(i);*/
					flag = !flag;
					if(flag){
						new Thread(new ChangeRunner()).start();
					}
			    	break;
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
