package game;
import java.util.Scanner;
public class Game {
	public int check(int[] a,int[] b){
		int count=0;
		for(int i=0;i<a.length;i++){
			if(a[i]!=b[i])
				count++;
		}
		return count;
	}
	public void output(int n){
		switch(n){
		case 0:
			System.out.println("恭喜您获得一等奖!");break;
		case 1:
		    System.out.println("恭喜您获得二等奖!");break;
		case 2:
		    System.out.println("恭喜您获得三等奖!");break;
		case 3:
		    System.out.println("很遗憾您没有获奖");break;
		case 4:
		    System.out.println("很遗憾您没有获奖");break;
		case 5:
		    System.out.println("很遗憾您没有获奖");break;
		case 6:
		    System.out.println("很遗憾您没有获奖");break;
		}
	}
}
class ChoiceFive extends Game{
	public int[] cf=new int[5];
	public int[] num1 = new int[5];
	public ChoiceFive(){
		for(int i=0;i<5;i++){
            cf[i]=(int)(Math.random()*20+1);
        }
	}
	public void input(){
		Scanner cin1 = new Scanner(System.in);
        System.out.println("请输入5个数字（范围是1到21）：");
        for (int i = 0; i < 5; i++) {
        	num1[i] = cin1.nextInt();
        }
	}
}
class SixPlusOne extends Game{
	public int[] spo=new int[7];
	public int[] num2 = new int[7];
	public SixPlusOne(){
		for(int i=0;i<7;i++){
            spo[i]=(int)(Math.random()*8+1);
        }
	}
	public void input(){
		Scanner cin1 = new Scanner(System.in);
        System.out.println("请输入7个数字（范围是0到9）：");
        for (int i = 0; i < 7; i++) {
        	num2[i] = cin1.nextInt();
        }
	}
}
class Test{
	public static void main(String[] args) {
		System.out.println("选择1：21选5"+"\n"+"选择2：6+1");
		Scanner choose=new Scanner(System.in);
		int ch=choose.nextInt();
		if(ch==1){
	        ChoiceFive p1=new ChoiceFive();
	        p1.input();
	        int a=p1.check(p1.cf, p1.num1);
	        System.out.println("本期中奖号码为：");
	        for(int i=0;i<5;i++){
	        	System.out.println(p1.cf[i]);
	        }
	        p1.output(a);
		}
		if(ch==2){
			SixPlusOne p2=new SixPlusOne();
			p2.input();
	        int b=p2.check(p2.spo, p2.num2);
	        System.out.println("本期中奖号码为：");
	        for(int i=0;i<7;i++){
	            System.out.println(p2.spo[i]);
	        }
	        p2.output(b);
		}
	}
}
