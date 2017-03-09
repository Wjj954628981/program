#include<iostream>
#include<fstream>

using namespace std;

int main(){
	ofstream output; 
    output.open("text.txt");
    output<<"abc";
    output.close();
}
