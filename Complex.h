//Louis Pearson 8/30/17
//CSC 330 Lab1
#ifndef COMPLEX_
#define COMPLEX_
class Complex{
private:
	double real;
	double imaj;
public:
	Complex();
	Complex(double, double);
	double getReal();
	double getImag();
	void setReal(double);
	void setImag(double);
	Complex addComplex(Complex);
	Complex subtractComplex(Complex);
	Complex multiplyComplex(Complex);
	void print();
};
#endif
