#include<stdio.h>
int max(int a,int b){
	int i,m,n;
	i=(a>b)?a:b;
	for(;i<=a*b;i++){
		m=i%a;
		n=i%b;
		if((m==0)&&(n==0))
	    break;}
	return i;
	}
int min(int c,int d){
	int m,n,i;
    i=(c<d)?c:d;
	for(;i>=1;i--){
		m=c%i;
		n=d%i;
		if((m==0)&&(n==0))
	    break;
	}
	return i;
}



int main(){
	int x,y;
	while(1){
	printf("请输入两个整数：");
	scanf("%d %d",&x,&y);
	printf("最大公倍数%d 最大公约数%d\n",max(x,y),min(x,y));}
	}
	

