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
	fBinaryCalculator(std::string ainput, std::string binput);
	fBinaryCalculator(std::string ainput, std::string binput, short me, short nm);
	~fBinaryCalculator();
	std::string fBinAdd();
	std::string fBinMult(double, double);
	binnum fBinaryCalculator::initBinaryVars(binnum input);

	binnum a, b;

	// Adds the mantissa of a and b.
	std::string addMantissa();
};

