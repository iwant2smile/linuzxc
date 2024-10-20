#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

class Complex {
private:
	double real;
	double imag;

public:
	Complex(double r = 0.0, double i = 0.0);

	double getReal() const;
	double getImag() const;

	Complex operator+(const Complex& other) const;
	Complex operator-(const Complex& other) const;
	Complex operator*(const double scalar) const;

	double abs() const;
	void print() const;
};

#endif
