package frame;

import java.awt.Container;
import java.awt.Font;
import java.awt.Image;
import java.awt.Point;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTabbedPane;
import javax.swing.JTable;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.UIManager;

import socket.MultiBroadSendFilelist;
import socket.UDPAskFile;
import socket.downland;
import unit.filelist;
import unit.myfilelist;
import unit.myfiletab;


public class YFileChooser implements ActionListener{

	String fileName,file_addr,ip_addr,local_ip="单击刷新以显示本地IP地址";
	
	File f;
	int count=0;//当前在线用户数
	
	long timemillis = System.currentTimeMillis();   
	Date now = new Date(); //获取当前时间
    SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
    String time = "您的登录时间为："+dateFormat.format(new Date(timemillis)) ;
 
    String[] columnNames = {"文件名","文件路径"};
    String[] columnNames1 = {"文件名","来源地址","当前状态"};
    String[] columnNames2 ={"IP","IP地址"}; 
    

    private static Object[][] d = new Object[20][2];
    //myfilelist并不需要去重
    //d=myfilelist.toArray();
    private static Object[][] d1 = new Object[20][3];
    private static Object[][] d2 = new Object[20][2];
    private static Object[] d3 = new Object[20];
    /*List<Object[]> filename = new ArrayList<object[]>();
     *List<Object[]> ip_addr = new ArrayList<object[]>();
     * for(int i=0;i<filelist.size();i++){  
     *  ip_addr.add(filelist.get(i)[0]);  
     *	filename.add(filelist.get(i)[1]);
     *}
     *ArrayList list = new ArrayList(new HashSet(filename));用一个新的list去重
     *ArrayList list2 = new ArrayList(new HashSet(ip_addr));用一个新的list2去重
     *d1=list.toArray();
    */
    //d2=list2.toArray();    
    /*梦想中我们已经完美地实现了Arraylist能传到我们的Object[][] d 里面，2333 
     * d1 list 对应  myfilelist 上传列表 
     * d2 list2 对应ip列表
     */
/*    
    Object[][] data =
    	{
	    	//{"文件名", ("上传速度"),"已上传"},
	    	{"文件1", ("1"),"0.00"},
	        {"文件2", ("2"),"0.00"},
	        {"文件666",("3"),"0.00"},
	        {"文件1", ("1"),"0.00"},
	        {"文件2", ("2"),"0.00"},
	        {"文件3", ("3"),"0.00"},
	        {"文件1", ("1"),"0.00"},
	        {"文件2", ("2"),"0.00"},
	        {"文件3", ("3"),"0.00"},
    	};
    Object[][] data1 =
    	{
	    	//{"文件名", ("下载速度"),"剩余"},
	    	{"文件1", ("1"),"0.00"},
	        {"文件2", ("2"),"0.00"},
	        {"文件3", ("3"),"0.00"},
	        {"文件1", ("1"),"0.00"},
	        {"文件2", ("2"),"0.00"},
	        {"文件3", ("3"),"0.00"},
	        {"文件1", ("1"),"0.00"},
	        {"文件2", ("2"),"0.00"},
	        {"文件3", ("3"),"0.00"},
    	};
    Object[][] data2 =
    	{
	    	//{"ip", ("IP地址")},
	    	{"ip1", ("192.168.32.1")},
	        {"ip2", ("192.168.32.2")},
	        {"ip3", ("192.168.32.3")},
    	};	
   */ 
    
    
    JFrame frame=new JFrame("mdTorrent");
    JTabbedPane tabPane=new JTabbedPane();//选项卡布局
    Container con= new Container();//布局1
    //JPanel con=(JPanel)frame.getContentPane();
    Toolkit tool=frame.getToolkit(); //得到一个Toolkit对象
    ImageIcon img = new ImageIcon("bg.jpg");    
    //ImageIcon btnbgIcon= new ImageIcon("btnbg.jpg"); 
    Image icon=tool.getImage("wjj2.jpg"); //由tool获取图像
    JLabel label_bg = new JLabel(img);
    JLabel label1=new JLabel("选择目录");
    JLabel label2=new JLabel("选择文件");
    JLabel label3=new JLabel("上传列表");
    JLabel label4=new JLabel("下载列表");
    JLabel label5=new JLabel("所有可连接IP地址");
    JLabel label6=new JLabel("请输入下载文件名");
    JLabel label7=new JLabel(time);
    JLabel label8=new JLabel("当前在线的用户数目："+count);
    JLabel label9=new JLabel("欢迎使用mdTorrent 1.0.0.0版本");
    JLabel label10=new JLabel("当前状态为：已连接");
    JLabel label11=new JLabel("当前IP地址为："+local_ip);
    JLabel label12=new JLabel("<html><body>所在小组成员："
    		+ "<br />1412616 	李志伟"
    		+ "<br />1412618 	刘帆"
    		+ "<br />1412622 	刘天龙"
    		+ "<br />1412641	王佳颉"
    		+ "</body></html>");
    JTextField text1=new JTextField();
    JTextField text2=new JTextField();
    JTextField text3=new JTextField();
    
