package socket;

import java.io.BufferedOutputStream;
import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.SequenceInputStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Arrays;

public class TCPSendFile implements Runnable{
	
	private String ipaddress;
	private String path;
	
	public TCPSendFile(String ipaddress, String filename) {
		super();
		this.ipaddress = ipaddress;
		this.path = filename;
	}

	public void run() {
		try {
			Socket s = new Socket(ipaddress,8800);
            
            File file = new File(path);
            FileInputStream fs = new FileInputStream(file);
            
            byte[] b = file.getName().getBytes();
            byte[] info = Arrays.copyOf(b,256);         
            ByteArrayInputStream bais = new ByteArrayInputStream(info);
            
            //合并流
            SequenceInputStream sis = new SequenceInputStream(bais,fs);
            BufferedOutputStream bos = new BufferedOutputStream(s.getOutputStream());
            byte[] buf = new byte[1024];
            int len = 0;
            while((len = sis.read(buf))!=-1){
                bos.write(buf,0,len);
            }
            
            bos.close();
            sis.close();
            fs.close();
            bais.close();
            s.close();
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
