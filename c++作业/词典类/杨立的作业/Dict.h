#ifndef DICT_H
#define  DICT_H
#include <string>
using std::string;
struct Dict{
	void add(string sword, string smean);
	string trans(string sentence);
};
#endif
