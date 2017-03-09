package Collection;

import java.util.Iterator;
import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;

public class CollectionTest {
	static <T> void Amount(List<T> a){
		Set<T> aset=new HashSet<T>(a);
		System.out.println(a+"中包含"+aset+aset.size()+"种不同的数");
	}
	static <T> void Corresponding(List<T> a,List<T> b){
		Set<T> aset=new HashSet<T>(a);
		Iterator<T> it=aset.iterator();
		while(it.hasNext()){
			Set<T> bset=new HashSet<T>();
			T X=(T)it.next();
			for(int i=0;i<a.size();i++){
				if(a.indexOf(X)!=-1){
					T Y=b.get(a.indexOf(X));
					a.set(a.indexOf(X), null);
					bset.add(Y);
				}
			}
			System.out.println("a中的"+X+"对应于b中的"+bset);	
		}
	}
	public static void main(String[] args) {
		List<Integer> a=new ArrayList<Integer>();
		List<Integer> b=new ArrayList<Integer>();
		int[]A={2,1,2,2};
		int[]B={1,0,0,1};
		for(int i=0;i<A.length;i++){
			a.add(A[i]);
		}
		for(int i=0;i<B.length;i++){
			b.add(B[i]);
		}
		Amount(a);
		Corresponding(a,b);
	}
}
