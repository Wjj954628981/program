package unit;

import java.util.HashMap;
import java.util.Map;

public class file_number_check {
	public static Map<String,Integer> file_downland_list = new HashMap<String,Integer>();
	
	public static void add(String filename){
		file_downland_list.put(filename, 0);
	}
	
	public static void delete(String filename){
		file_downland_list.remove(filename);
	}
	
	public static void inc_filenum(String filename){
		int num = file_downland_list.get(filename);
		System.out.println("inc"+"  "+filename+"  "+num);
		file_downland_list.put(filename, num+1);
	}	
	
	public static int getvalue(String filename){
		int value = file_downland_list.get(filename);
		return value;
	}
	
	public static void map_print(){
		for(Map.Entry entry: file_downland_list.entrySet()){
			   System.out.println("???"+entry.getKey()+" = "+entry.getValue());
			}
	}
		
}
