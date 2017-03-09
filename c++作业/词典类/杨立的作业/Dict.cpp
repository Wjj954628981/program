#include "Dict.h"
#include <map>
#include <string>
#include <sstream>
using namespace std;

map<string, string> t;
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