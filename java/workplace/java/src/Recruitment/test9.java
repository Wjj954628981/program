package Recruitment;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class test9 {

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		int m = cin.nextInt();
		cin.nextLine();
		String[] sentence = new String[n];
		for(int i=0;i<n;i++){
			sentence[i] = cin.nextLine();
		}
		String[] search = new String[m];
		for(int i=0;i<m;i++){
			search[i] = cin.nextLine();
		}
		
		int[][] contain = new int[n][m];
		for(int i=0;i<m;i++){
			List<String> a = Arrays.asList(search[i].split(" "));

			for(int j=0;j<n;j++){
				int times = 0;
				for(int k=0;k<a.size();k++){
					if(sentence[j].contains(a.get(k))){
						times++;
					}
				}
				contain[j][i] = times;
			}
		}
		
		for(int i=0;i<m;i++){
			int max = 0;
			int index = 0;
			for(int j=0;j<n;j++){
				if(contain[j][i]>max){
					max = contain[j][i];
					index = j;
				}
			}
			System.out.println(sentence[index]);
		}
	}

}
