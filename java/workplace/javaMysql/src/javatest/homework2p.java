package javatest;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import java.util.Scanner; 

public class homework2p {

	@SuppressWarnings("resource")
	public static void main(String[] args){
		// TODO Auto-generated method stub
		Scanner cs = new Scanner(System.in);
		System.out.println("�����û�����");
		String username=cs.nextLine();  
		System.out.println("�������룺");
		String password=cs.nextLine();  
		if(username == null){
			System.out.println("�û���Ϊ��");
		}else{
			if(password==null){
				System.out.println("����Ϊ��");
			}else{
				try{ 
				    Class.forName("com.mysql.jdbc.Driver");
				    Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "1996wangjiajie.");
				    String sql = "select * from user where username=? and password=?";
				    PreparedStatement pstmt =  conn.prepareStatement(sql);
				    pstmt.setString(1, username);
				    pstmt.setString(2, password);
				    ResultSet rs = pstmt.executeQuery();
				    if(rs.next()){
				    	System.out.println("��½�ɹ�");
				    }else{
				    	System.out.println("��½ʧ��");
				    }
				    rs.close();
				    pstmt.close();
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
