package socket;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.net.UnknownHostException;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import unit.myfilelist;

public class MultiBroadSendFilelist implements Runnable {

	private String LocalIP;

	private int flag;
	
	public MultiBroadSendFilelist(int flag) {
		super();
		this.flag = flag;
	}

	public void run() {

		try {
			String AllLocalIP = InetAddress.getLocalHost().toString();
			LocalIP = AllLocalIP.substring(AllLocalIP.indexOf("/") + 1, AllLocalIP.length());

			MulticastSocket multicastsocket = new MulticastSocket(30000);
			InetAddress broadcastAddress = InetAddress.getByName("230.0.0.1");
			multicastsocket.joinGroup(broadcastAddress);
			multicastsocket.setLoopbackMode(true);
			
			JSONArray jsonArray = new JSONArray();

			JSONObject json1 = new JSONObject();
			json1.put("operation", flag);
			json1.put("ip_address", LocalIP);

			jsonArray.put(json1);

			int num = myfilelist.list.size();
			for (int i = 0; i < num; i++) {
				JSONObject json = new JSONObject();
				json.put("file_name", myfilelist.list.get(i).getFile_name());
				json.put("ip_address", myfilelist.list.get(i).getIp_address());

				jsonArray.put(json);

			}

			byte[] buff_broad_send = jsonArray.toString().getBytes();
			DatagramPacket broad_outPacket = new DatagramPacket(buff_broad_send, buff_broad_send.length, broadcastAddress,30000);
			multicastsocket.send(broad_outPacket);
			multicastsocket.close();
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (JSONException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
