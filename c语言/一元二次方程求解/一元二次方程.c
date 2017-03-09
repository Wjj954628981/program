#include "stdio.h"
 #include "math.h" 
  main() {
   float a,b,c,x1,x2,d;
   printf("请输入a：");
   scanf("%f",&a);
   printf("请输入b：");
   scanf("%f",&b);
   printf("请输入c：");
   scanf("%f",&c);
   d=b*b-4*a*c;
   if(d < 0)
    printf("方程没有实数解。\n");
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
