package javatest;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import java.util.Scanner; 

public class homework4p {

	@SuppressWarnings({ "resource", "unused" })
	public static void main(String[] args) {
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
					    Class.forName("com.mysql.jdbc.Driver");
					    Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "1996wangjiajie.");
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
					    	boolean b2=false;
					    	System.out.println("��½�ɹ�");
					    	do{
						    	System.out.println("1.��ѯȫ���û�");
						    	System.out.println("2.�������û�");
						    	System.out.println("3.ɾ���û�");
						    	System.out.println("4.�޸��û�����");
						    	System.out.println("5.�˳�����");
						    	int a=new Scanner(System.in).nextInt();
						    	switch(a){
						    	case 1:
									String sql1 =  " select * from user " ;
									Statement stmt1 = conn.createStatement();
									ResultSet rs1 = stmt1.executeQuery(sql1);
								    while (rs1.next()){
									System.out.println(rs1.getInt(1) + "-" + rs1.getString(2) + "-" + rs1.getString(3) + "-" +rs1.getInt(4));
								    }
								    b2=false;
								    break;
								case 2:
									System.out.println("�������û���������");
								    String a2=new Scanner(System.in).nextLine();
								    String b21=new Scanner(System.in).nextLine();
								    Statement stmt2 = conn.createStatement();
								    String sql2= "insert into user values (null"+","+"'"+a2+"'"+","+"'"+b21+"'"+","+ 10 +") "; 
								    stmt2.executeUpdate(sql2);
								    System.out.println("����ɹ�");
								    b2=false;
								    break;
								case 3:
									System.out.println("��ָ����Ҫɾ���ı��");
									String a3=new Scanner(System.in).nextLine();
									Statement stmt3 = conn.createStatement();
									String sql3 = "delete from user where userid = "+a3;
									stmt3.executeUpdate(sql3);
									b2=false;
									break;
								case 4:
									System.out.println("�������û�����������");
									String a4=new Scanner(System.in).nextLine();
								    String b4=new Scanner(System.in).nextLine();
									Statement stmt4 = conn.createStatement();
									String sql4 = "update user set  password="+"'"+ b4 +"'"+"where username="+"'"+ a4 +"'" ;
									stmt4.executeUpdate(sql4);
									b2=false;
									break;
								case 5:	
									System.exit(0);
						    	}
						    			
					    	}while(b==false);
					    	
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
