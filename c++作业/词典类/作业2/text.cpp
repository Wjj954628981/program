#include <iostream>  
#include "dict.h"  
int main(int argc, char* argv[])
{
 Dict obj;
 obj.add("a", "һ��" );
 obj.add("I", "��" );
 obj.add("am", "��" );
 obj.add("student", "ѧ��" ); 
 cout<<obj.trans("I am a student")<<endl;
 return 0;
}
