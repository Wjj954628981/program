#include "stdio.h"
 #include "math.h" 
  main() {
   float a,b,c,x1,x2,d;
   printf("������a��");
   scanf("%f",&a);
   printf("������b��");
   scanf("%f",&b);
   printf("������c��");
   scanf("%f",&c);
   d=b*b-4*a*c;
   if(d < 0)
    printf("����û��ʵ���⡣\n");
   if (d==0) { 
     x1=(-b)/(2*a);
	 printf("x1=%f\n",x1);
   } 
   if (d>0) {
     x1=(-b+sqrt(d))/(2*a);
	 x2=(-b-sqrt(d))/(2*a);
	 printf("x1=%f,x2=%f\n",x1,x2);}
   getch();
   return 0;
 }
