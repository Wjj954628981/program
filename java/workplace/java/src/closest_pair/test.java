package closest_pair;

import java.util.Arrays;

public class test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int[] a = {1,2,3,4,5,6,7,8,9,10};
		int[] b = Arrays.copyOfRange(a, 0, a.length/2);
		int[] c = Arrays.copyOfRange(a, a.length/2, a.length);
		for(int i=0;i<b.length;i++){
			System.out.println(b[i]);
		}
		System.out.println();
		for(int i=0;i<c.length;i++){
			System.out.println(c[i]);
		}
	}

}
