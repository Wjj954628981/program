package javatest;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;


public class mysqltest {
	public static void main(String[] args){
		try{
			//����1---ͨ������ʵ�������ݿ�������
		    //Class.forName("���������ݿ���������");  
		    Class.forName("com.mysql.jdbc.Driver");

		    //����2---����DriverManager�ľ�̬����������ȡ���ݿ����Ӷ���
		    //Connection conn = DriverManager.getConnection("jdbc:mysql://���ݿ����ڵ���������IP��ַ:�˿ں�/���ݿ���", "�������ݿ���û���", "�������ݿ������"); 
		    Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "1996wangjiajie.");
			
		    //����3---�������Ӷ���Ĺ�����������������
		    Statement stmt =  conn.createStatement();     

		    //����4---׼��������SQL���
		    String sql = "select username,password from user where score>20";

		    //����5---����������Ĳ�ѯ����������SQL��䣬���ؽ�������� 
		    ResultSet rs = stmt.executeQuery(sql);

		    //����6---ʹ��whileѭ�����������������next()������ָ���ƶ�����һ����¼
		    while(rs.next()){
			//����7---ʹ�ý���������getXXX()������ȡ��ǰ��¼�в�ͬ�������͵��ֶ�ֵ
//		    	System.out.println(rs.getInt(1)+"-"+rs.getString(2)+"-"+rs.getString(3)+"-"+rs.getInt(4));
		    	System.out.println(rs.getString(1)+"-"+rs.getString(2));
		    }
		    
		    //����8---�رս�����������������ݿ����Ӷ���
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
