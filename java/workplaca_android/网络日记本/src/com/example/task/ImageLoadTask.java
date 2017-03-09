package com.example.task;

import java.io.IOException;
import java.io.InputStream;
import java.net.MalformedURLException;
import java.net.URL;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.widget.ImageView;

public class ImageLoadTask extends AsyncTask<String, Void, Bitmap> {

	private ImageView imageView;
	
	public ImageLoadTask(ImageView imageView){
		this.imageView = imageView;
	}
	
	//任务的主体执行代码
	@Override
	protected Bitmap doInBackground(String... arg0) {
		
		try {
			
			//根据访问地址构造URL对象
			URL url = new URL(arg0[0]);
			
			//根据URL对象获取图片的输入流
		    InputStream is = url.openStream();
			
		    //URL对象输入流构造Bitmap对象
		    Bitmap bitmap = BitmapFactory.decodeStream(is);
		    
		    //关闭输入流
		    is.close();
		    
		    return bitmap;
		    
		} catch (MalformedURLException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return null;
	}

	//任务的后续执行代码
	@Override
	protected void onPostExecute(Bitmap result) {
		
		super.onPostExecute(result);
		
		//显示用户头像
		imageView.setImageBitmap(result);
		
	}
}
