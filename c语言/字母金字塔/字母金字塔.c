#include<stdio.h>
int main(){ 
	char c;
	int a,b,i,j;
	while(1){
	printf("输入一个大写字母："); 
	scanf("%c",&c);
	a=c;
	for(i=64;i<=a;i++){
		for(b=i;b<=a;b++){
			printf(" ");
		}
		for(j=65;j<=i;j++){
			c=j;
			printf("%c",c);
		}
		for(;j>=65;j--){
			c=j;
			printf("%c",c);
		}
		printf("\n");
	} 
	getchar();}
	return 0;
}

