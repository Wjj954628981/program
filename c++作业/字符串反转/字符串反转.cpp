#include<iostream>
#include<string>
#include<vector>
 
using namespace std;
 
int main()
{
	vector<char> v,num;
	string s;
	bool b;
    cin >> s;
    for(int i=0;i<s.length();i++){
    	if(s[i]>=48&&s[i]<=57){
    		b = true;
    	}else{
    		b=false;
    	}
    	if(b==true){
    		num.push_back(s[i]);
    	} 
    	if(b==false||i==s.length()-1){
    		for(int j=num.size()-1;j>=0;j--){
    			v.push_back(num[j]);
    			num.clear();
    		}
    	}
    	if(s[i]>=97&&s[i]<=122){
    		v.push_back(s[i]);
    	}
    	if(s[i]>=65&&s[i]<=90){
    		int asc = s[i] + 32;
    		v.push_back((char)(asc));
    	}
    }
    for(int i=0;i<v.size();i++){
    	cout<<v[i];
    }
}
