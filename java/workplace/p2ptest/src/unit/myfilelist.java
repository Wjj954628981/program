package unit;

import java.util.ArrayList;
import java.util.List;

public class myfilelist {
	public static List<myfiletab> list = new ArrayList<myfiletab>();

	public static void delete(String filename){
		for(int i=0;i<list.size();i++){
			if(list.get(i).file_name.equals(filename)){
				list.remove(i);
				i--;
			}
		}
	}
	
	public static void add(myfiletab myfiletab){
		list.add(myfiletab);
	}
	
	public static void print(){
		for(int i=0;i<list.size();i++){
			System.out.print(list.get(i).file_name);
			System.out.println(",");
			System.out.print(list.get(i).ip_address);
			System.out.println(",");
			System.out.print(list.get(i).file_address);
			System.out.println();
		}
	}
}
