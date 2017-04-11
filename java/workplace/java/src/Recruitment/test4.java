package Recruitment;
import java.util.Scanner;

public class test4 {
	public static int findname(String[] nameList, String name){
		for(int i=0;i<nameList.length;i++){
			if(nameList[i].equals(name)){
				return i;
			}
		}
		return 0;
	}
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = Integer.parseInt(cin.nextLine());
		String[] nameList = new String[n];
		int[] moneyfirst = new int[n];
		int[] earn = new int[n];
		for(int i=0;i<n;i++){
			nameList[i] = cin.nextLine();
			earn[i] = 0;
		}
		for(int i=0;i<=n;i++){
			String name = cin.nextLine();
			int index = findname(nameList, name);
			String msg = cin.nextLine();
			int money_begin = Integer.parseInt(msg.substring(0, msg.indexOf(" ")));
			int num = Integer.parseInt(msg.substring(msg.indexOf(" ")+1));
			
			System.out.println(name + "? " + money_begin);
			
			moneyfirst[index] = money_begin;
			
			int everyone_money;
			if(num==0){
				everyone_money = 0;
				earn[index] = money_begin;
			}else{
				everyone_money = money_begin/num;
				earn[index] = money_begin%num;
			}
			
			for(int j=0;j<num;j++){
				String name2 = cin.nextLine();
				int index2 = findname(nameList, name2);
				earn[index2]+=everyone_money;
			}
		}
		for(int i=0;i<n;i++){
			System.out.println(nameList[i]+" "+(earn[i]-moneyfirst[i]));
		}
	}
}