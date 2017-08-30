//Louis Pearson 8/30/17
//CSC 330 Lab1
#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
	Complex c1(7,6);
	Complex c2(2,5);
	Complex c3 = c1.multiplyComplex(c2);
	Complex c4 = c1.addComplex(c2);
	Complex c5 = c1.subtractComplex(c2);
	c1.print();
	c2.print();
	c3.print();
	c4.print();
	c5.print();
	return 0;
}
