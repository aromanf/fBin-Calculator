#pragma once
#include <iostream>
#include <string>
class fBinaryCalculator
{
public:
	//fBinaryCalculator(std::string a, std::string b);
	fBinaryCalculator(std::string ainput, std::string binput, short m, short n);
	~fBinaryCalculator();
	double fBinAdd(double, double);
	double fBinMult(double, double);
private:
	std::string repA;
	std::string repB;
	struct binnum {
		std::string rep;
		std::string mantissa;
		std::string exponent;
		std::string sign;
		std::string nbin;
		long expdec;
		long expbias;
	};
};

