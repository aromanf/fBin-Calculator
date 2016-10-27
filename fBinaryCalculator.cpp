#include "fBinaryCalculator.h"
#include <iostream>
#include <string>


fBinaryCalculator::fBinaryCalculator(std::string ainput, std::string binput) {
	n = 23;
	m = 8;
	a.rep = ainput;
	a.mantissa = "";
	a.exponent = "";
	a.sign = "";
	a.nbin = "";
	a.expdec = 0;
	a.expbias = 0;

	b.rep = binput;
	b.mantissa = "";
	b.exponent = "";
	b.sign = "";
	b.nbin = "";
	b.expdec = 0;
	b.expbias = 0;

	a = initBinaryVars(a);
	b = initBinaryVars(b);
}
fBinaryCalculator::fBinaryCalculator(std::string ainput, std::string binput, short nma, short me)
{
	n = nma;
	m = me;
	a.rep = ainput;
	a.mantissa = "";
	a.exponent = "";
	a.sign = "";
	a.nbin = "";
	a.expdec = 0;
	a.expbias = 0;

	b.rep = binput;
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
	std::cout << " size : " << x.rep.size() << "\n";
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

std::string fBinaryCalculator::fBinAdd() {
	binnum res;
	if (a.sign == "0" && b.sign == "0") {
		res.sign = "0";
		std::cout << "Result sign = " << res.sign << std::endl;
		if (a.expbias > b.expbias) {
			res.expbias = b.expbias;
			std::cout << "Result Exponent with bias > = " << res.expbias << std::endl;
			res.mantissa = subMantissa();

			std::cout << " FP Binary in scientific notation : ";
			if (res.sign == "0")
				std::cout << "+ ";
			else
				std::cout << "- ";
			std::cout << "1." << res.mantissa << " x 2^" << res.expbias << std::endl;

			
		}
		if (a.expbias < b.expbias) {
			res.expbias = b.expbias;
			std::cout << "Result Exponent with bias < = " << res.expbias << std::endl;
			res.mantissa = subMantissa();

			std::cout << " FP Binary in scientific notation : ";
			if (res.sign == "0")
				std::cout << "+ ";
			else
				std::cout << "- ";
			std::cout << "1." << res.mantissa << " x 2^" << res.expbias << std::endl;

		}
		else {
			res.expbias = a.expbias;
			std::cout << "Result Exponent with bias == " << res.expbias << std::endl;
			res.mantissa = subMantissa();

			std::cout << " FP Binary in scientific notation : ";
			if (res.sign == "0")
				std::cout << "+ ";
			else
				std::cout << "- ";
			std::cout << "1." << res.mantissa << " x 2^" << res.expbias << std::endl;
		}
			
	}

	if (a.sign == "1" && b.sign == "1") {
		res.sign = "1";
		std::cout << "Result sign = " << res.sign << std::endl;
	}
	return "";
}

std::string fBinaryCalculator::fBinMult(double, double) {
	return "";
}


// Adds the mantissa of a and b.
std::string fBinaryCalculator::addMantissa(std::string ainput, std::string binput)
{
	int carry=0;
	std::string amantissa = ainput;
	std::string bmantissa = binput;
	std::string rmantissa = amantissa;
	for (int i = amantissa.size()-1; i >= 0; i--) {
		std::cout << "\n Carry = " << carry << "  ";
		//std::cout << "bbin : " << b.mantissa[i] << std::endl;
		if (amantissa[i] == '1' && bmantissa[i] == '1') {
			//std::cout << "Carry = " << carry << "\n";
			if (carry == 1) {
				//std::cout << "trigger 1+1 C=1\n";
				rmantissa[i] = '1';
				carry = 1;
			}
		if (i == 0 && carry == 1)
			std::cout << "Overflow.\n";
		if (amantissa[i] == '1' && bmantissa[i] == '1') {
		//	std::cout << "Carry = " << carry << "\n";
			if (carry == 0) {
				//std::cout << "trigger 1+1 C=0\n";
				rmantissa[i] = '0';
				carry = 1;
			}
		}
		
			
		}
		if (amantissa[i] == '0' && bmantissa[i] == '0' && carry == 0) {
			std::cout << "trigger 0+0 C=0\n";
			rmantissa[i] = '0';
			carry = 0;
		}
		if (amantissa[i] == '0' && bmantissa[i] == '0' && carry == 1) {
			std::cout << "trigger 0+0 C=1\n";
			rmantissa[i] = '1';
			carry = 0;
		}
		if ((amantissa[i] == '1' && bmantissa[i] == '0' && carry == 0) 
			|| (amantissa[i] == '0' && bmantissa[i] == '1' && carry == 0)) {
			//std::cout << "trigger 1+0 OR 0+1 C=0\n";
			rmantissa[i] = '1';
			carry = 0;
		}
		if ((amantissa[i] == '1' && bmantissa[i] == '0' && carry == 1)
			|| (amantissa[i] == '0' && bmantissa[i] == '1' && carry == 1)) {
			//std::cout << "trigger 1+0 OR 0+1 C=1\n";
			rmantissa[i] = '0';
			carry = 1;
		}
			
		std::cout << "" << amantissa[i];
		std::cout << " + " << bmantissa[i];
		std::cout << " = " << rmantissa[i];
		
	}
	std::cout << "\nabin : " << amantissa << std::endl;
	std::cout << "bbin : " << bmantissa << std::endl;
	std::cout << "________________________________\n";
	std::cout << "RBin : " << rmantissa << std::endl;
	return rmantissa;
}


// Substract two mantissa values.
std::string fBinaryCalculator::subMantissa()
{
	std::string amantissa = a.mantissa;
	std::string bmantissa = b.mantissa;
	std::string rmantissa = a.mantissa;
	std::string omantissa = b.mantissa; // Using this string to contain only a 1.
	std::string tmantissa = " "; // Two's Complement of B.

	// Two's Complement
	for (int i = 0; i < bmantissa.size(); i++) {
		std::cout << "B[" << i << "]: " << bmantissa[i] << "\n";
		if (bmantissa[i] == '0')
			bmantissa[i] = '1';
		else
			bmantissa[i] = '0';
		std::cout << "B[" << i << "] after change: " << bmantissa[i] << "\n";
	}

	// Turn omantissa into only a 1
	for (int i = 0; i < bmantissa.size(); i++) 
		omantissa[i] = '0';
	omantissa[omantissa.size()-1] = '1';
	
	// Add one to inverted b to complete Two's Complement
	addMantissa(bmantissa, omantissa);
	std::cout << "Mantissa with a one : " << omantissa << "\n";
	std::cout << "b on regular : " << b.mantissa << "\n";
	tmantissa = addMantissa(bmantissa, omantissa);
	std::cout << "b on Two's Complement : " << tmantissa << "\n";

	// Add amantissa and Two's Complemented Mantissa to get result of substraction.
	
	
	return addMantissa(amantissa, tmantissa);
}
