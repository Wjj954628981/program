package Recruitment;
import java.util.Scanner;

public class test3 {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		String[] list = new String[n];
		String[] output = new String[n];
		for(int i=0;i<n;i++){
			list[i] = cin.nextLine();
		}
		for(int i=0;i<n;i++){
			if(list[i].contains("+")||list[i].contains("-")){
				for(int j=0;j<list[i].length();j++){
					if(String.valueOf(list[i].charAt(j)).equals("+")){
						output[i]+="/\\";
					}else{
						output[i]+="__";
					}
				}
			}else{
				for(int k=0;k<list[i].length();k++){
					if(String.valueOf(list[i].charAt(k)).equals("_")){
						output[i]+="-";
						k++;
					}else{
						output[i]+="+";
						k++;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			System.out.println(output[i]);
		}
	}
}
