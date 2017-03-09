#include <string>
#include <vector>
#include <iostream>
#include <fstream> 
using namespace std;
int main()
{
	ifstream in("Íõ¼Ñò¡.txt");
	vector<string> str;
	string word;
	int Number=0,Cnumber[1000]={};
	
	while(in>>word)
	str.push_back(word);
	
	for(int i=0;i<str.size();i++)
		for(int j=i+1;j<str.size();j++)
		{
			if(str[i]==str[j])
			{
				str[j]=" ";
				Cnumber[i]++;
			}
		}	
	
	for(int i=0;i<str.size();i++)
	{
		if(str[i]==" ")
	{
		continue;
	}
	else
	{
	cout<<"´Ê"<<str[i]<<";    \t"<<"´ÎÊý£º"<<Cnumber[i]+1<<endl;
	}
	}	
}
