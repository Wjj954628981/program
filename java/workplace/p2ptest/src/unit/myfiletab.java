package unit;

public class myfiletab {
	String file_name;
	String ip_address;
	String file_address;
	public myfiletab(String filename, String ip_address, String file_address) {
		super();
		this.file_name = filename;
		this.ip_address = ip_address;
		this.file_address = file_address;
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
	public String getFile_address() {
		return file_address;
	}
	public void setFile_address(String file_address) {
		this.file_address = file_address;
	}
	
}
