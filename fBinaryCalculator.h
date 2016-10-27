/*********************************************************
Computer Architecture Project : Code 2
Written by Antonio F. Roman , Moises
fBinaryConverter.h - Declaration for
fBinaryConverter.cpp. Converts decimal numbers to binary
representations.
**********************************************************/
#pragma once
#include <iostream>
#include <string>
class fBinaryCalculator
{
private:
	short m; // Max Exponent  
	short n; // Max Mantissa 
	struct binnum {
		std::string rep;
		std::string mantissa;
		std::string exponent;
		std::string sign;
		std::string nbin;
		long expdec;
		long expbias;
	};
public:
	// Constructor takes two string binary representations and initializes them. 
	// This constructor initializes the representation to a 32 bit representation.
	fBinaryCalculator(std::string ainput, std::string binput);
	// Constructor takes two string binary representations and initializes them. 
	// This constructor initializes the representation to a user defined mantissa and exponent.
	fBinaryCalculator(std::string ainput, std::string binput, short me, short nm);
	~fBinaryCalculator();
	std::string fBinAdd();
	std::string fBinMult(double, double);
	binnum fBinaryCalculator::initBinaryVars(binnum input);

	binnum a, b;

	// Adds the mantissa of a and b.
	std::string addMantissa(std::string ainput, std::string binput);
	// A addMantissa with overflow warning turned off as Two's Complement will cause it anyway.
	std::string addsMantissa(std::string ainput, std::string binput);
	// Substract two mantissa values.
	std::string subMantissa(std::string ainput, std::string binput);
	// Small convert for turning a binary into a decimal for light comparisons.
	long calbconvert(std::string binput);
};

