package com.example.calcultor;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

public class MainActivity extends Activity {

	//声明组件
	private EditText edtNum1, edtNum2, edtResult;
	
	private Spinner spnOperand;
	
	private char operand = '+';
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        //获取组件
        edtNum1 = (EditText) findViewById(R.id.edtNum1);
        edtNum2 = (EditText) findViewById(R.id.edtNum2);
        edtResult = (EditText) findViewById(R.id.edtResult);
        
        spnOperand = (Spinner) findViewById(R.id.spnOperand);
        
    }

    public void calc(View v){
    	
    	int num1 = Integer.parseInt(edtNum1.getText().toString());
    	int num2 = Integer.parseInt(edtNum2.getText().toString());
    	
    	//获取下拉框选择的操作符
    	operand = spnOperand.getSelectedItem().toString().charAt(0);
    	
    	int result = 0;
    	
    	switch(operand){
    	
    		case '+':
    			result = num1 + num2;
    			break;
    		case '-':
    			result = num1 - num2;
    			break;
    		case '*':
    			result = num1 * num2;
    			break;
    		case '/':
    			if(num2==0){
    				Toast.makeText(getApplicationContext(), "除数不能为零", Toast.LENGTH_SHORT).show();
    			}else{
    				result = num1 / num2;
    			}
    			break;
    	}
    	
    	edtResult.setText(result + "");
    	
    }

    public void clear(View v){
    	edtNum1.setText("");
    	edtNum2.setText("");
    }
    
    public void exit(View v){
    	System.exit(0);
    }
    
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }
    
}
