package Recruitment;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class test8 {

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int num = cin.nextInt();
		int[] Array = new int[num];
		for(int i=0;i<num;i++){
			Array[i] = cin.nextInt();
		}

		List<Integer> list_up = new ArrayList<Integer>();
		List<Integer> list_down = new ArrayList<Integer>();
		if(Array[0]<Array[1]){
			list_down.add(0);
		}
		for(int i=1;i<num-1;i++){
			if(Array[i]<Array[i-1]&&Array[i]<Array[i+1]){
				list_down.add(i);
			}
		}
		if(Array[num-1]<Array[num-2]){
			list_down.add(num-1);
		}
		int begin=0,end=0,max=0;
		if(list_down.size()==1){
			begin = end = -1;
		}
		for(int i=0;i<list_down.size()-1;i++){
			int tmp = list_down.get(i+1)-list_down.get(i);
			if(max<tmp){
				max = tmp;
				begin = list_down.get(i);
				end = list_down.get(i+1);
			}
		}
		System.out.println(begin + " " + end);
	}

}
