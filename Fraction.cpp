// Assignment 4: Fraction.cpp
// Member-function definitions for class Fraction.
// Author:   Krzysztof Szczurowski
// ID: A01013054
// Date: October 12th 2019

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
	long long tempDenum = getDenom();
	long long tempOpDenum = op.denominator;
	if (denominator == op.denominator)
	{
		numerator += op.numerator;
	}
	else
	{
		denominator *= op.denominator;
		numerator = (denominator / tempDenum * numerator) - (denominator / tempOpDenum * op.numerator);
	}

	simplify();

	return (*this);
}

const Fraction & Fraction::plusEq(const Fraction& op)
{
	long long tempDenum = getDenom();
	long long tempOpDenum = op.denominator;

	if (denominator == op.denominator)
	{
		numerator += op.numerator;
	}
	else 
	{
		denominator *= op.denominator;
		numerator = (denominator/tempDenum*numerator) + (denominator/tempOpDenum *op.numerator);
	}

	simplify();

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
	return Fraction(-numerator, denominator);
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