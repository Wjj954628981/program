package socket;

import java.util.List;

import unit.file_number_check;
import unit.filelist;

public class downland implements Runnable{

	private String filename;
	
	public downland(String filename) {
		super();
		this.filename = filename;
	}

	public void run() {
		try {
			String check_filename = filename.substring(0, filename.indexOf("."));
			List<String> iplist = filelist.findIpaddress(filename);
			new fileblock().newproperties(filename, iplist.size());
			
			file_number_check.add(check_filename);
			
			for(int i=0;i<iplist.size();i++){
				new Thread(new UDPAskFile(filename, iplist.get(i), i+1, iplist.size())).start();
			}
			
			while(true){
				if(file_number_check.getvalue(check_filename)==iplist.size()){
					new fileblock().mergeByName(filename);
					break;
				}
			}
				
			file_number_check.delete(check_filename);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
