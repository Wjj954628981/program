#ifndef Dict_H_  
#define Dict_H_  
#include <string>
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
#endif 
