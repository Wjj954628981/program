package javatest;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class mysqltest2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
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
		    String sql = "insert into user values(null,'user5','5',50)";

		    //步骤5---调用语句对象的查询方法，传入SQL语句，返回结果集对象 
		    int rows=stmt.executeUpdate(sql);

		    //步骤6---使用while循环遍历结果集，调用next()方法将指针移动到下一条记录
		    if(rows>0){
		    	System.out.println("插入成功");
		    }else{
		    	System.out.println("插入失败");
		    }
		    stmt.close();
		    conn.close();
		}catch(ClassNotFoundException e){
			e.printStackTrace();
		}catch(SQLException e){
			e.printStackTrace();
		}
	}
}
