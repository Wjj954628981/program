package javatest;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class homework1p {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
		    Class.forName("com.mysql.jdbc.Driver");
		    Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "1996wangjiajie.");
		    String sql="insert into user values(null,?,?,?)";
		    PreparedStatement pstmt =  conn.prepareStatement(sql);
		    long begin = System.currentTimeMillis();
		    for(int i=1;i<=100;i++){
		    	pstmt.setString(1, "user"+i);
		    	pstmt.setString(2, i+"");
		    	pstmt.setInt(3, i*50);
		    	pstmt.executeUpdate();
		    }
		    long end = System.currentTimeMillis();
		    System.out.println("成功插入数据,用时"+(end-begin)+"ms");
		    pstmt.close();
		    conn.close();
		}catch(ClassNotFoundException e){
			e.printStackTrace();
		}catch(SQLException e){
			e.printStackTrace();
		}
	}

}
