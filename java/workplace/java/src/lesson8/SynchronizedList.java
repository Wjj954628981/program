package lesson8;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

class ListThread extends Thread{
	public List<Integer> l;

	public ListThread(List<Integer> l) {
		super();
		this.l = l;
		this.setDaemon(true);
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		//Iterator<Integer> it=l.iterator();
		while (true)
			
		{
			synchronized (l)
			{
			for(Integer i:l){
				System.out.print(i+' ');
				try {
					this.sleep(500);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			System.out.println();
			}
			
			
			/*while ( for)
		{
			System.out.print(it.next()+' ');
			try {
				this.sleep(50);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.println();
		}*/
			}
	}
	
}
class ChangeListThread extends Thread{
	public List<Integer> l;

	public ChangeListThread(List<Integer> l) {
		super();
		this.l = l;
		this.setDaemon(true);
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		while (true)
			{
			synchronized (l)
			{l.add(0,5);}
			try {
				this.sleep(50);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}}
		
		}
	}
	

public class SynchronizedList {
	
public static void main(String[] arg) throws Exception{
	List<Integer> l=new ArrayList<Integer>();
	//List<Integer> l=Collections.synchronizedList(new ArrayList<Integer>());
	Thread t1=new ChangeListThread(l);
	Thread t2=new ListThread(l);
	t1.start();
	t2.start();
	Thread.sleep(60000);
	
}


}
