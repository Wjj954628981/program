package Painter;

import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import javax.swing.*;

public class MyFrame extends JFrame{
	private JButton curve,line,rectangle,oval;
	private JButton color = new JButton("选择颜色");
	private JButton jbt = new JButton("清空");
	private JButton save = new JButton("保存");
	private JButton open = new JButton("打开");
//	CheckboxGroup fillc=new CheckboxGroup();
//	private Checkbox fill=new Checkbox("填充",fillc,true);
//	private Checkbox unfill=new Checkbox("非填充",fillc,false);
	private JButton fill = new JButton("填充");
	private JButton unfill = new JButton("非填充");
	private Paint paint = new Paint();  //画图的界面
	private int type;
	private int fillingType=2;
	private Color colorType;
	private int x1,x2,y1,y2;
	public MyFrame(){
		JPanel jp1 = new JPanel();
		jp1.setLayout(new GridLayout(10,1));
		jp1.add(fill);
		jp1.add(unfill);
		jp1.add(curve = new JButton("画笔"));
		jp1.add(line = new JButton("直线"));
		jp1.add(rectangle = new JButton("矩形"));
		jp1.add(oval = new JButton("椭圆"));
		jp1.add(color);
		jp1.add(jbt);
		jp1.add(save);
		jp1.add(open);
		setLayout(new BorderLayout());
		add(jp1, BorderLayout.WEST);
		add(paint, BorderLayout.CENTER);
		
		paint.addMouseListener(new PressListener());
		paint.addMouseMotionListener(new DragListener());
		
/*		fill.addItemListener(new ItemListener(){
			public void itemStateChanged(ItemEvent e) {
				fillingType=1;
			}
		});
		unfill.addItemListener(new ItemListener(){
			public void itemStateChanged(ItemEvent e) {
				fillingType=2;
			}
		});*/
		fill.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				fillingType=1;
			}
		});
		unfill.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				fillingType=2;
			}
		});
		line.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				type = 1;
			}
		});
		rectangle.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				type = 2;
			}
		});
		oval.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				type = 3;
			}
		});
		curve.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				type = 4;
			}
		});
		color.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				colorType=JColorChooser.showDialog(null, "请选择颜色", Color.BLUE);
			}
		});
		jbt.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				paint.setIsClear(true);
				paint.repaint();
				paint.clear();
			}
		});
		save.addActionListener(new saveaction(paint));
		open.addActionListener(new readaction(paint));
	}
	public static void main(String[] args){
		MyFrame frame = new MyFrame();
		frame.setTitle("JAVA画图本");
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(500,400);
		frame.setVisible(true);
	}
	class PressListener extends MouseAdapter {
		public void mousePressed(MouseEvent e){
			paint.setType(type, fillingType, colorType);
			x1 = e.getX();
			y1 = e.getY();
			paint.setLocation1(x1, y1);  //设定每次画图开始坐标
		}
	}
	class DragListener extends MouseMotionAdapter {
		public void mouseDragged(MouseEvent e){
			x2 = e.getX();
			y2 = e.getY();
			paint.setLocation2(x2, y2);  //设定每个瞬间的坐标
			paint.repaint();
		}
	}
	class saveaction implements ActionListener
	{
		Paint x;
		saveaction(Paint a)
		{
			x=a;
		}
		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			BufferedImage image = new BufferedImage(x.getWidth(),x.getHeight(), BufferedImage.TYPE_INT_RGB);   
			Graphics2D g2 =(Graphics2D) image.getGraphics(); 
			x.paint(g2); 
			x.save(image);
			
		}
		
	}
	class readaction implements ActionListener
	{
		Paint x;
		readaction(Paint a)
		{
			x=a;
		}
		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			x.read();
		}	
	}
    class Paint extends JPanel{
    	private int[] type = new int[100];
    	private int[] fillingType = new int[100];
    	private Color[] colorType = new Color[100];
    	private int[] xStart = new int[100];
    	private int[] yStart = new int[100];
    	private int[][] xEnd = new int[100][10000];
    	private int[][] yEnd = new int[100][10000];
    	private int[] num = new int[100];   //每次画图实际经过的点数(除了开始那点外)
    	private int[] x;  //用于curve
    	private int[] y;  //用于curve
    	private int count,count1;  //前者记录清空后已画图形数目。后者记录某一次画的瞬间已经过的点数（除了开始点）
    	private boolean isClear = false;  //用于判断是否要清空。
    	public Image readimage;
    	
    	void setColor(Color colorType){
    			setForeground(colorType);
    	}
    	void setType(int type, int fillingType, Color colorType){
    		count++;
    		if ((count) >= this.type.length){
    			this.type = expand(this.type);
    			this.fillingType = expand(this.fillingType);
    			this.colorType = expand(this.colorType);
    			xStart = expand(xStart);
    			yStart = expand(yStart);
    			xEnd = expand(xEnd);
    			yEnd = expand(yEnd);
    			num = expand(num);
    		}
    			this.type[count] = type;
    			this.fillingType[count] = fillingType;
    			this.colorType[count] = colorType;
    	}
    	void setLocation1(int x1, int y1){
    		count1 = 0;
    		if (type[count] !=4){
    			this.xStart[count] = x1;
    			this.yStart[count] = y1;
    		}
    		else{
    			xEnd[count][0] = x1;
    			yEnd[count][0] = y1;
    		}
    	}
    	void setLocation2(int x2, int y2){
    		count1++;
    		num[count] = count1;
    		if (count1 >= xEnd[0].length){
    			xEnd = expand(xEnd);
    			yEnd = expand(yEnd);
    		}
    		xEnd[count][count1] = x2;
    		yEnd[count][count1] = y2;
    	}
    	void setIsClear(boolean isClear){
    		this.isClear = isClear;
    	}

    	void save(BufferedImage bImage)
    	{
    	//把图像保存为文件
    	JFileChooser chooser=new JFileChooser();//文件保存对话框
    	if(chooser.showSaveDialog(null)==JFileChooser.APPROVE_OPTION)
    	{
    	File oFile=chooser.getSelectedFile();
    	try
    	{
    	ImageIO.write(bImage, "jpeg", oFile);//保存图像文件
    	}catch(IOException ex)
    	{
    	ex.printStackTrace();
    	}
    	}
    	}
    	void read()
    	{
    		JFileChooser chooser= new JFileChooser();
    		if(chooser.showSaveDialog(null)==JFileChooser.APPROVE_OPTION)
    		{
    		File oFile=chooser.getSelectedFile();
    		try
    		{
    		readimage = ImageIO.read(oFile);//打开图像文件
    		}catch(IOException ex)
    		{
    		ex.printStackTrace();
    		}
    		}
    		this.repaint();
    	}
    	void convert(int number1, int number2){
    		x = new int[number2 + 1];
    		y = new int[number2 + 1];
    		for(int i=0;i <= number2;i++){
    			x[i] = xEnd[number1][i];
    			y[i] = yEnd[number1][i];
    		}
    	}
    	void clear(){
    		for (int i = 0;i <= count; i++){
    			xStart[i] = 0;
    			yStart[i] = 0;
    			for (int j = 0; j <= num[i]; j++){
    				xEnd[i][j] = 0;
    				yEnd[i][j] = 0;
    			}
    			num[i] = 0;
    		}
    		count = 0;
    		count1 = 0;	
    		isClear = false;
    	}
    	int[] expand(int[] list){
    		int number = list.length;
    		int[] temper = new int[2 * number];
    		for (int i = 0; i < number; i++){
    			temper[i] = list[i];
    		}
    		return temper;
    	}
    	Color[] expand(Color[] list){
    		int number = list.length;
    		Color[] temper = new Color[2 * number];
    		for (int i = 0; i < number; i++){
    			temper[i] = list[i];
    		}
    		return temper;
    	}
    	int[][] expand(int[][] list){
    		int number1 = list.length;
    		int number2 = list[0].length;
    		int[][] temper = new int[2 * number1][2 * number2];
    		for (int i = 0; i < number1; i++){
    			for (int j = 0; j < number2; j++){
    				temper[i][j] = list[i][j];
    			}
    		}
    		return temper;
    	}
    	protected void paintComponent(Graphics g){
    		super.paintComponent(g);
    		if (isClear){
    			return;
    		}
    		else{
    			for (int i = 1;i <= count;i++){
    				setColor(colorType[i]);
    				g.setColor(getForeground());
    				int j = num[i];
    				int xTemper = (xEnd[i][j] - xStart[i]) > 0? (xEnd[i][j] - xStart[i]): Math.abs(xEnd[i][j] - xStart[i]);
    				int yTemper = (yEnd[i][j] - yStart[i]) > 0? (yEnd[i][j] - yStart[i]): Math.abs(yEnd[i][j] - yStart[i]);
    				if(fillingType[i]==1){
    					switch (type[i]){
        				case 1:
        					g.drawLine(xStart[i], yStart[i], xEnd[i][j], yEnd[i][j]);
        					break;
        				case 2:
        					if(xEnd[i][j] - xStart[i] > 0)
        					    g.fillRect(xStart[i], yStart[i], xTemper, yTemper);
        					else
        						g.fillRect(xEnd[i][j], yStart[i], xTemper, yTemper);
        					break;
        				case 3:
        					if(xEnd[i][j] - xStart[i] > 0)
        					    g.fillOval(xStart[i], yStart[i], xTemper, yTemper);
        					else
        						g.fillOval(xEnd[i][j], yStart[i], xTemper, yTemper);
        					break;
        				case 4:
        					convert(i , j);
        					g.drawPolyline(x, y, x.length);
        				}
    				}
    				if(fillingType[i]==2){
    					switch (type[i]){
        				case 1:
        					g.drawLine(xStart[i], yStart[i], xEnd[i][j], yEnd[i][j]);
        					break;
        				case 2:
        					if(xEnd[i][j] - xStart[i] > 0)
        					    g.drawRect(xStart[i], yStart[i], xTemper, yTemper);
        					else
        						g.drawRect(xEnd[i][j], yStart[i], xTemper, yTemper);
        					break;
        				case 3:
        					if(xEnd[i][j] - xStart[i] > 0)
        					    g.drawOval(xStart[i], yStart[i], xTemper, yTemper);
        					else
        						g.drawOval(xEnd[i][j], yStart[i], xTemper, yTemper);
        					break;
        				case 4:
        					convert(i , j);
        					g.drawPolyline(x, y, x.length);
        				}
    				}
    		    }
    			g.drawImage(readimage,Paint.WIDTH,Paint.HEIGHT,null);
    		}
    	}
    }
 }