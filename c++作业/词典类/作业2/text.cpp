#include <iostream>  
#include "dict.h"  
int main(int argc, char* argv[])
{
 Dict obj;
 obj.add("a", "一个" );
 obj.add("I", "我" );
 obj.add("am", "是" );
 obj.add("student", "学生" ); 
 cout<<obj.trans("I am a student")<<endl;
 return 0;
}
