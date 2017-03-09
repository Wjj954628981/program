package frame;

import java.io.File;
import java.net.InetAddress;
import java.net.UnknownHostException;

import socket.MultiBroadListener;
import socket.MultiBroadSendFilelist;
import socket.TCPListener;
import socket.UDPListener;
import unit.filelist;
import unit.myfilelist;
import unit.myfiletab;

public class testmain {
	

	public static void main(String[] args) throws Exception {
		
		String AllLocalIP,local_ip = " ";
		try {
			AllLocalIP = InetAddress.getLocalHost().toString();
			local_ip =	AllLocalIP.substring(AllLocalIP.indexOf("/") + 1, AllLocalIP.length());	
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		String path = "d:/fileblock/";
        File f = new File(path);
        if(!f.exists()){
        	f.mkdirs();
        }
		
		new Thread(new UDPListener()).start();
		new Thread(new TCPListener()).start();
		new Thread(new MultiBroadListener()).start();
		
		new Thread(new MultiBroadSendFilelist(0)).start();
		myfiletab myfiletab1 = new myfiletab("wjj1.txt", local_ip, "d:\\"); 
		myfiletab myfiletab2 = new myfiletab("wjj2.txt", local_ip, "d:\\"); 
		myfiletab myfiletab3 = new myfiletab("test.txt", local_ip, "d:\\"); 		
		myfilelist.list.add(myfiletab1);
		myfilelist.list.add(myfiletab2);
		myfilelist.list.add(myfiletab3);
		
		new YFileChooser();
	}
}

