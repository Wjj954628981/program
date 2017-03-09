package socket;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InetSocketAddress;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import unit.myfilelist;

public class UDPSendFilelist implements Runnable{

	private String ipaddress;
	
	public UDPSendFilelist(String ipaddress) {
		super();
		this.ipaddress = ipaddress;
	}

	public void run() {
		try {
			InetAddress addr = InetAddress.getByName(ipaddress);
			InetSocketAddress UDP_Address = new InetSocketAddress(addr, 6667);
			
			JSONArray jsonArray = new JSONArray();
			int num = myfilelist.list.size();
			for (int i = 0; i < num; i++) {
				JSONObject json = new JSONObject();
				json.put("file_name", myfilelist.list.get(i).getFile_name());
				json.put("ip_address", myfilelist.list.get(i).getIp_address());
				
				jsonArray.put(json);
			}
			DatagramSocket Send_socket = new DatagramSocket();
			byte[] buff_UDP_send = jsonArray.toString().getBytes();
			DatagramPacket sendpacket = new DatagramPacket(buff_UDP_send, buff_UDP_send.length);
	        sendpacket.setSocketAddress(UDP_Address);
	        Send_socket.send(sendpacket);
	        Send_socket.close();
		} catch (JSONException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
