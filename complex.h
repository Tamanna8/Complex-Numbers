/*
Name: Tamanna Sharma
Class: CSS 342
Quarter: Fall 2017
Version: 10/13/2017 1.0

complex.h : This is the header file for complex.cpp
*/
#pragma once
#include <iostream>
using namespace std;

class Complex {
private:
	double r, i;
public:

	//Operator for constructor with no argument
	Complex();
	//Operator for constructor with one argument
	Complex(double r);
	//Operator for constructor with two argument
	Complex(double r, double i);

	//Operator to get the real value of the complex number
	double getReal() const;
	// Operator to get the imaginary value of complex number
	double getImaginary() const;

	// Operator for += function to add and update the complex numbers
	Complex& operator+=(const Complex &com);
	// Operator for -= function to subtract and update the complex numbers
	Complex& operator-=(const Complex &com);
	// Operator for *= function to muliply and update the complex numbers
	Complex& operator*=(const Complex &com);
	// Operator for /= function to divide and update the complex numbers
	Complex& operator/=(const Complex &com);

	// Operator for addition function, which adds and return a complex value
	Complex operator+(const Complex &com) const;
	// Operator for subtraction function, which subtracts and return a complex value
	Complex operator-(const Complex &com) const;
	// Operator for multiplication function, which multiplies and return a complex value
	Complex operator*(const Complex &com) const;
	// Operator for division function, which divides and return a complex value
	Complex operator/(const Complex &com) const;

	// Operator for conjugate function, which conjugates the complex number and return a complex value
	Complex conjugate();

	// Operator for equals comparison function, which compare if the complex numbers are equal
	bool operator==(Complex);
	// Operator for not equals comparison function, which compare if the complex numbers are not equal
	bool operator!=(Complex);

	//Friend function for output of the complex number
	friend ostream& operator<<(ostream &outStream, const Complex &comp);
	//Friend function for input of the complex number by the user
	friend istream& operator>>(istream &inStream, Complex &comp);
};