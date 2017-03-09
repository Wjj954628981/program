package socket;

import java.io.*;
import java.util.Properties;

public class fileblock {
	public void newproperties(String filename, int number){
		try {
			OutputStream configOps = new FileOutputStream("d:"+File.separator+"fileblock"+File.separator+filename+"info.properties");
			Properties partInfo = new Properties();
			partInfo.setProperty("fileName",filename);
			partInfo.setProperty("fileNumber",""+number);
			for(int i=1;i<=number;i++){
				String targetFilePath = "d:"+File.separator+"fileblock"+File.separator+filename+"part_"+i+".file";
				partInfo.setProperty(""+i,targetFilePath);
			}
			partInfo.store(configOps,"ConfigFile");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	// 分块
	public void splitFile(String filepath,String filename, int Number) throws Exception{
		File sourceFile = new File(filepath+filename);
		long size =sourceFile.length()/Number;
		InputStream ips = new FileInputStream(sourceFile);
		OutputStream configOps = new FileOutputStream("d:"+File.separator+"fileblock"+File.separator+filename+"info.properties");
		
		Properties partInfo = new Properties();
		partInfo.setProperty("fileName",sourceFile.getName());
		partInfo.setProperty("fileNumber",""+Number);
		
		int i=1;
		
		byte[] buffer1 = new byte[(int) size];
		byte[] buffer2 = new byte[(int) (sourceFile.length()-size*(Number-1))];
		
		if(Number!=1){
			while(ips.read(buffer1,0,buffer1.length) != -1){
				System.out.println("???");
				String targetFilePath = "d:"+File.separator +"fileblock"+File.separator+ sourceFile.getName() + "part_" + i + ".file";
				partInfo.setProperty(""+i,targetFilePath);
				File targetFile = new File(targetFilePath);
				OutputStream ops = new FileOutputStream(targetFile);
				ops.write(buffer1,0,buffer1.length);
				ops.close();
				i++;
				if(i==Number){
					break;
				}
			}
		}
		
		ips.read(buffer2,0,buffer2.length);
		String targetFilePath = "d:"+File.separator + "fileblock"+File.separator+sourceFile.getName() + "part_" + Number + ".file";
		partInfo.setProperty(""+Number,targetFilePath);
		File targetFile = new File(targetFilePath);
		OutputStream ops = new FileOutputStream(targetFile);
		ops.write(buffer2,0,buffer2.length);
		ops.close();
		 	
		partInfo.store(configOps,"ConfigFile");
		ips.close();
	}

	// 合并
	public void mergeByName(String filename) throws Exception {
		Properties prop = new Properties();

		InputStream pro_in = new BufferedInputStream(new FileInputStream("d:"+File.separator+"fileblock"+File.separator+filename+"info.properties"));
		prop.load(pro_in);
		pro_in.close();
		
		int number=Integer.parseInt(prop.getProperty("fileNumber"));
		
		File allfile = new File("d:"+File.separator+"fileblock"+File.separator + prop.getProperty("fileName"));
		BufferedOutputStream out=new BufferedOutputStream(new FileOutputStream(allfile));
		
		for(int i=1;i<=number;i++) {
			File smallFile=new File(prop.getProperty(""+i));
			BufferedInputStream small_in=new BufferedInputStream(new FileInputStream(smallFile));
			byte[] buf=new byte[(int) smallFile.length()];
			small_in.read(buf);
			out.write(buf);
			small_in.close();
		}
		out.close();
	}

	public String randNumber() {
		double number = Math.random();
		String str = String.valueOf(number);
		str = str.replace(".", "");
		return str;
	}
	
	public static void main(String[] args) {
		fileblock fileblock = new fileblock();
		try {
			fileblock.splitFile("d:/","test.txt",1);
//			fileblock.newproperties("test.txt", 10);
			fileblock.mergeByName("test.txt");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
