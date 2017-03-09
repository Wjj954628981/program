package javatest;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;

public class homework4compete {
	@SuppressWarnings("resource")
	public static void main (String args[]){
		try {
			//步骤1---通过反射实例化数据库驱动类
			//Class.forName("完整的数据库驱动类名");  
			Class.forName("com.mysql.jdbc.Driver");
			//步骤2---调用DriverManager的静态工厂方法获取数据库连接对象
			//Connection conn = DriverManager.getConnection("jdbc:mysql://数据库所在的主机名或IP地址:端口号/数据库名", "连接数据库的用户名", "连接数据库的密码"); 
			Connection conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/test", "root", "1996wangjiajie.");		
			//步骤3---调用连接对象的工厂方法创建语句对象
			Statement stmt = conn.createStatement();
			boolean K = true;
			while(K){
			System.out.println("请输入用户名和密码");
			Scanner scanner = new Scanner(System.in); 
			String username , password;
			username = scanner.next();
			password = scanner.next();
			//步骤4---准备完整的SQL语句
			//String sql= "insert into user values (null,'1412641','7',80) "; 
			String sql =  " select * from user where username = " + "'" + username + "'" + "and password="+"'"+ password +"'"  ;
			//步骤5---调用语句对象的更新方法，传入SQL语句，返回本次更新所影响的记录行数，行数>0---表示更新成功 行数=0---找不到要更新的数据 行数<0---更新失败
			ResultSet rs = stmt.executeQuery(sql);
			
			if (rs.next()){
				System.out.println("登陆成功");
				K = false;
				System.out.println("请选择想要执行的操作1-5");
				System.out.println("1.查询全部用户");
				System.out.println("2.插入新用户");
				System.out.println("3.删除用户");
				System.out.println("4.修改用户密码");
				System.out.println("5.退出程序");
				int c;
				c= scanner.nextInt();
				switch(c){
				case 1:
					String sql1 =  " select * from user " ;
					Statement stmt1 = conn.createStatement();
					ResultSet rs1 = stmt1.executeQuery(sql1);
				    while (rs1.next()){
					System.out.println(rs1.getInt(1) + "-" + rs1.getString(2) + "-" + rs1.getString(3) + "-" +rs1.getInt(4));
				    }
				    break;
				case 2:
					System.out.println("请输入用户名和密码");
				    String a2,b2;
				    a2=scanner.next();b2=scanner.next();
				    Statement stmt2 = conn.createStatement();
				    String sql2= "insert into user values (null"+","+"'"+a2+"'"+","+"'"+b2+"'"+","+ 10 +") "; 
				    System.out.println(sql2);
				    stmt2.executeUpdate(sql2);
				    break;
				case 3:
					System.out.println("请指定想要删除的编号");
					String a3;
					a3=scanner.next();
					Statement stmt3 = conn.createStatement();
					String sql3 = "delete from user where userid = "+a3;
					stmt3.executeUpdate(sql3);
					break;
				case 4:
					System.out.println("请输入用户名和新密码");
					String a4,b4;
					a4=scanner.next();b4=scanner.next();
					Statement stmt4 = conn.createStatement();
					String sql4 = "update user set  password="+"'"+ b4 +"'"+"where username="+"'"+ a4 +"'" ;
					stmt4.executeUpdate(sql4);
					break;
				case 5:	
					System.exit(0);
				}
			}else{
				System.out.println("登录失败,是否需要重新输入(y/n)");
				String a;
				a = scanner.next();
				if(a.equals("N")|| a.equals("n")){
					System.exit(0);
					break;
				}
			}
			}
			//步骤6---关闭语句对象和数据库连接对象
			stmt.close();
			conn.close();
		    
		}catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		}
}
