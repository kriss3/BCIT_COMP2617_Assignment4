// Assignment 4: Fraction.cpp
// Member-function definitions for class Fraction.
// Author:  
// Date: 

#include "Fraction.h"
#include "GCD.h" // template function for calculating greatest common divisor
#include <iostream>
using namespace std;


Fraction::Fraction() : numerator(0), denominator(0) { }

Fraction::Fraction(long long a, long long b): numerator(a), denominator(b) {}

//Implementation of the timesEq() member function
//Performs similar operation as the *= operator on the built-in types
const Fraction & Fraction::timesEq(const Fraction & op )
{
	numerator *= op.numerator;
	denominator *= op.denominator;

	simplify();  // will make sure that denominator is positive and
	             //   will invoke gcd() function to reduce fraction
	             //   as much as possible

	return (*this); // returns the object which invoked the method
}

const Fraction & Fraction::minusEq(const Fraction & op) 
{
	numerator -= op.numerator;
	denominator -= op.denominator;

	simplify();

	return (*this);
}

const Fraction & Fraction::plusEq(const Fraction& op)
{
	return (*this);
}

const Fraction & Fraction::divideEq(const Fraction& op)
{
	return (*this);
}

Fraction Fraction::negate(void) const
{
	auto a = Fraction();
	return a;
}

long long Fraction::getNum(void) const 
{
	return numerator;
}

long long Fraction::getDenom(void) const
{
	return denominator;
}

void Fraction::display(void) const
{
	cout << "Test display()";
}

void Fraction::simplify(void) 
{
	cout << "Test simplify()";
	int t = gcd(numerator, denominator);
}