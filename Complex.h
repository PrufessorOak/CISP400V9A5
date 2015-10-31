// NAME  : Yevgeniy Lankin
// CLASS : CISP 400, Online
// Assignment #: A5
// PURPOSE : Date class definition. This file presents Complex's public 
//           interface without revealing the implementations of Complex's member
//           functions, which are defined in Complex.cpp
//           To show my understanding of a header file and function prototypes.
// Software Change (Modifications) Record
// date         what               who
// 10/29/2015   created program    Yev
// Complex class definition.

#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(double = 0.0, double = 0.0); // constructor
	const Complex& Complex::operator=(const Complex &rhs); // assignment operator
	Complex operator+(const Complex &rhs) const; // addition operator
	Complex operator-(const Complex &rhs) const; // subtraction operator
	Complex operator*(const Complex &operand) const; // multiplication operator
	Complex operator/(const Complex &operand) const; // division operator
	const bool operator==(const Complex &rhs) const; // equal comparison operator
	const bool operator!=(const Complex &rhs) const; // not-equal-to comparison operator
private:
	friend ostream &operator<<(ostream&output, const Complex&complex); // insertion operator
	friend istream &operator>>(istream&input, Complex&complex); // extraction operator
	double real; // real part
	double imaginary; // imaginary part
}; // end class Complex
