#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main(){
	int number,i=1;
	srand((unsigned)time(0));
	number=rand()%6+1;
	switch(number){
	 case 1:printf("�����\n");break;
	 case 2:printf("������\n");break;
	 case 3:printf("����\n");break;
	 case 4:printf("��־ΰ\n");break;
	 case 5:printf("���ҵ\n");break;
	 case 6:printf("����\n");break;
	}
	getch();
	return 0;
	
}
