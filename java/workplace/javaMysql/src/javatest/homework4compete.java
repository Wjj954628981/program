package javatest;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;

public class homework4compete {
	@SuppressWarnings("resource")
	public static void main (String args[]){
		try {
			//����1---ͨ������ʵ�������ݿ�������
			//Class.forName("���������ݿ���������");  
			Class.forName("com.mysql.jdbc.Driver");
			//����2---����DriverManager�ľ�̬����������ȡ���ݿ����Ӷ���
			//Connection conn = DriverManager.getConnection("jdbc:mysql://���ݿ����ڵ���������IP��ַ:�˿ں�/���ݿ���", "�������ݿ���û���", "�������ݿ������"); 
			Connection conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/test", "root", "1996wangjiajie.");		
			//����3---�������Ӷ���Ĺ�����������������
			Statement stmt = conn.createStatement();
			boolean K = true;
			while(K){
			System.out.println("�������û���������");
			Scanner scanner = new Scanner(System.in); 
			String username , password;
			username = scanner.next();
			password = scanner.next();
			//����4---׼��������SQL���
			//String sql= "insert into user values (null,'1412641','7',80) "; 
			String sql =  " select * from user where username = " + "'" + username + "'" + "and password="+"'"+ password +"'"  ;
			//����5---����������ĸ��·���������SQL��䣬���ر��θ�����Ӱ��ļ�¼����������>0---��ʾ���³ɹ� ����=0---�Ҳ���Ҫ���µ����� ����<0---����ʧ��
			ResultSet rs = stmt.executeQuery(sql);
			
			if (rs.next()){
				System.out.println("��½�ɹ�");
				K = false;
				System.out.println("��ѡ����Ҫִ�еĲ���1-5");
				System.out.println("1.��ѯȫ���û�");
				System.out.println("2.�������û�");
				System.out.println("3.ɾ���û�");
				System.out.println("4.�޸��û�����");
				System.out.println("5.�˳�����");
				int c;
				c= scanner.nextInt();
				switch(c){
				case 1:
					String sql1 =  " select * from user " ;
					Statement stmt1 = conn.createStatement();
					ResultSet rs1 = stmt1.executeQuery(sql1);
				    while (rs1.next()){
					System.out.println(rs1.getInt(1) + "-" + rs1.getString(2) + "-" + rs1.getString(3) + "-" +rs1.getInt(4));
				    }
				    break;
				case 2:
					System.out.println("�������û���������");
				    String a2,b2;
				    a2=scanner.next();b2=scanner.next();
				    Statement stmt2 = conn.createStatement();
				    String sql2= "insert into user values (null"+","+"'"+a2+"'"+","+"'"+b2+"'"+","+ 10 +") "; 
				    System.out.println(sql2);
				    stmt2.executeUpdate(sql2);
				    break;
				case 3:
					System.out.println("��ָ����Ҫɾ���ı��");
					String a3;
					a3=scanner.next();
					Statement stmt3 = conn.createStatement();
					String sql3 = "delete from user where userid = "+a3;
					stmt3.executeUpdate(sql3);
					break;
				case 4:
					System.out.println("�������û�����������");
					String a4,b4;
					a4=scanner.next();b4=scanner.next();
					Statement stmt4 = conn.createStatement();
					String sql4 = "update user set  password="+"'"+ b4 +"'"+"where username="+"'"+ a4 +"'" ;
					stmt4.executeUpdate(sql4);
					break;
				case 5:	
					System.exit(0);
				}
			}else{
				System.out.println("��¼ʧ��,�Ƿ���Ҫ��������(y/n)");
				String a;
				a = scanner.next();
				if(a.equals("N")|| a.equals("n")){
					System.exit(0);
					break;
				}
			}
			}
			//����6---�ر�����������ݿ����Ӷ���
			stmt.close();
			conn.close();
		    
		}catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		}
}
