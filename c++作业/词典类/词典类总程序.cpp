#include <map>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
/*class define*/
class Dict
{
private:
 map<string, string> t;
public:
 Dict();
 void add(string sword, string smean);
 string trans(string sentence);
};
Dict::Dict(){}
void Dict::add(string sword, string smean)
{
 t.insert(pair<string,string>(sword, smean));
}
 
string Dict::trans(string sentence)
{
 string s, sres = "";
 istringstream iss(sentence);
 map<string,string>::iterator iter=t.begin();
 int c = 0;
 while (iss>>s)
 {
  iter = t.find(s);
  if (iter == t.end())
   continue;
  sres += iter->second;
 }
 return sres;
}
/*class define ended!!*/
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