    JButton button1=new JButton("...");
    JButton button2=new JButton("...");
    JButton button3=new JButton("upload");
    JButton button4=new JButton("download"); //单击下载后如果列表里没有该文件则给出提示框
    JButton button5=new JButton("刷新");
    JButton button6=new JButton("退出"); 
    //JButton button6=new JButton("下载");
    
    
    JFileChooser jfc=new JFileChooser();//文件选择器
    
   
    JTable table1 = new JTable(d,columnNames);
    JTable table2 = new JTable(d1,columnNames1);
    JTable table3 = new JTable(d2,columnNames2);
    JScrollPane scrollPane1 = new JScrollPane(table1);
    JScrollPane scrollPane2 = new JScrollPane(table2);
    JScrollPane scrollPane3 = new JScrollPane(table3);
   
    //JTableHeader tableHeader1 = new JTableHeader();
    
    YFileChooser(){
    	updatedialog();   
    	setUIFont();
        jfc.setCurrentDirectory(new File("d:\\"));//文件选择器的初始目录定为d盘
        //下面两行是取得屏幕的高度和宽度
        double lx=Toolkit.getDefaultToolkit().getScreenSize().getWidth();
        double ly=Toolkit.getDefaultToolkit().getScreenSize().getHeight();
        frame.setLocation(new Point((int)(lx/2-450),(int)(ly/2-300)));//设定窗口出现位置
        frame.setSize(1000,550);//设定窗口大小
        frame.setContentPane(tabPane);//设置布局
       //下面设定标签等的出现位置和高宽
        label1.setBounds(10,10,70,20);
        label2.setBounds(10,30,100,20);
        label3.setBounds(10,70,100,20);
        label4.setBounds(10,300,300,20);
        label5.setBounds(550,70,300,20);
        label6.setBounds(10, 240, 120, 20);
        label7.setBounds(10,450,300,20);
        label8.setBounds(600,450,300,20);
        label9.setBounds(600,10,300,20);
        label10.setBounds(400, 450, 150, 20);
        label11.setBounds(600, 40, 300, 20);
        label12.setBounds(600, 320, 200, 100);
        label_bg.setBounds(0, 0, img.getIconWidth(), img.getIconHeight());
        
        text1.setBounds(80,10,120,20);
        text2.setBounds(80,30,120,20);
        text3.setBounds(120, 240, 120, 20);
        button1.setBounds(210,10,30,20);
        button2.setBounds(210,30,30,20);
        button3.setBounds(250,20,100,20);
        button4.setBounds(250,240,100,20);
        button5.setBounds(750,450,80,20);   
        button6.setBounds(850,450,80,20);   
        button1.setContentAreaFilled(false);
        button2.setContentAreaFilled(false);
        button3.setBorderPainted(false); 
        button4.setBorderPainted(false); 
        button5.setBorderPainted(false); 
        button6.setBorderPainted(false); 
        //button3.setIcon(btnbgIcon);
        scrollPane1.setBounds(10,100,500,100);
        scrollPane2.setBounds(10,320,500,100);
        scrollPane3.setBounds(550,100,400,100);
        button1.addActionListener(this);//添加选择目录事件处理
        button2.addActionListener(this);//添加选择文件事件处理
        button3.addActionListener(this);//添加上传事件处理
        button4.addActionListener(this);//添加下载事件处理
        button5.addActionListener(this);//添加刷新事件处理
        button6.addActionListener(this);//添加退出事件处理
        
        tabPane.setOpaque(false);
        label_bg.setOpaque(false);
        scrollPane1.setViewportView(table1);
        scrollPane2.setViewportView(table2);
        scrollPane3.setViewportView(table3);
        table1.setEnabled(false);
        con.add(label1);
        con.add(label2);
        con.add(label3);
        con.add(label4);
        con.add(label5);
        con.add(label6);
        con.add(label7);
        con.add(label8);
        con.add(label9);
        con.add(label10);
        con.add(label11);
        con.add(label12);
        //con.add(imgLabel);//绝对不能这么加进去
        con.add(text1);
        con.add(text2);
        con.add(text3);
        con.add(button1);
        con.add(button2);
        con.add(button3);
        con.add(button4);
        con.add(scrollPane1);
        con.add(scrollPane2);
        con.add(scrollPane3);
        con.add(button5);
        con.add(button6);
        tabPane.add("文件",con);//添加布局1
        frame.getLayeredPane().setLayout(null);
        frame.getLayeredPane().add(label_bg,new Integer(Integer.MIN_VALUE));
        frame.setVisible(true);//窗口可见
        frame.setIconImage(icon);
        //frame.setBackground(new Color(0,0,0));
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//使能关闭窗口，结束程序
        
     
      //创建表值  
       
    }

