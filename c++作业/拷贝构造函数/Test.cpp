#include <iostream> 
#include "Course.h" 
using namespace std;
 
int main() 
{
	Course course1("Data Structures", 1); 

	course1.addStudent("Peter Jones");//对第一个对象赋值 
	course1.addStudent("Brian Smith"); 
	course1.addStudent("Anne Kennedy");


	Course course2(course1);//将第一个对象完全拷贝到第二个对象里面去，这里是深拷贝 


	cout << "Number of students in course1: "//这里是将第一个对象完全输出 
		<< course1.getNumberOfStudents() << endl;
	string* students = course1.getStudents();
	for (int i = 0; i < course1.getNumberOfStudents(); i++)
		cout << students[i] << ", ";
	cout << endl;

	cout << "Number of students in course2: "//这里是将第二个对象完全输出 
		<< course2.getNumberOfStudents() << endl; 
	students = course2.getStudents();
	for (int i = 0; i < course2.getNumberOfStudents(); i++)
		cout << students[i] << ", "; 
	cout<<endl;


	course1.dropStudent("Anne Kennedy");//测试dropstudent的功能 
	cout << "Number of students in course1: " 
		<< course1.getNumberOfStudents() << endl;
	students = course1.getStudents();
	for (int i = 0; i < course1.getNumberOfStudents(); i++)
		cout << students[i] << ", ";
	cout << endl;



	course1.clear();
		cout << "Number of students in course1: "//这里是将第一个对象完全输出 
		<< course1.getNumberOfStudents() << endl;
	students = course1.getStudents();
	for (int i = 0; i < course1.getNumberOfStudents(); i++)
		cout << students[i] << ", ";
	cout << endl;

	cout << endl;

	return 0;
}
