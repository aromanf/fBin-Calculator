#include "fBinaryCalculator.h"
#include <iostream>
#include <string>


//fBinaryCalculator::fBinaryCalculator(std::string a, std::string b) {

//}
fBinaryCalculator::fBinaryCalculator(std::string ainput, std::string binput, short m, short n)
{
	/*
	binnum a, b;
	a.rep = ainput;
	b.rep = binput;
	std::string sign, exponent, mantissa = "";
	
	a.expdec = 0;
	b.expdec = 0;

	//Separate sign
	sign = repA[0];
	std::cout << "A : " << repA << "\n";
	std::cout << " size : " << repA.size() << "\n";
	if (sign == "0")
		std::cout << " Sign : +\n";
	else
		std::cout << " Sign : -\n";
	// Separate exponent
	for (int i = 1; i < n + 1; i++)
		exponent += repA[i];
	std::cout << " Exponent in Binary: " << exponent << "\n";


	// Separate mantissa
	for (int i = n + 1; i < repA.size(); i++) {
		mantissa += repA[i];
	}

	std::cout << " Mantissa : " << mantissa << "\n";


	long num = stoi(exponent);
	long bin = num;
	long rem, dec = 0, base = 1;
	while (num > 0) {
		rem = num % 10;
		dec = dec + rem * base;
		base = base * 2;
		num = num / 10;
	}
	expdec = dec;
	long expbias = dec - 127;
	std::cout << " The decimal equivalent of exponent " << bin << " : " << dec << std::endl;
	std::cout << " Exponent with Bias: 2^" << expbias << "\n";

	std::string nbin = "";
	std::string s;
	int expl = std::abs(expbias);

	for (int i = 0; i < expl - 1; i++) {
		s += "0";
	}
	nbin += "." + s + mantissa;

	std::cout << " FP Binary in IEEE 754 form: " << sign << " " << exponent << " " << mantissa << std::endl;
	std::cout << " FP Binary in . form : " << nbin << std::endl;
	std::cout << " FP Binary in scientific notation : ";
	if (sign == "0")
		std::cout << "+ ";
	else
		std::cout << "- ";
	std::cout << "1." << mantissa << " x 2^" << expbias << std::endl;
	*/
}


fBinaryCalculator::~fBinaryCalculator()
{
}

double fBinaryCalculator::fBinAdd(double a, double b) {

	return 0;
}

double fBinaryCalculator::fBinMult(double, double) {
	return 0;
}
