package com.example.InternetDiary;

import android.app.Activity;
import android.app.AlertDialog.Builder;
import android.app.Dialog;
import android.app.Fragment;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.MyApp.MyApp;
import com.example.entity.User;
import com.example.task.ImageLoadTask;

public class MainActivity extends Activity {
	//声明组件
		private TextView txtUserInfo;
		private ImageView imgUserPhoto;
		
		private Dialog dlgExit;
		
		private String urlString = "http://10.0.2.2:8080/jspdemo/image/photo/";
		
		//private Handler handler;
		
		//private Bitmap bitmap;
		
		@Override
		protected void onCreate(Bundle savedInstanceState) {
			super.onCreate(savedInstanceState);
			setContentView(R.layout.activity_main);
			
			
			
			//获取组件
			txtUserInfo = (TextView) findViewById(R.id.txtUserInfo);
			imgUserPhoto = (ImageView) findViewById(R.id.imgUserPhoto);
			
			//显示用户信息
			showUserInfo();
			
			//创建退出对话框
			createDialog();	
			
			/*handler = new Handler(){
				@Override
				public void handleMessage(Message msg) {
					super.handleMessage(msg);
					
					if(msg.what==1){
						
						//显示用户头像
						imgUserPhoto.setImageBitmap(bitmap);
						
					}
				}
			};*/
			
		}

		//显示用户信息
		private void showUserInfo(){
			
			MyApp myApp = (MyApp) getApplication();
			
			User user = myApp.getUser();
			
			String userInfo = "欢迎" + user.getUsername() + "光临主页，您的积分是" + user.getScore() + "分";
			
			txtUserInfo.setText(userInfo);
			
			urlString += user.getPhoto();
			
			
			//启动加载图片的线程
			new ImageLoadTask(imgUserPhoto).execute(urlString);
			//new Thread(new ImageLoadRunner()).start();
		}
		
		/*//加载图片的线程
		private class ImageLoadRunner implements Runnable{

			@Override
			public void run() {
				
				try {
					URL url = new URL(urlString);
					
				    InputStream is = url.openStream();
					
				    bitmap = BitmapFactory.decodeStream(is);
				    
				    is.close();
				    
				    handler.sendEmptyMessage(1);
				    
				} catch (MalformedURLException e) {
					e.printStackTrace();
				} catch (IOException e) {
					e.printStackTrace();
				}
				
			}
			
		}*/
		
		//创建退出对话框
		private void createDialog(){
			
			Builder builder = new Builder(this);

			builder.setMessage("退出前是否删除用户登录信息");

			builder.setPositiveButton("是", new ExitOnClickImpl());
			builder.setNegativeButton("否", new ExitOnClickImpl());

			dlgExit = builder.create();	
		}
		
		public void exit(View v){
			
			//显示退出对话框
			dlgExit.show();
			
		}
		
		//退出对话框事件监听器
		private class ExitOnClickImpl implements DialogInterface.OnClickListener {

			@Override
			public void onClick(DialogInterface dialog, int id) {

				if (id == DialogInterface.BUTTON_POSITIVE) {

					//删除用户信息
					SharedPreferences sp = getSharedPreferences("UserInfo", MODE_PRIVATE);

					Editor editor = sp.edit();

					editor.remove("username");
					editor.remove("password");

					editor.commit();

				}
				
				System.exit(0);
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
			View rootView = inflater.inflate(R.layout.fragment_main, container,
					false);
			return rootView;
		}
	}

}
