/*
output:
   2 > 2/3 is true
   2 < 2/3 is false
   2 == 2/3 is false
   2 != 2/3 is true
   2 + 2/3 = 8/3
   2 - 2/3 = 4/3
   2 * 2/3 = 4/3
   2 / 2/3 = 3
   r3 is 5/2
   r4 is 3/4
   r3 is 3/4
   r4 is 7/4
   1 + 7/4 is 11/4
*/
#include <iostream>
#include <string>
#include "Rational.h"

using namespace std;

int main()
{
	Rational r1(4,2);
	Rational r2(2,3);

	// Test relational operators
	cout << r1 << " > " << r2 << " is " << 
		((r1 > r2) ? "true" : "false") << endl;
	cout << r1 << " < " << r2 << " is " << 
		((r1 < r2) ? "true" : "false") << endl;
	cout << r1 << " == " << r2 << " is " << 
		((r1 == r2) ? "true" : "false") << endl;
	cout << r1 << " != " << r2 << " is " << 
		((r1 != r2) ? "true" : "false") << endl;

	// Test add, subtract, multiply, and divide operators
	cout << r1 << " + " << r2 << " = " << r1 + r2 << endl; 
	cout << r1 << " - " << r2 << " = " << r1 - r2 << endl; 
	cout << r1 << " * " << r2 << " = " << r1 * r2 << endl; 
	cout << r1 << " / " << r2 << " = " << r1 / r2 << endl;

	// Test augmented operator +=
	Rational r3(1, 2);
	r3 += r1;
	cout << "r3 is " << r3 << endl;

	// Test operator []
	Rational r4(1, 2);
	r4[0] = 3; r4[1] = 4;
	cout << "r4 is " << r4 << endl;

	// Test operators ++ 
	r3 = r4++;
	cout << "r3 is " << r3 << endl; 
	cout << "r4 is " << r4 << endl;

	// Test operator for auto conversion
	cout << "1 + " << r4 << " is " << (1 + r4) << endl;
	cin>>r3;
	return 0;
}
