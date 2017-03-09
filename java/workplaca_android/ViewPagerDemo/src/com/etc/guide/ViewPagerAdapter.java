package com.etc.guide;

import java.util.List;

import android.content.Context;
import android.support.v4.view.PagerAdapter;
import android.support.v4.view.ViewPager;
import android.view.View;

public class ViewPagerAdapter extends PagerAdapter{

	private List<View> views;
	private Context context;
	
	public ViewPagerAdapter(List<View> views, Context context) {
		this.views = views;
		this.context = context;
	}
	
	public void destroyItem(View container, int position, Object object) {
		((ViewPager) container).removeView(views.get(position));
	}
	
	public Object instantiateItem(View container, int position) {
		((ViewPager) container).addView(views.get(position));
		return views.get(position);
	}
	
	public int getCount() {
		return views.size();
	}

	public boolean isViewFromObject(View arg0, Object arg1) {
		return (arg0 == arg1);
	}

}
