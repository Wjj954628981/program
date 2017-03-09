package Collection;

import java.util.Comparator;
import java.util.TreeSet;

public class Student {
	public String name;
	public int number;
	public int[] score=new int[10];
	public double average;
	public int max;
	public int min;
	public Student(String name,int number){
		this.name=name;
		this.number=number;
		double sum=0;
		for(int i=0;i<10;i++){
			score[i]=(int)(Math.random()*100+1);
		}
		max=min=score[0];
		for(int i=1;i<10;i++){
			sum=sum+score[i];
			if(max<score[i]){
				max=score[i];
			}
			if(min>score[i]){
				min=score[i];
			}
		}
		average=sum/10;
	}
	public String toString(){
		return "学号:"+number+"  姓名:"+name+"  平均分:"+average+"  最高分:"+max+"  最低分:"+min;
	}
	public boolean equals(Object obj){
		if(this==obj){
			return true;
		}
		if(obj!=null&&obj.getClass()==Student.class){
			Student s=(Student)obj;
			return s.number==this.number;
		}
		return false;
	}
	public int hashCode(){
		return this.number;
	}
	public static void main(String[] args){
		Student student1=new Student("张三",1412641);
		Student student2=new Student("李四",1412642);
		Student student3=new Student("王五",1412643);
		Student student4=new Student("钱六",1412644);
		Student student5=new Student("孙七",1412645);
		
		TreeSet<Student> ts1=new TreeSet<Student>(new Comparator<Student>(){
			public int compare(Student m1,Student m2){
				return m1.average>m2.average?-1
						:m1.average<m2.average?1:0;
			}
		});
		ts1.add(student1);
		ts1.add(student2);
		ts1.add(student3);
		ts1.add(student4);
		ts1.add(student5);
		System.out.println("平均分排名：");
		System.out.println(ts1);
		
		TreeSet<Student> ts2=new TreeSet<Student>(new Comparator<Student>(){
			public int compare(Student m1,Student m2){
				return m1.max>m2.max?-1
						:m1.max<m2.max?1:0;
			}
		});
		ts2.add(student1);
		ts2.add(student2);
		ts2.add(student3);
		ts2.add(student4);
		ts2.add(student5);
		System.out.println("最高分排名：");
		System.out.println(ts2);
		
		TreeSet<Student> ts3=new TreeSet<Student>(new Comparator<Student>(){
			public int compare(Student m1,Student m2){
				return m1.min>m2.min?-1
						:m1.min<m2.min?1:0;
			}
		});
		ts3.add(student1);
		ts3.add(student2);
		ts3.add(student3);
		ts3.add(student4);
		ts3.add(student5);
		System.out.println("最低分排名：");
		System.out.println(ts3);
	}
}
