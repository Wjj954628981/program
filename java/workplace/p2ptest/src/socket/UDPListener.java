package socket;

import java.io.File;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InetSocketAddress;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import unit.filelist;
import unit.filetab;
import unit.myfilelist;

public class UDPListener implements Runnable {

	byte[] UDP_inBuff = new byte[4096];
	private DatagramPacket UDP_inPacket = new DatagramPacket(UDP_inBuff, UDP_inBuff.length);
	DatagramSocket Receive_socket = null;
	
	public void run() {
		try {
			InetSocketAddress address = new InetSocketAddress(InetAddress.getLocalHost(), 6667);
			Receive_socket = new DatagramSocket(address);
			System.out.println("UDPListener create");
			while(true){
				Receive_socket.receive(UDP_inPacket);
				System.out.println("UDP receive ask");
				JSONArray UDP_Array = new JSONArray(new String(UDP_inBuff, 0, UDP_inPacket.getLength()));
				//System.out.println(new String(UDP_inBuff, 0, UDP_inPacket.getLength()));
				String ip_address = null;
				for(int i=0;i<UDP_Array.length();i++){
					JSONObject resultObj = UDP_Array.optJSONObject(i);
					//System.out.println(resultObj.toString());
					if(i==0 && resultObj.has("flag")){
						System.out.println("flag = 0");
						String flag = resultObj.getString("flag");
						String file_block = resultObj.getString("file_block");
						String file_block_number = resultObj.getString("file_block_number");
						ip_address = resultObj.getString("ip_address");
						String file_name = resultObj.getString("file_name");
						if(flag.equals("0")){
							for(int j=0;j<myfilelist.list.size();j++){
								if(myfilelist.list.get(j).getFile_name().equals(file_name)){
									new fileblock().splitFile(myfilelist.list.get(j).getFile_address(),file_name, Integer.parseInt(file_block_number));
									String block_path = "D:"+File.separator+"fileblock"+File.separator+file_name+"part_"+file_block+".file";
									new Thread(new TCPSendFile(ip_address, block_path)).start();
								}
							}
							break;
						}
					}
					if(i==0 && (!resultObj.has("flag"))){
						filelist.delete(ip_address);
//						System.out.println("flag = 1");
					}
					String file_name = resultObj.getString("file_name");
					ip_address = resultObj.getString("ip_address");
					filetab filetab = new filetab(file_name, ip_address);
					filelist.add(filetab);
				}
//			filelist.print();
			}
		} catch (IOException e) {
			e.printStackTrace();
		} catch (JSONException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
}
