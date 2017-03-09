package socket;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class TCPListener implements Runnable {
	private ServerSocket ss;

	public void run(){
		try {
			ss = new ServerSocket(8800);
			System.out.println("TCPListener create");
			while(true){
				Socket s=ss.accept();
				System.out.println("TCP receive ask");
				new Thread(new TCPGetFile(s)).start();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}