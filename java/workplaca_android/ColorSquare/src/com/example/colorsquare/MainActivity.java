package com.example.colorsquare;

import android.graphics.Color;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v7.app.ActionBarActivity;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.SeekBar.OnSeekBarChangeListener;
import android.widget.TextView;

public class MainActivity extends ActionBarActivity {

	 private SeekBar seekBarRed,seekBarGreen,seekBarBlue;

	 private TextView txtColorsq;
	 
	 private Button rdoRed,rdoGreen,rdoBlue;
	 
	 private int red=0,green=0,blue=0;
	
	
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txtColorsq=(TextView)findViewById(R.id.txtColorsq);
        
        seekBarRed=(SeekBar)findViewById(R.id.seekBarRed);
        seekBarGreen=(SeekBar)findViewById(R.id.seekBarGreen);
        seekBarBlue=(SeekBar)findViewById(R.id.seekBarBlue);
        
        rdoRed=(Button)findViewById(R.id.rdoRed);
        rdoGreen=(Button)findViewById(R.id.rdoGreen);
        rdoBlue=(Button)findViewById(R.id.rdoBlue);
        
        seekBarRed.setOnSeekBarChangeListener(new OnSeekBarChangeListenerImpl());
        seekBarGreen.setOnSeekBarChangeListener(new OnSeekBarChangeListenerImpl());
        seekBarBlue.setOnSeekBarChangeListener(new OnSeekBarChangeListenerImpl());
        
        
        rdoRed.setText("��="+red);
        rdoGreen.setText("��="+green);
        rdoBlue.setText("��="+blue);
		txtColorsq.setBackgroundColor(Color.rgb(red, green, blue));

        /*
        //����Intent
    	Intent intent = new Intent(MainActivity.this, HandleActivity.class);
    	//�������ݰ� 
    	Bundle bundle = new Bundle();

    	//������ݰ� 
    	bundle.putInt("red", red); 
    	bundle.putInt("green", green); 
    	bundle.putInt("blue", blue);

    	//�������ݰ�
    	intent.putExtras(bundle);

    	//����Activity
    	 startActivityForResult(intent, 1); */
        
       /* seekBarRed.setOnSeekBarChangeListener(new OnSeekBarChangeListener(){
			@Override
			public void onProgressChanged(SeekBar arg0, int arg1, boolean arg2) {
				// TODO Auto-generated method stub
				red = 255 * arg1 / 100;
				rdoRed.setText("��="+red);
				txtColorsq.setBackgroundColor(Color.rgb(red, green, blue));
			}

			@Override
			public void onStartTrackingTouch(SeekBar arg0) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void onStopTrackingTouch(SeekBar arg0) {
				// TODO Auto-generated method stub
				rdoRed.setText("��="+red);
				
			}
        });
        seekBarGreen.setOnSeekBarChangeListener(new OnSeekBarChangeListener(){
			@Override
			public void onProgressChanged(SeekBar arg0, int arg1, boolean arg2) {
				// TODO Auto-generated method stub
				green = 255 * arg1 / 100;
				rdoGreen.setText("��="+green);
				txtColorsq.setBackgroundColor(Color.rgb(red, green, blue));
			}

			@Override
			public void onStartTrackingTouch(SeekBar arg0) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void onStopTrackingTouch(SeekBar arg0) {
				// TODO Auto-generated method stub
				rdoGreen.setText("��="+green);
				
			}
        });
        seekBarBlue.setOnSeekBarChangeListener(new OnSeekBarChangeListener(){
			@Override
			public void onProgressChanged(SeekBar arg0, int arg1, boolean arg2) {
				// TODO Auto-generated method stub
				blue = 255 * arg1 / 100;
				rdoBlue.setText("��="+blue);
				txtColorsq.setBackgroundColor(Color.rgb(red, green, blue));
			}

			@Override
			public void onStartTrackingTouch(SeekBar arg0) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void onStopTrackingTouch(SeekBar arg0) {
				// TODO Auto-generated method stub
				rdoBlue.setText("��="+blue);
				
			}
        });*/
        
        
        
        if (savedInstanceState == null) {
            getSupportFragmentManager().beginTransaction()
                    .add(R.id.container, new PlaceholderFragment())
                    .commit();
        }
    }


    private class OnSeekBarChangeListenerImpl implements OnSeekBarChangeListener{

    	//�϶������ȸı��ʱ�����
		@Override
		public void onProgressChanged(SeekBar arg0, int arg1, boolean arg2) {
			// TODO Auto-generated method stub
			red = seekBarRed.getProgress();
			green = seekBarGreen.getProgress();
			blue = seekBarBlue.getProgress();
			
		}

		//�϶�����ʼ�϶���ʱ�����
		@Override
		public void onStartTrackingTouch(SeekBar arg0) {
			// TODO Auto-generated method stub
			
		}

		//�϶���ֹͣ�϶���ʱ�����
		@Override
		public void onStopTrackingTouch(SeekBar arg0) {
			// TODO Auto-generated method stub
			
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
