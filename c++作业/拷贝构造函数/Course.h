#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std; 
class Course 
{
	public:
		Course(const string& courseName, int capacity); 
		~Course();
		Course(Course &x);
		string getCourseName() const;
		void addStudent(string name);
		void dropStudent(const string& name);
		string *getStudents() const;
		int getNumberOfStudents() const;
		void clear();

		private:
		string courseName; 
		string *students;
		int numberOfStudents; 
		int capacity;
};

Course::Course(const string& courseName, int capacity)//构造函数 
{
this->courseName=courseName;
this->capacity=capacity;
numberOfStudents=0; 
students=new string[capacity];
}

Course::~Course()
{
delete []students; 
}

Course::Course(Course &x)
{
capacity=x.capacity;
courseName=x.courseName;
students=new string[capacity];//深拷贝的内容  
for(int i=0;i<capacity;i++)
{
students[i]=x.students[i];
}
numberOfStudents=x.numberOfStudents;
}

void Course::addStudent(const string name)
{

	if ( numberOfStudents >= capacity )
	{
		string* old = students;
		capacity = 2 *numberOfStudents;
		students = new string[capacity];

		for ( int i = 0; i < numberOfStudents; i++ )
			students[i] = old[i];
		delete [] old;
	}
students[numberOfStudents++]=name;
}

void Course::dropStudent(const string& name)
{
for(int i=0;i<numberOfStudents;i++)
{
if(students[i]==name)
{
for(int k=i;k<numberOfStudents-1;k++)
{
students[k]=students[k+1];
}
numberOfStudents--;
} 
}
}

string* Course::getStudents() const
{
return students;
}

int Course::getNumberOfStudents() const
{
return numberOfStudents;
}

void Course::clear()
{
	delete []students;
	students=new string[capacity];
	numberOfStudents=0;
	
}

#endif
