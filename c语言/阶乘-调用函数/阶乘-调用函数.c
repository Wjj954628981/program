#include<stdio.h>
int jiecheng(int a){
	int b=1,i=1;
	for(;i<=a;i++){
		b=b*i;
	}
	return b;
} 
int main(){
	int k;
	while(1) {
	printf("输入一个数字");
	scanf("%d",&k);
	k=jiecheng(k);
	printf("阶乘为%d\n",k);}
	return 0;
	getchar();
} 
