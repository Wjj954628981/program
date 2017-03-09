#include <iostream>
using namespace std;
int min(int a,int b){
	int m,n,i;
    i=(a<b)?a:b;
	for(;i>=1;i--){
		m=a%i;
		n=b%i;
		if((m==0)&&(n==0))
	    break;
	}
	return i;
}
int f1(double x){
	int y,z=0;
	y=(int) x;
	if(y!=x){
		x=10*x;
		z=z+1;
	} 
	return x;
}
int f2(double x){
	int y,z=0;
	y=(int) x;
	if(y!=x){
		x=10*x;
		z=z+1;
	} 
	return z;
}
int main(){
	double x;
	int i,z,a,b,y;
	cout<<"请输入一个小数："<<endl;
	cin>>x;
	y=(int)x;
	if(y==x){
		cout<<x;
    }
	z=f2(x);
	x=f1(x);
	i=min(x,10*z); 
	a=x/i;
	b=10*z/i;
	cout<<"转换为分数为：";
	cout<<a;
	cout<<"/";
	cout<<b;
	return 0;
}
