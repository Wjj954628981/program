#include<stdio.h>
int main(){
	double h,i,sum;
	h=100;
	sum=100;
	for(i=1;i<10;i++){
		h=h/2.0;
		sum=sum+2*h;
	}
	h=h/2.0; 
	printf("��ʮ�η����߶�Ϊ%lf\n��ʮ�����ʱ·��Ϊ%lf",h,sum);
	return 0;
	getchar();
} 
