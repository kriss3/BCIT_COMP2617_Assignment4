// Assignment 4 Solution: Fraction.h
// Declaration of class Fraction.
// Member functions are defined in Fraction.cpp.
// Author: Bob Langelaan 
// Date: Oct 29th, 2013

#ifndef Fraction_incl
#define Fraction_incl

class Fraction  // Fraction class
{
public:
	Fraction (void); // default ctor
	Fraction (long long num, long long denom = 1 );  // second ctor, which
	   // requires at least one long long argument
	 
	const Fraction & plusEq (const Fraction & RHS ) ; //Adds RHS to the Fraction object invoked with this method
	                                      //  (thereby modifying the Fraction object) and returns the result
	const Fraction & minusEq (const Fraction & RHS ) ; //Subtracts RHS from the Fraction object invoked with this method
	                                      //  (thereby modifying the Fraction object) and returns the result
	const Fraction & timesEq (const Fraction & RHS ) ; //Multiplies RHS by the Fraction object invoked with this method
	                                      //  (thereby modifying the Fraction object) and returns the result
	const Fraction & divideEq (const Fraction & RHS ) ; //Divides RHS into the Fraction object invoked with this method
	                                      //  (thereby modifying the Fraction object) and returns the result

	Fraction negate (void)const; //Returns the negation of the Fraction object
	                        //  invoked with the method but must NOT
	                        //  modify the actual Fraction object invoked
	                        //  with the method.

	long long getNum(void)const;   // Returns numerator
	long long getDenom(void)const; // Returns denominator

	void display(void)const; // Outputs to standard output stream the Fraction object
	                    //   in the format: numerator/denominator

private:

	void simplify (void); // this method reduces the Fraction objects as much
	                      //  as possible.  It also ensures that the denominator is
	                      //  positive.
	long long numerator, // represents numerator of Fraction object
		denominator;     // represents denominator of Fraction object

};
#endif