package server;

import java.io.BufferedReader;  
import java.io.IOException;  
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.Socket;  
import java.util.Scanner;  
  
public class MulClient {  
    public static void main(String[] args) throws IOException {  
    	Socket socket = new Socket("10.129.171.210", 8888);  
        //接收服务器返回的UDP端口号
        BufferedReader socketIn = new BufferedReader(new InputStreamReader(socket.getInputStream()) );
        String UPDPort = socketIn.readLine();
        System.out.println(UPDPort);
        
        //创建客户端UDP socket与服务器进行交互
        InetAddress addr = InetAddress.getByName("10.129.171.210");
        InetSocketAddress toAddress = new InetSocketAddress(addr, Integer.parseInt(UPDPort));
        DatagramSocket ds = new DatagramSocket();
        ds.setSoTimeout(10000);
        
        
        //发送数据
        Scanner cin = new Scanner(System.in);
        int message = cin.nextInt();

        byte buf_send[] = String.valueOf(message).getBytes();
        DatagramPacket sendpacket = new DatagramPacket(buf_send, buf_send.length);
        sendpacket.setSocketAddress(toAddress);
        ds.send(sendpacket);
        
        //接收数据
        byte buf_receive[] = new byte[1024];
        DatagramPacket receivepacket = new DatagramPacket(buf_receive, buf_receive.length);
        ds.receive(receivepacket);
        String Mse_receive = new String(buf_receive, 0, receivepacket.getLength());  
        if(Mse_receive.equals("3")){
        	System.exit(0);
        }else{
        	System.out.println(Mse_receive);
        	System.exit(0);
        }
        
        ds.close();       
        socketIn.close();
        socket.close();
    }  
} 