package javatest;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class homework1 {

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

		    for(int i=1;i<=100;i++){
		    	//����4---׼��������SQL���
		    String stringi=String.valueOf(i);
		    String string1 = "user"+i;
//		    int score=10*i;
		    String sql = "insert into user values(null,'"+string1+"','"+stringi+"','"+10*i+"')";

//			    //����5---����������ĸ��·���������SQL��䣬���ر��θ�����Ӱ��ļ�¼����������>0---��ʾ���³ɹ� ����=0---�Ҳ���Ҫ���µ����� ����<0---����ʧ��
			    stmt.executeUpdate(sql);
		    }
		  //����6---�ر�����������ݿ����Ӷ���
		    stmt.close();
		    conn.close();
		}catch(ClassNotFoundException e){
			e.printStackTrace();
		}catch(SQLException e){
			e.printStackTrace();
		}
	}

}
