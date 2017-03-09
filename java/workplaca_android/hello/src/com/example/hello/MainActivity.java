package com.example.hello;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity {

	//�������
	private EditText edtUsername;
	private Button btnHello, btnClear, btnExit;
	
    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        //��ȡ���
        edtUsername = (EditText) findViewById(R.id.edtUsername);
        
        btnHello = (Button) findViewById(R.id.btnHello);
        btnClear = (Button) findViewById(R.id.btnClear);
        btnExit = (Button) findViewById(R.id.btnExit);
        
        //�󶨵����¼�������
        btnHello.setOnClickListener(new OnClickListenerImpl());
        btnClear.setOnClickListener(new OnClickListenerImpl());
        btnExit.setOnClickListener(new OnClickListenerImpl());       
    }
    

     
    //���嵥���¼�������
    private class OnClickListenerImpl implements View.OnClickListener{

		@Override
		public void onClick(View v) {
			
			switch(v.getId()){
			
				case R.id.btnHello:
					
					//��ȡ�û���
			    	String username = edtUsername.getText().toString();
			    	
			    	System.out.println("username = " + username);
			    	
			    	Toast.makeText(getApplicationContext(), "��ã�" + username, Toast.LENGTH_SHORT).show();
			    	
			    	break;
			    	
				case R.id.btnClear:
					
					//����û���
			    	edtUsername.setText("");
			    	
			    	break;
			    	
				case R.id.btnExit:
					
					System.exit(0);  	
					
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
    
}
