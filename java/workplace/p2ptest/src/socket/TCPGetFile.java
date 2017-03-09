package socket;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.Socket;

import unit.file_number_check;

public class TCPGetFile implements Runnable {
    private Socket s;
 
    TCPGetFile(Socket s) {
        this.s = s;
    }
 
    @Override
    public void run() {
        System.out.println(s.getInetAddress().getHostAddress());
        try {
            BufferedInputStream bis = new BufferedInputStream(s.getInputStream());
            byte[] info = new byte[256];
            bis.read(info);
            String file_name = new String(info).trim();
            
            String path = "d:/fileblock/";
            File f = new File(path);
            if(!f.exists()){
            	f.mkdirs();
            } 
            
            File file = new File(f,file_name);
            if(!file.exists()){
	            try {
	            	file.createNewFile();
	            } catch (IOException e) {
	            e.printStackTrace();
	            }
            }
            
            BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream(path+file_name));
             
            byte[] buf = new byte[1024];
            int len = 0;
            while ((len = bis.read(buf)) != -1) {
                bos.write(buf, 0, len);
            }
            bos.close();
            bis.close();
            s.close();
            System.out.println(file_name+"  文件传输成功");
            String check_filename = file_name.substring(0, file_name.indexOf("."));
            file_number_check.map_print();
            System.out.println(check_filename);
            file_number_check.inc_filenum(check_filename);
            
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
 
}

