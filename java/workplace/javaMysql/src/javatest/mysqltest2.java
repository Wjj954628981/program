package javatest;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class mysqltest2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
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
		    String sql = "insert into user values(null,'user5','5',50)";

		    //����5---����������Ĳ�ѯ����������SQL��䣬���ؽ�������� 
		    int rows=stmt.executeUpdate(sql);

		    //����6---ʹ��whileѭ�����������������next()������ָ���ƶ�����һ����¼
		    if(rows>0){
		    	System.out.println("����ɹ�");
		    }else{
		    	System.out.println("����ʧ��");
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
