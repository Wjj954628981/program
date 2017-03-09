#include<stdio.h>
#include<string.h>
int main(){
	char a[100];
	int i,length,alpha=0,blank=0,number=0,ALPHA=0;
	printf("请数输入一行字符："); 
	gets(a);
	length=strlen(a);
	for(i=0;i<=length-1;i++) {
		if((a[i]>='a')&&(a[i]<='z')){
			alpha++;
		}
		if((a[i]>='A')&&(a[i]<='Z')){
			ALPHA++;
		}
		if(a[i]==32){
			blank++;
		}
		if((a[i]>='0')&&(a[i]<='9')){
			number++;
		}
	}
	printf("小写字母数为%d\n大写字母数为%d\n空格数为%d\n数字数为%d\n",alpha,ALPHA,blank,number);
    printf("字符长度为%d\n",length);
    return 0;
    getchar();
}
