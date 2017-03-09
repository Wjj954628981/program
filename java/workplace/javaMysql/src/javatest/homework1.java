package javatest;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class homework1 {

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

		    for(int i=1;i<=100;i++){
		    	//步骤4---准备完整的SQL语句
		    String stringi=String.valueOf(i);
		    String string1 = "user"+i;
//		    int score=10*i;
		    String sql = "insert into user values(null,'"+string1+"','"+stringi+"','"+10*i+"')";

//			    //步骤5---调用语句对象的更新方法，传入SQL语句，返回本次更新所影响的记录行数，行数>0---表示更新成功 行数=0---找不到要更新的数据 行数<0---更新失败
			    stmt.executeUpdate(sql);
		    }
		  //步骤6---关闭语句对象和数据库连接对象
		    stmt.close();
		    conn.close();
		}catch(ClassNotFoundException e){
			e.printStackTrace();
		}catch(SQLException e){
			e.printStackTrace();
		}
	}

}
