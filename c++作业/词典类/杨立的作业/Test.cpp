#include "Dict.h"
#include <iostream>
using namespace std;
int main()
{
	Dict a;
	a.add("i", "��");
	a.add("am", "��");
	a.add("boy","�к�");
	a.add("a","һ��"); 
	cout<<a.trans(" i am a boy");


}