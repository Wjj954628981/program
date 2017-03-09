#include<stdio.h>
#include<conio.h>
int main(){
	int m,a,b,c,d,e;
	for(m=1;m<10000;m++){
		a=(int)m/1000;
	    b=(int)(m-a*1000)/100;
	    c=(int)(m-a*1000-b*100)/10;
	    d=m-a*1000-b*100-c*10; 
	    e=a*a*a+b*b*b+c*c*c+d*d*d;
		if(e==m) printf("%d\n",e);
    }
	return 0;
	getchar();
}
