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
	
	//���������ִ�д���
	@Override
	protected Bitmap doInBackground(String... arg0) {
		
		try {
			
			//���ݷ��ʵ�ַ����URL����
			URL url = new URL(arg0[0]);
			
			//����URL�����ȡͼƬ��������
		    InputStream is = url.openStream();
			
		    //URL��������������Bitmap����
		    Bitmap bitmap = BitmapFactory.decodeStream(is);
		    
		    //�ر�������
		    is.close();
		    
		    return bitmap;
		    
		} catch (MalformedURLException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return null;
	}

	//����ĺ���ִ�д���
	@Override
	protected void onPostExecute(Bitmap result) {
		
		super.onPostExecute(result);
		
		//��ʾ�û�ͷ��
		imageView.setImageBitmap(result);
		
	}
}
