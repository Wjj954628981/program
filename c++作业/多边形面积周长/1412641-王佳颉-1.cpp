#include <iostream>
#include <cmath>
#define PI 3.1415
using namespace std;

class RegularPolygon
{
	
	private:
	int n;
	double side,x,y;
	public:
	RegularPolygon(){n=3;side=1;x=0;y=0;};	
	RegularPolygon(int n_1,double side_1);
	RegularPolygon(int n_2,double side_2,double x_2,double y_2);
	const double getPerimeter();
	const double getArea();
};

RegularPolygon::RegularPolygon(int n_1,double side_1)
{
	n=n_1;
	side=side_1;
	x=0;
	y=0;
};

RegularPolygon::RegularPolygon(int n_2,double side_2,double x_2,double y_2)
{
	n=n_2;
	side=side_2;
	x=x_2;
	y=y_2;
	
};

const double RegularPolygon::getPerimeter()
{
double meters=0;
meters=(double)n*side;
return meters;
};

const double RegularPolygon::getArea()
{
double areas;
double angel_1=(PI-(2*PI)/n)/2,angel_2=(2*PI)/n;
areas=(sin(angel_1)*sin(angel_1)*side*side*n)/2*sin(angel_2);
return areas;
};

int main()
{
RegularPolygon first,second(6,4),third(10,4,5.6,7.8);
cout<<"第一个正多边形"<<endl; 
cout<<"周长："<<first.getPerimeter()<<"   \t"<<"面积："<<first.getArea()<<endl;

cout<<"第二个正多边形"<<endl; 
cout<<"周长："<<second.getPerimeter()<<"   \t"<<"面积："<<second.getArea()<<endl;

cout<<"第三个正多边形"<<endl; 
cout<<"周长："<<third.getPerimeter()<<"   \t"<<"面积："<<third.getArea()<<endl;
}

