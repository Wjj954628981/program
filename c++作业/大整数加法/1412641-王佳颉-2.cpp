#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class bigint
{
	private:
	string Number;
	int counter;
	void change();
	vector< string > Vnumber;	
	void compare(int Num,int Counter,int Counter_2);
	public:
	string calculate();
};

string bigint::calculate()
{
	Vnumber.clear();
	Number.clear();
	string temp;
	int higher[255]={},Fuck=0;
	getline(cin,Number);
	
	change();
	
	istringstream iss(Number);
	
	while ( iss >> temp )
	{
		Vnumber.push_back(temp);
	}
	
	if(Vnumber[0]=="0")
	{
	
	}
	
	for(int i=0;i<Vnumber.size()-1;i++)
	{
 	
 	int Temp=0;
	if(Vnumber[i].size()>=Vnumber[i+1].size())
	{
		Temp=Vnumber[i+1].size();
	}
	else
	{
		Temp=Vnumber[i].size();	
	}
	

	for(int k=0;k<255;k++)
		{
			higher[k]=0;
		}
		
	for(int j=0;j<Temp;j++)
	{
		
		counter=(int)(Vnumber[i][j]-48)+(int)(Vnumber[i+1][j]-48);
		if(counter>=10)
		higher[j]=1;
		
		Fuck=j;
		
		if(j==0)
		{
			Fuck=1;
		}
		
		if(higher[Fuck]==1)
		{
			compare(1,i,j);
		}
			else
		{
			compare(0,i,j);				
		}
		
		if(Temp==Vnumber[i].size()&&Temp==Vnumber[i+1].size()&&higher[Temp-1]==1)
		{
			if(Vnumber[i].size()<=Vnumber[i+1].size())
			{
					Vnumber[i+1].push_back('1');
			}
			else
			{
					Vnumber[i].push_back('1');	
			}
		}
		}
	
	if(Vnumber[i].size()>Vnumber[i+1].size())
		{
			Vnumber[i+1]=Vnumber[i];
		}

	} 
	
	Number=Vnumber[Vnumber.size()-1];	
	change();
	cout<<Number<<endl;
	
	return Number;
}

void bigint::change()
{
	char Temp;
	for(int i=0;i<(int)Number.size()/2;i++)
	{
		Temp=Number[i];
		Number[i]=Number[Number.size()-i-1];
		Number[Number.size()-i-1]=Temp;
	}
};

void bigint::compare(int Number,int Counter,int Counter_2)
{
	if(Vnumber[Counter].size()<=Vnumber[Counter+1].size())
	{
		Vnumber[Counter+1][Counter_2]=(char)(counter%10+48+Number);
	}
	else
	{
		Vnumber[Counter][Counter_2]=(char)(counter%10+48+Number);	
	}
};

int main()
{
	bigint Numbers;
	while(1)
	Numbers.calculate();
}
