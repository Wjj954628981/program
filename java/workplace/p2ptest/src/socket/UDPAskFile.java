package socket;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class UDPAskFile implements Runnable{

	private String filename;
	private String Dest_ipaddress;
	private int file_block;
	private int file_block_number;
	
	public UDPAskFile(String filename, String Dest_ipaddress, int file_block, int file_block_number) {
		super();
		this.filename = filename;
		this.Dest_ipaddress = Dest_ipaddress;
		this.file_block = file_block;
		this.file_block_number = file_block_number;
	}

	public void run() {
		try {
			String AllLocalIP = InetAddress.getLocalHost().toString();
			String LocalIP = AllLocalIP.substring(AllLocalIP.indexOf("/") + 1, AllLocalIP.length());
			
			JSONArray jsonArray = new JSONArray();
			
			JSONObject json = new JSONObject();
			JSONObject json1 = new JSONObject();
			json.put("file_name", filename);
			json.put("flag", "0");
			json.put("ip_address",LocalIP);
			json.put("file_block",file_block);
			json.put("file_block_number",file_block_number);
				
			jsonArray.put(json);
			jsonArray.put(json1);
				
			
			InetAddress addr = InetAddress.getByName(Dest_ipaddress);
			InetSocketAddress UDP_Address = new InetSocketAddress(addr, 6667);
			
			DatagramSocket Send_socket = new DatagramSocket();
			byte[] buff_UDP_send = jsonArray.toString().getBytes();
			DatagramPacket sendpacket = new DatagramPacket(buff_UDP_send, buff_UDP_send.length);
			sendpacket.setSocketAddress(UDP_Address);
			Send_socket.send(sendpacket);
			System.out.println("UDP askfile "+filename+" from "+Dest_ipaddress);
			Send_socket.close();
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (SocketException e) {
			e.printStackTrace();
		} catch (JSONException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
