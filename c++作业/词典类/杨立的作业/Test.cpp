#include "Dict.h"
#include <iostream>
using namespace std;
int main()
{
	Dict a;
	a.add("i", "我");
	a.add("am", "是");
	a.add("boy","男孩");
	a.add("a","一个"); 
	cout<<a.trans(" i am a boy");


}