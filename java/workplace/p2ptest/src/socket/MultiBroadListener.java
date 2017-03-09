package socket;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.net.SocketException;
import java.net.UnknownHostException;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import unit.filelist;
import unit.filetab;

public class MultiBroadListener implements Runnable{
	MulticastSocket multicastsocket = null;
	
	byte[] broad_inBuff = new byte[4096];
	private DatagramPacket broad_inPacket = new DatagramPacket(broad_inBuff, broad_inBuff.length);
	
	public void run() {
		try {
			multicastsocket = new MulticastSocket(30000);
			InetAddress broadcastAddress = InetAddress.getByName("230.0.0.1");
			multicastsocket.joinGroup(broadcastAddress);
			multicastsocket.setLoopbackMode(true);
			while(true){
				multicastsocket.receive(broad_inPacket);
				System.out.println("Broad receive ask");
				JSONArray broad_Array = new JSONArray(new String(broad_inBuff, 0, broad_inPacket.getLength()));
				
				JSONObject resultObj0 = broad_Array.optJSONObject(0);
				String operation = resultObj0.getString("operation");
				String ip_address = resultObj0.getString("ip_address");
				if(operation.equals("0")){
					new Thread(new UDPSendFilelist(ip_address)).start();
				}
				if(operation.equals("1")){
					System.out.println(broad_Array.toString());
					filelist.delete(ip_address);
					for(int i=1;i<broad_Array.length();i++){
						JSONObject resultObj = broad_Array.optJSONObject(i);
						String file_name = resultObj.getString("file_name");
						filetab filetab = new filetab(file_name, ip_address);
						filelist.add(filetab);
					}
					//filelist.print();
				}
				if(operation.equals("2")){
					filelist.delete(ip_address);
					System.out.println("多播2"+ip_address);
				}
			}
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (SocketException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (JSONException e) {
			e.printStackTrace();
		}
	}

}
