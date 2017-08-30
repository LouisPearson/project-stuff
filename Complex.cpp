//Louis Pearson 8/30/17
//CSC 330 Lab1
#include "Complex.h"
#include <iostream>
using namespace std;

Complex::Complex() //default constructor
{
	real = 0;
	imaj = 0;
}
Complex::Complex(double r, double i):real(r),imaj(i) {} //initialization list for constructor initializer.
double Complex::getReal()
{
	return real;
}
double Complex::getImag()
{
	return imaj;
}
void Complex::setReal(double rr)
{
	real = rr;
}
void Complex::setImag(double ii)
{
	imaj = ii;
}
Complex Complex::addComplex(Complex c)
{
	Complex temp((this->real + c.real), (this->imaj + c.imaj));
	return temp;
}
Complex Complex::subtractComplex(Complex c)
{
	Complex temp((this->real - c.real), (this->imaj - c.imaj));
	return temp;
}
Complex Complex::multiplyComplex(Complex c)
{
	double tempReal = (this->real*c.real)-(this->imaj*c.imaj);
	double tempImag = (this->real*c.imaj)+(this->imaj*c.real);
	Complex temp(tempReal,tempImag);
	return temp;
}
void Complex::print()
{
	cout<<real<<"+"<<imaj<<"i"<<endl;
}
