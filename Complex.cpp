// NAME  : Yevgeniy Lankin
// CLASS : CISP 400, Online
// Assignment #: A5
// PURPOSE : To show my understanding of member functions prototyped in Complex.h
//           and class member-function definitions.
//           Complex class member-function definitions.
// Software Change (Modifications) Record
// date         what               who
// 10/29/2015   created program    Yev

#include "Complex.h" // Complex class definition

// Constructor
Complex::Complex(double realPart, double imaginaryPart)
	: real(realPart),
	imaginary(imaginaryPart)
{
	this->real = realPart;
	this->imaginary = imaginaryPart;

} // end Complex constructor

//overload insertion operator
ostream &operator<<(ostream&output, const Complex &complex)
{
	// check to see if the real number has been divided by zero
	if (complex.real != INFINITY)
	{
		output << '(' << complex.real << "," << complex.imaginary << ')';
		return output;
	}
	else
	{
		//replace complex number with "infinite"
		output << "infinite";
	}
} //end function operator <<

//overload extraction operator
istream &operator>>(istream&input, Complex &complex)
{
	cout << "(Performing >> operator overloading.)\n? ";
	input.ignore();
	input >> complex.real;
	input.ignore();
	input >> complex.imaginary;
	input.ignore();
	return input;
} // end function operatot >>

// assignment operator
const Complex& Complex::operator=(const Complex &rhs)
{
	real = rhs.real;
	imaginary = rhs.imaginary;
	return *this;
} // end function operator =

//addition operator
Complex Complex::operator+(const Complex &rhs) const
{
	return Complex(real + rhs.real,
		imaginary + rhs.imaginary);
} // end function operator +

// subtraction operator
Complex Complex::operator-(const Complex &rhs) const
{
	return Complex(real - rhs.real,
		imaginary - rhs.imaginary);
} // end function operator -

// mutilplication operator
Complex Complex::operator*(const Complex &operand) const
{
	//  (ac -bd) + (ad + bc)i
	return Complex((real * operand.real - imaginary * operand.imaginary),
		(real * operand.imaginary + imaginary*operand.real));
} // end function operator *

Complex Complex::operator/(const Complex &operand) const
{
	// (a+ib)/(c+id)=(ac+bd)+i(bc-ad))/(c^2+d^2) 
	double x = ((real * operand.real + imaginary * operand.imaginary) / (operand.real*operand.real + operand.imaginary*operand.imaginary),
		(imaginary*operand.real - real * operand.imaginary) / (operand.real*operand.real + operand.imaginary*operand.imaginary));
	if (x == x)
	{
		return Complex((real * operand.real + imaginary * operand.imaginary) / (operand.real*operand.real + operand.imaginary*operand.imaginary),
			(imaginary*operand.real - real * operand.imaginary) / (operand.real*operand.real + operand.imaginary*operand.imaginary));
	}
	else
		return INFINITY;
}

// equal comparison operator
const bool Complex::operator==(const Complex &rhs) const
{
	if ((real == rhs.real) && (imaginary == rhs.imaginary))
		return true;
	else
		return false;
} // end equal comparison operator

// not-equal-to comparison operator
const bool Complex::operator!=(const Complex &rhs) const
{
	if ((real != rhs.real) || (imaginary != rhs.imaginary))
		return true;
	else
		return false;
} //end function comparison operator !=
