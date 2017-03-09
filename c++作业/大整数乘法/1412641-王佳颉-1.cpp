#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class bigint
{
	private:
	vector< string > Vnumber;	
	public:
	string calculate(string Number);
	string add();
	void time();
};

string bigint::add()
{	
	string Temp;
	Temp.clear();
	getline(cin,Temp);
	cout<<calculate(Temp)<<endl;
	return Temp;
};

void bigint::time()
{
	int counter;
	string Number; 
	Vnumber.clear();
	Number.clear();
	string temp;
	getline(cin,Number);
	char Temp;
	for(int i=0;i<(int)Number.size()/2;i++)
	{
		Temp=Number[i];
		Number[i]=Number[Number.size()-i-1];
		Number[Number.size()-i-1]=Temp;
	}
	istringstream iss(Number);
	
	while ( iss >> temp )
	Vnumber.push_back(temp);
	
	counter=Vnumber.size();
	vector< vector< int > > Inumber(counter);
	

	
	int Nlength=0;
	for(int i=0;i<Vnumber.size();i++)
	{
		if(Nlength<=Vnumber[i].size())
		Nlength=Vnumber[i].size();
	}
	
	for(int i=0;i<Vnumber.size();i++)
	for(int j=0;j<Vnumber[i].size()-Nlength;j++)
	Vnumber[i].push_back('0');	

	for(int i=0;i<Vnumber.size();i++)
	for(int j=0;j<Vnumber[i].size();j++)
	Inumber[i].push_back(int(Vnumber[i][j]-48));
	
	
	string TempString;
	for(int i=0;i<counter-1;i++)
	{
	
	int Temp_2=Inumber[i+1].size();
	for(int q=0;q<Inumber[i].size()-Temp_2;q++){Inumber[i+1].push_back(0);}
	
	for(int j=0;j<Inumber[i].size();j++)
	for(int k=0;k<Inumber[i].size();k++)
	{
		int Temp_1=Inumber[i][j]*Inumber[i+1][k];
		if(Temp_1>=10)
		{
			TempString+=(Temp_1/10+'0');
		}
		TempString+=(Temp_1%10+'0');
	
		for(int p=0;p<k+j;p++)
		{
			TempString+='0';
		}
		TempString+=' ';		
	}
	
	Inumber[i+1].clear();
	for(int p=calculate(TempString).size()-1;p>=0;p--)
	{
		Inumber[i+1].push_back(calculate(TempString)[p]-48);
	}
		
	TempString.clear();	
	
	}
	
	int flag=0;
	for(int i=Inumber[Inumber.size()-1].size()-1;i>=0;i--)
	{
		if(flag==0)
		if(Inumber[Inumber.size()-1][i]==0)
		{
			continue;
		}
		else
		{
			flag=1;
		}
		if(flag==1)
		cout<<Inumber[Inumber.size()-1][i];
	}
	
	cout<<endl;
	Inumber.clear();
	
}

string bigint::calculate(string XNumber)
{	
	int counter;
	string Number=XNumber;
	Vnumber.clear();
	string temp;
	char Temp;
	for(int i=0;i<(int)Number.size()/2;i++)
	{
		Temp=Number[i];
		Number[i]=Number[Number.size()-i-1];
		Number[Number.size()-i-1]=Temp;
	}
	istringstream iss(Number);
	
	while ( iss >> temp )
	Vnumber.push_back(temp);
	
	counter=Vnumber.size();
	vector< vector< int > > Inumber(counter);
	
	int Nlength=0;
	for(int i=0;i<Vnumber.size();i++)
	{
		if(Nlength<=Vnumber[i].size())
		Nlength=Vnumber[i].size();
	}
	
	for(int i=0;i<Vnumber.size();i++)
	for(int j=0;j<Vnumber[i].size()-Nlength;j++)
	Vnumber[i].push_back('0');	

	for(int i=0;i<Vnumber.size();i++)
	for(int j=0;j<Vnumber[i].size();j++)
	Inumber[i].push_back(int(Vnumber[i][j]-48));
	
	for(int i=0;i<counter-1;i++)
	for(int j=0;j<Inumber[i].size();j++)
	{	
			
		int Temp=0;
		Temp=Inumber[i][j]+Inumber[i+1][j];
		if(j<Inumber[i].size()-1)
		{
		Inumber[i+1][j]=Temp%10;
		Inumber[i+1][j+1]+=int(Temp/10);
		}
		else
		{
		Inumber[i+1][j]=Temp%10;
		if(Temp>=10)
		{
		Inumber[i+1].push_back(int(Temp/10));
		if(i+1!=counter-1)
		{
			for(int k=0;k<counter-1-(i+1);k++)
			Inumber[i+1+k+1].push_back(0);
		}	
		}
		}
	}
	Number.clear();
	for(int i=Inumber[counter-1].size()-1;i>=0;i--)
	Number+=(Inumber[counter-1][i]+48);
	Inumber.clear();
	return Number;
};


int main()
{
	bigint Numbers;
	while(1)
	Numbers.time();
}
