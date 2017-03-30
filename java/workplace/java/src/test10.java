import java.util.Scanner;

public class test10 {

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		int q = cin.nextInt();
		int[] A = new int[n]; 
		int[] B = new int[n]; 
		for(int i=0;i<n;i++){
			A[i] = cin.nextInt();
		}
		for(int i=0;i<n;i++){
			B[i] = cin.nextInt();
		}
		int[] x = new int[q];
		int[] y = new int[q];
		for(int i=0;i<q;i++){
			x[i] = cin.nextInt();
			y[i] = cin.nextInt();
		}
	}

}
