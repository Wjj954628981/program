import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class test6 {
	public static int result = 0;
	static List<Integer> jobList = new ArrayList<Integer>();
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int num = Integer.parseInt(cin.nextLine());
		List<String> list = new ArrayList<String>();
		for(int i=0;i<num;i++){
			list.add(cin.nextLine());
		}
		for(int i=0;i<6;i++){
			jobList.add(i);
		}
		match(list, jobList);
		System.out.println(result);
	}
	 static void match(List<String> list, List<Integer> jobList){
		 if(jobList.size()==1){
			 result += list.size();
		 }
		 int a = list.get(0).length();
		 for(int i=0;i<a;i++){
			jobList.remove(Integer.parseInt(String.valueOf(list.get(0).charAt(i))));
			list.remove(0);
			match(list, jobList);
		 }
	 }
}