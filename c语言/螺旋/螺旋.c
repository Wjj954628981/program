#include <stdio.h>
#include <math.h>
main()
{   int points,k;
    double x,y,angle,portion;
    
    /*将720度分成40份， 一共画40个点*/
	points=40;
	portion=4.0*3.1415926/points;
	for(k=0;k<points;k++){
		angle=k*portion;/*求出角度*/
		x   =2.0+angle*cos(angle);
		y   =angle*sin(angle);
		printf("%.3lf %.3lf\n",x,y);
	} 
	getchar(); 
	return 0; 
}

