#include <stdio.h>
#include <math.h>
main()
{   int points,k;
    double x,y,angle,portion;
    
    /*��720�ȷֳ�40�ݣ� һ����40����*/
	points=40;
	portion=4.0*3.1415926/points;
	for(k=0;k<points;k++){
		angle=k*portion;/*����Ƕ�*/
		x   =2.0+angle*cos(angle);
		y   =angle*sin(angle);
		printf("%.3lf %.3lf\n",x,y);
	} 
	getchar(); 
	return 0; 
}

