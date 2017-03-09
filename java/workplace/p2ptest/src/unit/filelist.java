package unit;

import java.util.ArrayList;
import java.util.List;

public class filelist {
	public static List<filetab> list = new ArrayList<filetab>();

	public static void delete(String ip_address){
		for(int i=0;i<list.size();i++){
			if(list.get(i).ip_address.equals(ip_address)){
				list.remove(i);
				i--;
			}
		}
	}
	
	public static void add(filetab filetab){
		list.add(filetab);
	}
	
	public static void print(){
		for(int i=0;i<list.size();i++){
			System.out.print(list.get(i).file_name);
			System.out.println(",");
			System.out.print(list.get(i).ip_address);
			System.out.println();
		}
	}
	
	public static List<String> findIpaddress(String filename){
		List<String> IPlist = new ArrayList<String>();
		for(int i=0;i<list.size();i++){
			if(list.get(i).file_name.equals(filename)){
				IPlist.add(list.get(i).ip_address);
			}
		}
		return IPlist;
	}
	
}
