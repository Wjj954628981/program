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
	printf("����һ������");
	scanf("%d",&k);
	k=jiecheng(k);
	printf("�׳�Ϊ%d\n",k);}
	return 0;
	getchar();
} 
