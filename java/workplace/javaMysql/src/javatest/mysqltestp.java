package javatest;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;


public class mysqltestp {
	public static void main(String[] args){
		try{
			//����1---ͨ������ʵ�������ݿ�������
		    //Class.forName("���������ݿ���������");  
		    Class.forName("com.mysql.jdbc.Driver");

		    //����2---����DriverManager�ľ�̬����������ȡ���ݿ����Ӷ���
		    //Connection conn = DriverManager.getConnection("jdbc:mysql://���ݿ����ڵ���������IP��ַ:�˿ں�/���ݿ���", "�������ݿ���û���", "�������ݿ������"); 
		    Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "1996wangjiajie.");
			
		  //����4---׼��������SQL���
		    String sql = "select username,password from user where score>?";
		    
		    //����3---�������Ӷ���Ĺ�����������������
		    PreparedStatement pstmt =  conn.prepareCall(sql);     

		    
		    pstmt.setInt(1, 20);

		    //����5---����������Ĳ�ѯ����������SQL��䣬���ؽ�������� 
		    ResultSet rs = pstmt.executeQuery();

		    //����6---ʹ��whileѭ�����������������next()������ָ���ƶ�����һ����¼
		    while(rs.next()){
			//����7---ʹ�ý���������getXXX()������ȡ��ǰ��¼�в�ͬ�������͵��ֶ�ֵ
//		    	System.out.println(rs.getInt(1)+"-"+rs.getString(2)+"-"+rs.getString(3)+"-"+rs.getInt(4));
		    	System.out.println(rs.getString(1)+"-"+rs.getString(2));
		    }
		    
		    //����8---�رս�����������������ݿ����Ӷ���
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
