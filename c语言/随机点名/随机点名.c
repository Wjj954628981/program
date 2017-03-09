#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main(){
	int number,i=1;
	srand((unsigned)time(0));
	number=rand()%6+1;
	switch(number){
	 case 1:printf("王佳颉\n");break;
	 case 2:printf("刘天龙\n");break;
	 case 3:printf("杨立\n");break;
	 case 4:printf("李志伟\n");break;
	 case 5:printf("许宏业\n");break;
	 case 6:printf("马丁丁\n");break;
	}
	getch();
	return 0;
	
}
