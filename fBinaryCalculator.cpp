#include "fBinaryCalculator.h"
#include <iostream>
#include <string>


//fBinaryCalculator::fBinaryCalculator(std::string a, std::string b) {

//}
fBinaryCalculator::fBinaryCalculator(std::string ainput, std::string binput, short nma, short me)
{
	
	binnum a, b;
	n = nma;
	m = me;
	a.rep = ainput;
	a.mantissa = "";
	a.exponent = "";
	a.sign = "";
	a.nbin = "";
	a.expdec = 0;
	a.expbias = 0;

	b.rep = ainput;
	b.mantissa = "";
	b.exponent = "";
	b.sign = "";
	b.nbin = "";
	b.expdec = 0;
	b.expbias = 0;

	a = initBinaryVars(a);
	b = initBinaryVars(b);

		
}


fBinaryCalculator::~fBinaryCalculator()
{
}

fBinaryCalculator::binnum fBinaryCalculator::initBinaryVars(binnum input) {
	binnum x = input;

	x.rep = input.rep;
	
	x.sign, x.exponent, x.mantissa = "";

	//Separate sign
	x.sign = x.rep[0];
	std::cout << "A : " << x.rep << "\n";
	std::cout << " size : " << x.rep.size()+1 << "\n";
	if (x.sign == "0")
		std::cout << " Sign : +\n";
	else
		std::cout << " Sign : -\n";
	// Separate exponent
	std::cout << " m : " << m << std::endl;
	for (int i = 1; i < m + 1; i++) 
		x.exponent += x.rep[i];

	std::cout << " Exponent in Binary: " << x.exponent << "\n";


	// Separate mantissa
	for (int i = m + 1; i < x.rep.size(); i++) {
		x.mantissa += x.rep[i];
	}

	std::cout << " Mantissa : " << x.mantissa << "\n";


	long num = stoi(x.exponent);
	long bin = num;
	long rem, dec = 0, base = 1;
	while (num > 0) {
		rem = num % 10;
		dec = dec + rem * base;
		base = base * 2;
		num = num / 10;
	}

	int bias = pow(2, m - 1) - 1;

	x.expbias = dec - bias;
	std::cout << " The decimal equivalent of exponent " << bin << " : " << dec << std::endl;
	std::cout << " Exponent with Bias: 2^" << x.expbias << "\n";

	std::string s;
	int expl = std::abs(x.expbias);

	for (int i = 0; i < expl - 1; i++) {
		s += "0";
	}
	x.nbin += "." + s + x.mantissa;//space was here at the end. Converted exponent into binary and added to the representation.

	std::cout << " FP Binary in IEEE 754 form: " << x.sign << " " << x.exponent << " " << x.mantissa << std::endl;
	std::cout << " FP Binary in . form : " << x.nbin << std::endl;
	std::cout << " FP Binary in scientific notation : ";
	if (x.sign == "0")
		std::cout << "+ ";
	else
		std::cout << "- ";
	std::cout << "1." << x.mantissa << " x 2^" << x.expbias << std::endl; 
	return x; 
}

std::string fBinaryCalculator::fBinAdd(double a, double b) {

	return "";
}

std::string fBinaryCalculator::fBinMult(double, double) {
	return "";
}
