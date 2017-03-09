#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
	public:
		Rational();
		Rational(int numerator, int denominator);
		int getNumerator() const;
		int getDenominator() const;
		Rational add(const Rational& secondRational) const;
		Rational subtract(const Rational& secondRational) const;
		Rational multiply(const Rational& secondRational) const;
		Rational divide(const Rational& secondRational) const;
		int compareTo(const Rational& secondRational) const;
		bool equals(const Rational& secondRational) const;
		int intValue() const;
		double doubleValue() const;
		string toString() const;

		//重载运算符部分
		//类型转换
		operator double();
		operator int();	
		Rational(int numerator);	
		//运算符号 
		Rational &Rational::operator+=(const Rational& secondRational); 
		Rational &Rational::operator-=(const Rational& secondRational);
		Rational &Rational::operator*=(const Rational& secondRational);
		Rational &Rational::operator/=(const Rational& secondRational);
		Rational &Rational::operator++();
		Rational Rational::operator++(int dummy);
		Rational Rational::operator--(int dummy);
		Rational &Rational::operator--();
		Rational &Rational::operator[](int index);
		Rational &Rational::operator+(const Rational& secondRational);
		Rational Rational::operator+();
		Rational &Rational::operator-(const Rational& secondRational);
		Rational Rational::operator-();
		Rational Rational::operator*(const Rational& secondRational);
		Rational Rational::operator/(const Rational& secondRational);
		
		
    friend ostream& operator<<(ostream& out, const Rational& rational);
	  friend istream& operator>>(istream& input, Rational& rational);
		bool Rational::operator==(const Rational& secondRational);
		bool Rational::operator!=(const Rational& secondRational);
		bool Rational::operator>(const Rational& secondRational);
		bool Rational::operator<(const Rational& secondRational);
		bool Rational::operator>=(const Rational& secondRational);
		bool Rational::operator<=(const Rational& secondRational);
			
		private:
		int numerator;
		int denominator;
		static int gcd(int n, int d);    //求最大公约数
};


Rational::Rational()
{
numerator=0;
denominator=0;
}

Rational::Rational(int numerator, int denominator)
{
this->numerator=numerator;
this->denominator=denominator;
}

int Rational::gcd(int n, int d)
{
int temp=1,i=1;
while(i<=n)
{
if(!(n%i)&&!(d%i))
{
temp=i;
}
i++;
}
return temp;
}


int Rational::getNumerator() const
{
return numerator;
}

int Rational::getDenominator() const
{
return denominator;
} 

Rational Rational::add(const Rational& secondRational) const
{
Rational temp;
temp.numerator=numerator+secondRational.numerator;
temp.denominator=denominator+secondRational.denominator;
return temp; 
} 

Rational Rational::subtract(const Rational& secondRational) const
{
Rational temp;
temp.numerator=numerator-secondRational.numerator;
temp.denominator=denominator-secondRational.denominator;
return temp; 
}

Rational Rational::multiply(const Rational& secondRational) const
{
Rational temp;
temp.numerator=numerator*secondRational.numerator;
temp.denominator=denominator*secondRational.denominator;
return temp; }

Rational Rational::divide(const Rational& secondRational) const
{
Rational temp;
temp.numerator=numerator/secondRational.numerator;
temp.denominator=denominator/secondRational.denominator;
return temp; }

int Rational::compareTo(const Rational& secondRational) const
{
//如果是大于，那么返回1，如果是小于，那么返回2 
if(this->doubleValue()>secondRational.doubleValue())
{
return 1;
}
if(this->doubleValue()<secondRational.doubleValue())
{
return 2;
}

}

bool Rational::equals(const Rational& secondRational) const
{
return numerator==secondRational.numerator&&denominator==secondRational.denominator;
}



int Rational::intValue() const
{
	return numerator/denominator;
}


double Rational::doubleValue() const
{
	return numerator/denominator;
}

string Rational::toString() const
{
	string temp;
	int i=0;

	while(int(numerator/int(pow(10.0,i))))
	{
	i++;
	char temp_1=numerator%(i*10)+'0';
	temp+=temp_1;	
	}
	
	temp+='/';
	i=0;
	while(int(denominator/pow(10.0,i)))
	{
	i++;
	char temp_1=denominator%(i*10)+'0';
	temp+=temp_1;	
	}
	return temp;
}

Rational::operator double()
{
    return doubleValue(); 
}

Rational::operator int()
{
    return intValue(); 
}

Rational::Rational(int numerator)
{
	this->numerator = numerator;
	this->denominator = 1;
}


Rational &Rational::operator+=(const Rational& secondRational)
{
   *this = add(secondRational);
   return *this;
}

Rational &Rational::operator-=(const Rational& secondRational)
{
	*this = subtract(secondRational);
	return *this;	
}

Rational &Rational::operator*=(const Rational& secondRational)
{
	*this = multiply(secondRational);
	return *this;	
	
}

Rational &Rational::operator/=(const Rational& secondRational)
{
	*this = divide(secondRational);
	return *this;	
}

Rational &Rational::operator++()
{
numerator+=denominator;
return *this;
}

Rational Rational::operator++(int dummy)
{
   Rational temp(numerator, denominator);
   numerator += denominator;
   return temp;
}




Rational &Rational::operator--()
{
numerator-=denominator;
return *this;
}

Rational Rational::operator--(int dummy)
{
   Rational temp(numerator, denominator);
   numerator -= denominator;
   return temp;
}

Rational &Rational::operator[](int index)
{
return this[index];
}

Rational &Rational::operator+(const Rational& secondRational)
{

Rational temp;
temp.numerator=numerator+secondRational.numerator;
temp.denominator=denominator+secondRational.denominator;
return temp;
}

Rational Rational::operator+()
{
     return Rational(numerator, denominator);
}

Rational &Rational::operator-(const Rational& secondRational)
{
Rational temp(numerator-secondRational.numerator,denominator-secondRational.denominator);
return temp;
}

Rational Rational::operator-()
{
     return Rational(-numerator, denominator);
}

Rational Rational::operator*(const Rational& secondRational)
{
Rational temp(numerator*secondRational.numerator,denominator*secondRational.denominator);
return temp;
}

Rational Rational::operator/(const Rational& secondRational)
{
Rational temp(numerator*secondRational.denominator,denominator*secondRational.numerator);
return temp;
}

//下面是友元部分 
ostream& operator<<(ostream& out, const Rational& rational)
{
  out << rational.numerator << "/" << rational.denominator;
  return out;
};

istream& operator>>(istream& input, Rational& rational)
{
input>> rational.numerator>>rational.denominator;
return input;
}

bool Rational::operator==(const Rational& secondRational)
{
return  equals(secondRational);
}
 
 bool Rational::operator!=(const Rational& secondRational)
{

return  !equals(secondRational);
}
 
 
bool Rational::operator>(const Rational& secondRational)
{
if(compareTo(secondRational)==1)
return  true;
else
return false;
}
bool Rational::operator<(const Rational& secondRational)
{
	if(compareTo(secondRational)==2)
	return  true;
	else
	return false;
}
bool Rational::operator>=(const Rational& secondRational)
{
	if(compareTo(secondRational)==1||equals(secondRational))
	return  true;
	else
	return false;
}

bool Rational::operator<=(const Rational& secondRational)
{
if(compareTo(secondRational)==2||equals(secondRational))
	return  true;
	else
	return false;
}			

Rational operator+(int x, const Rational& r2)
{

Rational temp(r2.getNumerator()+x*r2.getDenominator(),r2.getDenominator());
return	temp; 
}

#endif