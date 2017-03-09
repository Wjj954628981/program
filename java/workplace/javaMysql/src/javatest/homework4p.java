package javatest;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import java.util.Scanner; 

public class homework4p {

	@SuppressWarnings({ "resource", "unused" })
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		boolean b=false;
		do{
			System.out.println("输入用户名：");
			String username=new Scanner(System.in).nextLine();  
			System.out.println("输入密码：");
			String password=new Scanner(System.in).nextLine();  
			if(username == null){
				System.out.println("用户名为空");
			}else{
				if(password==null){
					System.out.println("密码为空");
				}else{
					try{
					    Class.forName("com.mysql.jdbc.Driver");
					    Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "1996wangjiajie.");
					    Statement stmt =  conn.createStatement();     

					    //步骤4---准备完整的SQL语句
					    String sql = "select * from user where username='"+username+"' and password='"+password+"'";

					    //步骤5---调用语句对象的查询方法，传入SQL语句，返回结果集对象 
					    ResultSet rs = stmt.executeQuery(sql);

					    //步骤6---使用while循环遍历结果集，调用next()方法将指针移动到下一条记录
					    if(rs.next()){
						//步骤7---使用结果集对象的getXXX()方法获取当前记录中不同数据类型的字段值
//					    	System.out.println(rs.getInt(1)+"-"+rs.getString(2)+"-"+rs.getString(3)+"-"+rs.getInt(4));
//					    	System.out.println(rs.getString(1)+"-"+rs.getString(2));
					    	boolean b2=false;
					    	System.out.println("登陆成功");
					    	do{
						    	System.out.println("1.查询全部用户");
						    	System.out.println("2.插入新用户");
						    	System.out.println("3.删除用户");
						    	System.out.println("4.修改用户密码");
						    	System.out.println("5.退出程序");
						    	int a=new Scanner(System.in).nextInt();
						    	switch(a){
						    	case 1:
									String sql1 =  " select * from user " ;
									Statement stmt1 = conn.createStatement();
									ResultSet rs1 = stmt1.executeQuery(sql1);
								    while (rs1.next()){
									System.out.println(rs1.getInt(1) + "-" + rs1.getString(2) + "-" + rs1.getString(3) + "-" +rs1.getInt(4));
								    }
								    b2=false;
								    break;
								case 2:
									System.out.println("请输入用户名和密码");
								    String a2=new Scanner(System.in).nextLine();
								    String b21=new Scanner(System.in).nextLine();
								    Statement stmt2 = conn.createStatement();
								    String sql2= "insert into user values (null"+","+"'"+a2+"'"+","+"'"+b21+"'"+","+ 10 +") "; 
								    stmt2.executeUpdate(sql2);
								    System.out.println("插入成功");
								    b2=false;
								    break;
								case 3:
									System.out.println("请指定想要删除的编号");
									String a3=new Scanner(System.in).nextLine();
									Statement stmt3 = conn.createStatement();
									String sql3 = "delete from user where userid = "+a3;
									stmt3.executeUpdate(sql3);
									b2=false;
									break;
								case 4:
									System.out.println("请输入用户名和新密码");
									String a4=new Scanner(System.in).nextLine();
								    String b4=new Scanner(System.in).nextLine();
									Statement stmt4 = conn.createStatement();
									String sql4 = "update user set  password="+"'"+ b4 +"'"+"where username="+"'"+ a4 +"'" ;
									stmt4.executeUpdate(sql4);
									b2=false;
									break;
								case 5:	
									System.exit(0);
						    	}
						    			
					    	}while(b==false);
					    	
					    	b=true;
					    }else{
					    	System.out.println("登陆失败");
					    	System.out.println("是否继续登陆（y/n）");
					    	String choose=new Scanner(System.in).nextLine();
					    	if(choose.equals("n")){
					    		b=true;
					    	}
					    	if(choose.equals("y")){
					    		b=false;
					    	}  	
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
		}while(b==false);
	}

}