	private void updatedialog() {
		String AllLocalIP;
    	try {
			AllLocalIP = InetAddress.getLocalHost().toString();
			local_ip =	AllLocalIP.substring(AllLocalIP.indexOf("/") + 1, AllLocalIP.length());	
			 
		} catch (UnknownHostException e2) {
			// TODO Auto-generated catch block
			e2.printStackTrace();
		}
		// TODO Auto-generated method stub
		//该函数用于更新表格中的数据
		for(int i=0;i<myfilelist.list.size();i++){   		
			d[i][0]=myfilelist.list.get(i).getFile_name(); 	
			d[i][1]=myfilelist.list.get(i).getFile_address(); 	
    	}
		
    	for(int i=0;i<filelist.list.size();i++){     		
			d1[i][0]=filelist.list.get(i).getFile_name(); 	
			d1[i][1]=filelist.list.get(i).getIp_address();
			if(d1[i][2]==null){
				d1[i][2]="未下载";
			}
    	}	
    	//去除重复IP
//    	Boolean ipflag = true;
//    	int IP_count=0;
//		for(int i=0;i<filelist.list.size();i++){ 			
//			for(int j=0;j<IP_count;j++){
//				if(d2[j][1].equals(filelist.list.get(i).getIp_address())){
//					ipflag = false;
//				}
//			}
//			System.out.println(ipflag);
//			if(ipflag==true){
//				d2[IP_count][0]=IP_count+1;			
//				d2[IP_count][1]=filelist.list.get(i).getIp_address();
//				IP_count++;
//				
//			}
//		}
    	Set<Object> ip_set = new HashSet<Object>();
    	//Iterator<Object> it = ip_set.iterator();
    	for(int i=0;i<filelist.list.size();i++){
    		ip_set.add(filelist.list.get(i).getIp_address());
    	}
    	
    	d3= ip_set.toArray();
    	for(int i=0;i<d2.length;i++){
    		d2[i][0]=null;
    		d2[i][1]=null;
    	}
    	for(int i=0;i<d3.length;i++){
    			d2[i][0] = i+1;
    			d2[i][1] = d3[i];
    	}
		table1.updateUI();
    	table2.updateUI();
    	table3.updateUI();
    	//System.out.println(myfilelist.list.size());
		
	}

