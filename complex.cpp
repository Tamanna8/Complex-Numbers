/*
Name: Tamanna Sharma
Class: CSS 342
Quarter: Fall 2017
Version: 10/13/2017 1.0

complex.cpp : Defines the entry point for the console application
*/

#include "stdafx.h"
#include "complex.h"
#include <iostream> 
#include <string>

using namespace std;

//Constructor with no argument
Complex::Complex() {
	r = 0.0;
	i = 0.0;
}

//Constructor with one argument
Complex::Complex(double real) {
	r = real;
	i = 0.0;
}

//Constructor with two arguments
Complex::Complex(double real, double img) {
	r = real;
	i = img;
}

//--------------------------------- getRealValue ----------------------------------------------
/*
This gets the real part of complex numbers
*/
double Complex::getReal() const {
	return r;
}

//--------------------------------- getImaginaryValue ------------------------------------------
/*
This gets the imaginary part of complex numbers
*/
double Complex::getImaginary() const
{
	return i;
}

//--------------------------------- addAndUpdate ----------------------------------------------
/*
Operator +=
This add and update two complex numbers
*/
Complex& Complex::operator+=(const Complex& a) {
	r += a.r;
	i += a.i;
	return *this;
}

//--------------------------------- subtractAndUpdate -----------------------------------------
/*
Operator -=
This subtract and update two complex numbers
*/
Complex& Complex::operator-=(const Complex& s) {
	r -= s.r;
	i -= s.i;
	return *this;
}

//--------------------------------- multiplyAndUpdate -----------------------------------------
/*
Operator *=
This multiply and update two complex numbers
*/
Complex& Complex::operator*=(const Complex& s) {
	double tempR = r;
	r = (r* s.r) + (i*s.i*-1);
	i = (tempR* s.i) + (i*s.r);
	return *this;
}

//--------------------------------- divideAndUpdate --------------------------------------------
/*
Operator /=
This divide and update two complex numbers
If the denominator is 0, it will give an error message
*/
Complex& Complex::operator/=(const Complex& c) {
	double div = c.r * c.r + c.i * c.i;
	if (div != 0) {
		double d = r;
		r = (r * c.r + i * c.i) / div;
		i = (i * c.r - d * c.i) / div;
	}
	return *this;
}

//--------------------------------- add ---------------------------------------------------------
/*
Operator +
This adds two complex numbers
*/
Complex Complex::operator+(const Complex& a) const {
	Complex sum;

	sum.r = r + a.r;
	sum.i = i + a.i;
	return sum;
}

//--------------------------------- subtract ---------------------------------------------------
/*
Operator -
This subtracts two complex numbers
*/
Complex Complex::operator-(const Complex& s) const {
	Complex sub;

	sub.r = r - s.r;
	sub.i = i - s.i;
	return sub;
}

//--------------------------------- multiply ----------------------------------------------------
/*
Operator *
This multiplies two complex numbers
*/
Complex Complex::operator*(const Complex& c) const {
	Complex mult = *this;

	mult *= c;
	return mult;
}

//--------------------------------- divide -----------------------------------------------------
/*
Operator /
This divides two complex numbers
If the denominator is 0, it will give an error message
*/
Complex Complex::operator/(const Complex& c) const {
	double div = (c.r*c.r) + (c.i*c.i);
	Complex divi;

	if (div == 0) {
		cout << " Cannot Divide a number with 0( Wrong Input)";
		return NULL;
	}
	else {
		divi.r = (r*c.r) + (i*c.i);
		divi.r /= div;
		divi.i = (i*c.r) - (r*c.i);
		divi.i /= div;
	}
	return divi;
}

//--------------------------------- conjugate ------------------------------------------------
/*
This conjugate two complex numbers
*/
Complex Complex::conjugate() {
	Complex conj;

	conj.i = -1 * i;
	conj.r = r;
	return conj;
}

//--------------------------------- equalComparison -----------------------------------------
/*
Operator ==
This checks if two complex numbers are equal
*/
bool Complex::operator==(Complex c) {

	return (r == c.r) && (i == c.i);
}

//--------------------------------- notEqualComparison --------------------------------------
/*
Operator !=
This checks if complex numbers are not equal
*/
bool Complex::operator!=(Complex c) {

	return (r != c.r) && (i != c.i);
}

//---------------------------- outputComplex -------------------------------------------------
/*
Output operator
This ouputs the results with appropriate formatting for complex numbers
*/
ostream& operator<<(ostream &outStream, const Complex &com) {

	if (com.i < -1 && com.r == 0)outStream << com.i << "i";
	else if (com.i == -1 && com.r == 0)  outStream << "-i";
	else if (com.i > -1 && com.i < 0 && com.r == 0) outStream << com.i << "i";
	else if (com.i == 0 && com.r == 0) outStream << "0";
	else if (com.i > 0 && com.i < 1 && com.r == 0) outStream << com.i << "i";
	else if (com.i == 1 && com.r == 0)outStream << "i";
	else if (com.r == 0 && com.i > 0) outStream << com.i << "i";
	else if (com.i < 0)outStream << com.r << com.i << "i";
	else if (com.i == -1)  outStream << com.r << "-i";
	else if (com.i > -1 && com.i < 0) outStream << com.r << com.i << "-i";
	else if (com.i == 0) outStream << com.r;
	else if (com.i > 0 && com.i < 1) outStream << com.r << "+" << com.i << "i";
	else if (com.i == 1)outStream << com.r << "+i";
	else outStream << com.r << "+" << com.i << "i";
	return outStream;
}

//---------------------------- inputComplex ------------------------------------------------
/*
Input operator
This takes input from the user
*/
istream& operator>>(istream &inStream, Complex &com) {

	inStream >> com.r >> com.i;
	if (com.i == 0)
	{
		com.r = 0;
		com.i = 1;
	}
	return inStream;
}
