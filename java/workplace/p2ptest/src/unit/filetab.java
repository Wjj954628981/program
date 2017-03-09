package unit;

public class filetab {
	String file_name;
	String ip_address;
	public filetab(String filename, String ip_address) {
		super();
		this.file_name = filename;
		this.ip_address = ip_address;
	}
	public String getFile_name() {
		return file_name;
	}
	public void setFile_name(String file_name) {
		this.file_name = file_name;
	}
	public String getIp_address() {
		return ip_address;
	}
	public void setIp_address(String ip_address) {
		this.ip_address = ip_address;
	}
	
}