	public void actionPerformed(ActionEvent e){//事件处理
        if(e.getSource().equals(button1)){//判断触发方法的按钮是哪个
            jfc.setFileSelectionMode(1);//设定只能选择到文件夹
            int state=jfc.showOpenDialog(null);//此句是打开文件选择器界面的触发语句
            if(state==1){
                return;//撤销则返回
            }
            else{
                File f=jfc.getSelectedFile();//f为选择到的目录
                text1.setText(f.getAbsolutePath());
            }
        }
        if(e.getSource().equals(button2)){
            jfc.setFileSelectionMode(0);//设定只能选择到文件
            int state=jfc.showOpenDialog(null);//此句是打开文件选择器界面的触发语句
            if(state==1){
                return;//撤销则返回
            }
            else{
                File f=jfc.getSelectedFile();//f为选择到的文件
                text2.setText(f.getAbsolutePath());
                
                //System.out.println(file_addr);   
                
            }
        }
        if(e.getSource().equals(button3)){
            //上传操作
        	String AllLocalIP;
        	try {
				AllLocalIP = InetAddress.getLocalHost().toString();
				local_ip =	AllLocalIP.substring(AllLocalIP.indexOf("/") + 1, AllLocalIP.length());	
				 
			} catch (UnknownHostException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
       	File f=jfc.getSelectedFile();//f为选择到的文件
            text2.setText(f.getAbsolutePath());
        	fileName = f.getName();  //获取f的文件名
            file_addr= f.getParent();
           	myfiletab newMyfiletab = new myfiletab(fileName, local_ip, file_addr);
           	Boolean isexisted = false; //检查该文件是否存在
           	for(int i=0;i<myfilelist.list.size();i++){
           		if(fileName.equals(myfilelist.list.get(i).getFile_name())==true){
           			isexisted = true;
           			Object[] options = { "确定", "取消" }; 
           			JOptionPane.showOptionDialog(null, "该文件已上传，请重新选择", "信息提示", 
           			JOptionPane.DEFAULT_OPTION, JOptionPane.WARNING_MESSAGE, 
           			null, options, options[0]); 
           			text2.setText("");
                    text1.setText("");
           			break;
           		}
           	}
           	if(isexisted==false){
                myfilelist.list.add(newMyfiletab);
                text2.setText("");
                text1.setText("");
                Button3Refresh();             
           	}
           }
        if(e.getSource().equals(button4)){
            //下载操作
        	String downloadtext = text3.getText();
        	Boolean statusBoolean = true;   
        	Boolean flag = true;
        	if(downloadtext!=null&&statusBoolean==true){
        		
        		//System.out.println(downloadtext);
	        	for(int i=0;i<d1.length;i++){
	        		if(downloadtext.equals(d1[i][0])&&d1[i][2]=="未下载"){
	        			d1[i][2]="正在下载";  
	        		
        			updatedialog();
        			String f_name = d1[i][0].toString();
        			String f_ip_addr = d1[i][1].toString();
        			
        			//System.out.println("终于等到你还好我没放弃");
        			flag = false;
        			//执行到了这一句，很nice！！
        			//调用函数开始下载        			
        			new Thread(new downland(f_name)).start();
        			//可以正常下载
        			//下载结束后随便给我一个参数就行
        			//根据参数d1[i][2]变为已下载、
        			d1[i][2]="已下载";    
        			break;
	        		}
	        	}
	        	for(int i=0;i<d1.length;i++){
	        		if(downloadtext.equals(d1[i][0])&&d1[i][2]=="未下载"){
	        			d1[i][2]="已下载";  
	        		}
	        	}	
	        	if(flag==true){
       	    	    //System.out.println("WJJ");
        		    final JFrame warningframe=new JFrame("warning");
        			JLabel warningJLabel = new JLabel("输入文件名有误，请重新输入");
        			JButton warningButton = new JButton("确定");
        			Container content = warningframe.getContentPane();
        			content.setLayout(null);
        			warningframe.setSize(300,200);
        			warningframe.setTitle("消息提醒");
        			warningJLabel.setBounds(60, 50, 200, 20);
        			warningButton.setBounds(120, 90, 60, 20);		
        			content.add(warningJLabel);
        			content.add(warningButton);
        			double lx=Toolkit.getDefaultToolkit().getScreenSize().getWidth();
        		    double ly=Toolkit.getDefaultToolkit().getScreenSize().getHeight();
        		    warningframe.setLocation(new Point((int)(lx/2+100),(int)(ly/2)));//设定窗口出现位置
        			warningframe.setVisible(true);
        			//warningframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//使能关闭窗口，结束程序
        			
        			warningButton.addActionListener(new ActionListener(){       		
						@Override
						public void actionPerformed(ActionEvent e) {
							// TODO Auto-generated method stub
							warningframe.dispose();
						}
        			});
        		}
       	    statusBoolean=false;
       	    text3.setText("");
        	}   
        	//System.out.println("终于退出了该死的循环");
        }
        if(e.getSource().equals(button5)){
            //刷新
        	int count = 1;
        	for(int i=0;i<d2.length;i++){
        		if(d2[i][1]!=null){
                	count++ ;
        		}
        	}
        	label8.setText("当前在线的用户数目："+count);
        	Button5Refresh();
        	updatedialog();
        	//将object数组的转化分开写成一个新函数，在refresh中调用这个函数实现列表的刷新
        	
        	
           }
        if(e.getSource().equals(button6)){
        	//点击退出
        	//myfilelist.list.clear();
        	new Thread(new MultiBroadSendFilelist(2)).start();
        	updatedialog();
        	System.exit(0);
        }
    }
    
    private void Button3Refresh() {
		// TODO Auto-generated method stub
    	/*
    	 * 清空列表并重新添加
    	 */
    	
    	//System.out.println(myfilelist.list.size());
    	for(int i=0;i<myfilelist.list.size();i++){   		
			d[i][0]=myfilelist.list.get(i).getFile_name(); 	
			d[i][1]=myfilelist.list.get(i).getFile_address(); 				
    	}	
		new Thread(new MultiBroadSendFilelist(1)).start();
    	updatedialog();
		//new YFileChooser();
    	//System.out.println("123");
    	
	}
    private void Button5Refresh() {
		// TODO Auto-generated method stub
    	/*
    	 * 更新IP列表
    	 */
    	String AllLocalIP;
		try {
			AllLocalIP = InetAddress.getLocalHost().toString();
			local_ip =	AllLocalIP.substring(AllLocalIP.indexOf("/") + 1, AllLocalIP.length());	
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		label11.setText("当前IP地址为："+local_ip);
		filelist.list.clear();
		for(int i=0;i<d1.length;i++){
			d1[i][0]=null;
			d1[i][1]=null;
			d1[i][2]=null;
		}
		new Thread(new MultiBroadSendFilelist(0)).start();
		try {
			Thread.sleep(100);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	updatedialog();
	}
	

	public static void main(String[] args) {

        new YFileChooser();
    }
	
	public static void setUIFont()
	{
		Font f = new Font("宋体",Font.PLAIN,13);
		String   names[]={ "Label", "CheckBox", "PopupMenu","MenuItem", "CheckBoxMenuItem",
				"JRadioButtonMenuItem","ComboBox", "Button", "Tree", "ScrollPane",
				"TabbedPane", "EditorPane", "TitledBorder", "Menu", "TextArea",
				"OptionPane", "MenuBar", "ToolBar", "ToggleButton", "ToolTip",
				"ProgressBar", "TableHeader", "Panel", "List", "ColorChooser",
				"PasswordField","TextField", "Table", "Label", "Viewport",
				"RadioButtonMenuItem","RadioButton", "DesktopPane", "InternalFrame"
		}; 
		for (String item : names) {
			 UIManager.put(item+ ".font",f); 
		}
	}     
}
 

