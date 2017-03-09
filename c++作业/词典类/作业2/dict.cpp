#include <string> 
#include <sstream>
#include <map>
#include "dict.h"
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
