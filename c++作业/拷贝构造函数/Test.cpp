#include <iostream> 
#include "Course.h" 
using namespace std;
 
int main() 
{
	Course course1("Data Structures", 1); 

	course1.addStudent("Peter Jones");//�Ե�һ������ֵ 
	course1.addStudent("Brian Smith"); 
	course1.addStudent("Anne Kennedy");


	Course course2(course1);//����һ��������ȫ�������ڶ�����������ȥ����������� 


	cout << "Number of students in course1: "//�����ǽ���һ��������ȫ��� 
		<< course1.getNumberOfStudents() << endl;
	string* students = course1.getStudents();
	for (int i = 0; i < course1.getNumberOfStudents(); i++)
		cout << students[i] << ", ";
	cout << endl;

	cout << "Number of students in course2: "//�����ǽ��ڶ���������ȫ��� 
		<< course2.getNumberOfStudents() << endl; 
	students = course2.getStudents();
	for (int i = 0; i < course2.getNumberOfStudents(); i++)
		cout << students[i] << ", "; 
	cout<<endl;


	course1.dropStudent("Anne Kennedy");//����dropstudent�Ĺ��� 
	cout << "Number of students in course1: " 
		<< course1.getNumberOfStudents() << endl;
	students = course1.getStudents();
	for (int i = 0; i < course1.getNumberOfStudents(); i++)
		cout << students[i] << ", ";
	cout << endl;



	course1.clear();
		cout << "Number of students in course1: "//�����ǽ���һ��������ȫ��� 
		<< course1.getNumberOfStudents() << endl;
	students = course1.getStudents();
	for (int i = 0; i < course1.getNumberOfStudents(); i++)
		cout << students[i] << ", ";
	cout << endl;

	cout << endl;

	return 0;
}
