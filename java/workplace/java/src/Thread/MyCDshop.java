package Thread;


import java.util.ArrayList;
import java.util.Date;
import java.util.Random;

class SaleCD
{
	int cdid;
	String name;
	int count;
	public SaleCD(int cdid, String name, int count) {
		super();
		this.cdid = cdid;
		this.name = name;
		this.count = count;
	}
	
}
class RentCD
{
	int cdid;
	String name;
	boolean isRent;

	public RentCD(int cdid, String name, boolean isRent) {
		super();
		this.cdid = cdid;
		this.name = name;
		this.isRent = isRent;
	}

}
class SaleThread extends Thread
{
	MyCDshop cdshop;

	public SaleThread(MyCDshop cdshop) {
		super();
		this.cdshop = cdshop;
	}
	public void run() {
		while(true)
		{
			try {
				sleep((int)(Math.random()*500));
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			int cdid=(int)(Math.random()*5)+1;
			int cdcount=(int)(Math.random()*5)+1;
			synchronized (cdshop.SaleList) {
				if (cdshop.saleCD(cdid, cdcount)) {
					System.out.println(new Date()+"成功销售" + cdid + "数量" + cdcount);
				} else {
					Random r = new Random();
					if (r.nextBoolean()) {
						System.out.println(new Date()+"数量不足，等候");
						cdshop.SaleList.notify();
						do
						{
							try {
								cdshop.SaleList.wait();
							} catch (InterruptedException e) {
								// TODO Auto-generated catch block
								e.printStackTrace();
							}
						}
						while(!cdshop.saleCD(cdid, cdcount));
						System.out.println(new Date()+"等候以后成功销售" + cdid + "数量" + cdcount);

					}
				}
			}
		}
	}
}
class GetInThread extends Thread
{
	MyCDshop cdshop;

	public GetInThread(MyCDshop cdshop) {
		super();
		this.cdshop = cdshop;
	}

	@Override
	public void run() {
		synchronized(cdshop.SaleList)
		{
			while (true) {
				try {
					cdshop.SaleList.wait(1000);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				cdshop.getIn();
				System.out.println(new Date()+"进货");
				cdshop.SaleList.notifyAll();
			}
		}
	}
	
}
class RentThread extends Thread
{
	MyCDshop cdshop;
	
	public RentThread(MyCDshop cdshop){
		super();
		this.cdshop = cdshop;
	}
	public void run(){
		while(true)
		{
			try {
				sleep((int)(Math.random()*300));
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			int cdid=(int)(Math.random()*5)+1;
			boolean isRent=false;
			synchronized (cdshop.RentList){
				if (cdshop.rentCD(cdid, isRent)) {
					System.out.println(new Date()+"成功出租" + cdid);
				}
				else{
					Random r=new Random();
					if(r.nextBoolean()){
						System.out.println(new Date()+"已经出租，等候");
						cdshop.RentList.notify();
						do{
							try {
								cdshop.RentList.wait();
							} catch (InterruptedException e) {
								// TODO Auto-generated catch block
								e.printStackTrace();
							}
						}
						while(!cdshop.rentCD(cdid, isRent));
						System.out.println(new Date()+"等候以后成功出租" + cdid);
					}
				}
			}
		}
	}
}

class ReturnThread extends Thread
{
	MyCDshop cdshop;

	public ReturnThread(MyCDshop cdshop) {
		super();
		this.cdshop = cdshop;
	}

	@Override
	public void run() {
		synchronized(cdshop.RentList)
		{
			while (true) {
				int renttime=(int)(Math.random()*100)+200;
				try {
					cdshop.RentList.wait(renttime);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
//				cdshop.Return(cdid);
//				System.out.println(new Date()+"还书"+cdid);
				cdshop.Return();
				System.out.println(new Date()+"还书");
				cdshop.RentList.notifyAll();
			}
		}
	}
}

class ControlThread extends Thread
{
	MyCDshop cdshop;

	public ControlThread(MyCDshop cdshop) {
		super();
		this.cdshop = cdshop;
		this.setDaemon(true);
	}
	public void run()
	{
		GetInThread gt=new GetInThread(cdshop);
		gt.setDaemon(true);
		gt.start();
		SaleThread st=new SaleThread(cdshop);
		st.start();
		
		RentThread rt=new RentThread(cdshop);
		rt.setDaemon(true);
		rt.start();	
		ReturnThread rtt=new ReturnThread(cdshop);
		rtt.start();
	}
	
}

public class MyCDshop {
	ArrayList<RentCD> RentList =new ArrayList<RentCD>();
	ArrayList<SaleCD> SaleList =new ArrayList<SaleCD>();
	public MyCDshop() {
		RentList.add(new RentCD(1,"rentcd1",false));
		RentList.add(new RentCD(2,"rentcd2",false));
		RentList.add(new RentCD(3,"rentcd3",false));
		RentList.add(new RentCD(4,"rentcd4",false));
		RentList.add(new RentCD(5,"rentcd5",false));
		SaleList.add(new SaleCD(1,"SaleCd1",10));
		SaleList.add(new SaleCD(2,"SaleCd2",10));
		SaleList.add(new SaleCD(3,"SaleCd3",10));
		SaleList.add(new SaleCD(4,"SaleCd4",10));
		SaleList.add(new SaleCD(5,"SaleCd5",10));		
		
	}
	public void getIn()
	{
		for(SaleCD sc:SaleList)
		{
			sc.count=10;
		}
	}
/*	public void Return(int cdid)
	{
		for(RentCD rc:RentList){
			if(rc.cdid==cdid){
				rc.isRent=false;
			}
		}
	}*/
	public void Return()
	{
		for(RentCD rc:RentList){
			if(rc.isRent){
				rc.isRent=false;
			}
		}
	}
	public boolean saleCD(int cdid,int count){
		for(SaleCD sc:SaleList)
		{
			if (sc.cdid==cdid)
			{
				if(sc.count>=count)
				{
					sc.count=sc.count-count;
					return true;
				}
				else
				{
					return false;
				}
				
			}
	    }
		return false;
	
	}
	public boolean rentCD(int cdid,boolean isRent){
		for(RentCD rc:RentList)
		{
			if(rc.cdid==cdid)
			{
				if(!rc.isRent)
				{
					rc.isRent=true;
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		return false;
	}
	public static void main(String[] arg)
	{
		
		ControlThread ct=new ControlThread(new MyCDshop());
		ct.start();
		try {
			Thread.sleep(120000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
