package javatest;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import java.util.Scanner; 

public class homework3 {
	@SuppressWarnings("resource")
	public static void main(String[] args){
		// TODO Auto-generated method stub
		boolean b=false;
		do{
			System.out.println("�����û�����");
			String username=new Scanner(System.in).nextLine();  
			System.out.println("�������룺");
			String password=new Scanner(System.in).nextLine();  
			if(username == null){
				System.out.println("�û���Ϊ��");
			}else{
				if(password==null){
					System.out.println("����Ϊ��");
				}else{
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
					    String sql = "select * from user where username='"+username+"' and password='"+password+"'";

					    //����5---����������Ĳ�ѯ����������SQL��䣬���ؽ�������� 
					    ResultSet rs = stmt.executeQuery(sql);

					    //����6---ʹ��whileѭ�����������������next()������ָ���ƶ�����һ����¼
					    if(rs.next()){
						//����7---ʹ�ý���������getXXX()������ȡ��ǰ��¼�в�ͬ�������͵��ֶ�ֵ
//					    	System.out.println(rs.getInt(1)+"-"+rs.getString(2)+"-"+rs.getString(3)+"-"+rs.getInt(4));
//					    	System.out.println(rs.getString(1)+"-"+rs.getString(2));
					    	System.out.println("��½�ɹ�");
					    	b=true;
					    }else{
					    	System.out.println("��½ʧ��");
					    	System.out.println("�Ƿ������½��y/n��");
					    	String choose=new Scanner(System.in).nextLine();
					    	if(choose.equals("n")){
					    		b=true;
					    	}
					    	if(choose.equals("y")){
					    		b=false;
					    	}  	
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
		}while(b==false);
	}
}
