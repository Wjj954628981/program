package server;

import java.io.PrintStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.NetworkInterface;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketAddress;
import java.text.SimpleDateFormat;
import java.util.Date;  
  
public class MulServer {  
    public static void main(String[] args) throws Exception{  
        //服务端在8888端口监听客户端请求的TCP连接  
        ServerSocket server = new ServerSocket(8888); 
        System.out.println("Waiting for connecting!");
        Socket client = null;  
        boolean f = true;  
        while(f){  
            //等待客户端的连接 
            client = server.accept();  
            System.out.println("Connection from TCP client " + client.getRemoteSocketAddress() +"accepted");  
            //为每个客户端连接开启一个线程  
            new Thread(new ServerThread(client)).start();  
        }  
        server.close();  
    }  
}  

class ServerThread implements Runnable {  
	  
    private Socket client = null;  
    public ServerThread(Socket client){  
        this.client = client;  
    }  
      
    @Override  
    public void run() {  
        try{  
        	//返回UDP端口号
            PrintStream out = new PrintStream(client.getOutputStream());
            System.out.println("Request for UDP Port from " + client.getRemoteSocketAddress() + " by TCP");
            String UDPport = "6666";
            System.out.println("Send UDP Port " + UDPport + " to client");
            out.println(UDPport);
            
            //创建服务器UDP socket，端口号为6666
            InetSocketAddress address = new InetSocketAddress(InetAddress.getLocalHost(), 6666);
            DatagramSocket ds = new DatagramSocket(address);
            
            //接收到客户端信息
            byte[] buf_receive = new byte[1024];
            DatagramPacket dp_receive = new DatagramPacket(buf_receive, buf_receive.length);
            ds.receive(dp_receive);
            String str_receive = new String(buf_receive,0,dp_receive.getLength());
            System.out.println("Receive message: " +str_receive+ " from client");
            SocketAddress toAddress = dp_receive.getSocketAddress();
            
            //进行判断并将消息发送回客户端
            String str_message = null;
            if(str_receive.equals("1")){
            	//获得系统时间
            	System.out.println("Request for Current time from " + client.getRemoteSocketAddress() + "by TCP");
            	SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");//设置日期格式
            	str_message = df.format(new Date());
            	System.out.println("Send Current time " + str_message + " to client"); 
            	byte[] buf_send = str_message.getBytes();
                DatagramPacket dp_send = new DatagramPacket(buf_send, buf_send.length);
                dp_send.setSocketAddress(toAddress);
                ds.send(dp_send);
            }else if(str_receive.equals("2")){
            	//获得服务器mac地址
            	byte[] mac = NetworkInterface.getByInetAddress(InetAddress.getLocalHost()).getHardwareAddress();
        		StringBuffer sb = new StringBuffer("");
        		for(int i=0; i<mac.length; i++) {
        			if(i!=0) {
        				sb.append("-");
        			}
        			//字节转换为整数
        			int temp = mac[i]&0xff;
        			String str = Integer.toHexString(temp);
        			System.out.println("每8位:"+str);
        			if(str.length()==1) {
        				sb.append("0"+str);
        			}else {
        				sb.append(str);
        			}
        		}
        		str_message = sb.toString().toUpperCase();
        		System.out.println("Send MAC address " + str_message + " to client"); 
            	byte[] buf_send = str_message.getBytes();
                DatagramPacket dp_send = new DatagramPacket(buf_send, buf_send.length);
                dp_send.setSocketAddress(toAddress);
                ds.send(dp_send);
            }else if(str_receive.equals("3")){
            	//返回客户端退出信息
            	str_message = "3";
            	byte[] buf_send = str_message.getBytes();
                DatagramPacket dp_send = new DatagramPacket(buf_send, buf_send.length);
                dp_send.setSocketAddress(toAddress);
                ds.send(dp_send);
            }else{
            	System.out.println(str_receive +" received from 128.82.10.15:36284 by UDP");
            }
            
            ds.close();
            out.close();
            client.close();  
        }catch(Exception e){  
            e.printStackTrace();  
        }  
    }  
  
}  