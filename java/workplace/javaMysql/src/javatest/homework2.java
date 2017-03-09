package javatest;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import java.util.Scanner; 

public class homework2 {

	@SuppressWarnings("resource")
	public static void main(String[] args){
		// TODO Auto-generated method stub
		System.out.println("输入用户名：");
		String username=new Scanner(System.in).nextLine();  
//		char username1 = (char) System.in.read();
//		String username=String.valueOf(username1);
		System.out.println("输入密码：");
		String password=new Scanner(System.in).nextLine();  
//		char password1 = (char) System.in.read(); 
//		String password=String.valueOf(password1);
		if(username == null){
			System.out.println("用户名为空");
		}else{
			if(password==null){
				System.out.println("密码为空");
			}else{
				try{
					//步骤1---通过反射实例化数据库驱动类
				    //Class.forName("完整的数据库驱动类名");  
				    Class.forName("com.mysql.jdbc.Driver");

				    //步骤2---调用DriverManager的静态工厂方法获取数据库连接对象
				    //Connection conn = DriverManager.getConnection("jdbc:mysql://数据库所在的主机名或IP地址:端口号/数据库名", "连接数据库的用户名", "连接数据库的密码"); 
				    Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "1996wangjiajie.");
					
				    //步骤3---调用连接对象的工厂方法创建语句对象
				    Statement stmt =  conn.createStatement();     

				    //步骤4---准备完整的SQL语句
				    String sql = "select * from user where username='"+username+"' and password='"+password+"'";

				    //步骤5---调用语句对象的查询方法，传入SQL语句，返回结果集对象 
				    ResultSet rs = stmt.executeQuery(sql);

				    //步骤6---使用while循环遍历结果集，调用next()方法将指针移动到下一条记录
				    if(rs.next()){
					//步骤7---使用结果集对象的getXXX()方法获取当前记录中不同数据类型的字段值
//				    	System.out.println(rs.getInt(1)+"-"+rs.getString(2)+"-"+rs.getString(3)+"-"+rs.getInt(4));
//				    	System.out.println(rs.getString(1)+"-"+rs.getString(2));
				    	System.out.println("登陆成功");
				    }else{
				    	System.out.println("登陆失败");
				    }
				    
				    //步骤8---关闭结果集对象，语句对象，数据库连接对象
				    rs.close();
				    stmt.close();
				    conn.close();
				}catch(ClassNotFoundException e){
					e.printStackTrace();
				}catch(SQLException e){
					e.printStackTrace();
				}
			}
		}
	}

}
