package Recruitment;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class test13 {
	//输出从a个数中选出b个数的全部组合
	final public static List<String> C(int a, int b){
		List<String> list = new ArrayList<String>();
		return list;
	}
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int num = cin.nextInt();
		cin.nextLine();
		double[] p = new double[num];
		for(int i=0;i<num;i++){
			p[i] = cin.nextDouble()/100;
		}
		int right_num = (int)(num*0.6)+1;
		double result = 0;
		for(int i=right_num;i<num+1;i++){
			List<String> k = C(num, i);
			for(int j=0;j<k.size();j++){
				double every_p = 1;
				for(int l=0;l<i;l++){
					every_p *= p[Integer.parseInt(String.valueOf(k.get(j).charAt(l)))];
				}
				//result乘1-剩下的num-i的概率
			}
		}
		System.out.println(result);
	}
}
