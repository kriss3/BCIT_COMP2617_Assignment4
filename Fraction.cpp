// Assignment 4: Fraction.cpp
// Member-function definitions for class Fraction.
// Author:  
// Date: 

#include "Fraction.h"
#include "GCD.h" // template function for calculating greatest common divisor
#include <iostream>
using namespace std;

const int NEGATIVE_SWITCHER = -1;

Fraction::Fraction() : numerator(0), denominator(1) { }

Fraction::Fraction(long long a, long long b): numerator(a), denominator(b)
{
	simplify();
}

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
	numerator *= op.denominator;
	denominator *= op.numerator;

	simplify();

	return (*this);
}

Fraction Fraction::negate(void) const
{
	long long tempVal1 = getNum(); 
	long long tempVal2 = getDenom();

	if (tempVal1 < 0 || tempVal1 > 0)
	{
		tempVal1 = -tempVal1;
	}


	return Fraction(tempVal1, tempVal2);
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
	cout << getNum() << "/" << getDenom();
}

void Fraction::simplify(void) 
{
	long long result = gcd(numerator, denominator);

	numerator /= result;
	denominator /= result;

	if (denominator < 0)
	{
		denominator *= NEGATIVE_SWITCHER;
		numerator *= NEGATIVE_SWITCHER;
	}
}