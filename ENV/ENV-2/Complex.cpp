#include "Complex.h"

Complex::Complex(double r, double i) : real(r), imag(i) {}

double Complex::getReal() const {
	return real;
}

double Complex::getImag() const {
	return imag;
}

Complex Complex::operator+(const Complex& other) const {
	return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
	return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const double scalar) const {
	return Complex(real * scalar, imag * scalar);
}

double Complex::abs() const {
	return std::sqrt(real * real + imag * imag);
}

void Complex::print() const {
	std::cout << "(" << real << ", " << imag << "i)" << std::endl;
}
