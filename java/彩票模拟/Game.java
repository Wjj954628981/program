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
			System.out.println("��ϲ�����һ�Ƚ�!");break;
		case 1:
		    System.out.println("��ϲ����ö��Ƚ�!");break;
		case 2:
		    System.out.println("��ϲ��������Ƚ�!");break;
		case 3:
		    System.out.println("���ź���û�л�");break;
		case 4:
		    System.out.println("���ź���û�л�");break;
		case 5:
		    System.out.println("���ź���û�л�");break;
		case 6:
		    System.out.println("���ź���û�л�");break;
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
        System.out.println("������5�����֣���Χ��1��21����");
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
        System.out.println("������7�����֣���Χ��0��9����");
        for (int i = 0; i < 7; i++) {
        	num2[i] = cin1.nextInt();
        }
	}
}
class Test{
	public static void main(String[] args) {
		System.out.println("ѡ��1��21ѡ5"+"\n"+"ѡ��2��6+1");
		Scanner choose=new Scanner(System.in);
		int ch=choose.nextInt();
		if(ch==1){
	        ChoiceFive p1=new ChoiceFive();
	        p1.input();
	        int a=p1.check(p1.cf, p1.num1);
	        System.out.println("�����н�����Ϊ��");
	        for(int i=0;i<5;i++){
	        	System.out.println(p1.cf[i]);
	        }
	        p1.output(a);
		}
		if(ch==2){
			SixPlusOne p2=new SixPlusOne();
			p2.input();
	        int b=p2.check(p2.spo, p2.num2);
	        System.out.println("�����н�����Ϊ��");
	        for(int i=0;i<7;i++){
	            System.out.println(p2.spo[i]);
	        }
	        p2.output(b);
		}
	}
}
