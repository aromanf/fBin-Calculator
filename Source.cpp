#include <iostream>
#include <string>
#include <stdlib.h>
#include "fBinaryConverter.h"

// Main function for running program and testing binary conversions.

int main()
{

	std::string input, repA, repB;
	short n; // n : bits of mantissa. m < n.
	short m; // m : bits of exponent.


	std::cout << "Floating Point Binary Calculator :\n\n";
	std::cout << "Enter bits of mantissa ( 8 to 64 ) : ";
	std::cin >> n;
	std::cout << "Enter bits of exponent ( 7 to 10 ) : ";
	std::cin >> m;

	std::cout << "Enter value for floating point: ";
	std::cin >> input;
	std::cout << "\n";
	fBinaryConverter a; // When no value is specified for n or m then default IEEE 754 is used. n= 23, m=8.
	fBinaryConverter b(n, m);
	repA = a.float2fbin(input);
	std::cout << "Floating point representation: " << repA << "\n\n";

	repB = b.float2fbin(input);
	std::cout << "Floating point representation: " << repB << "\n\n";



	// Testing extracting values from a string

	std::string exma = "00111110110011001100110011001101"; // exp = 125 | 2^-2
	std::string exmb = "00111111000110011001100110011010"; // exp = 126 | 2^-1
	//std::string exma = repA;
	//std::string exmb = repB;
	//short n = 23, m = 8;
	std::string sign, exponent, mantissa = "";

	//Separate sign
	sign = exma[0];
	std::cout << "A : " << exma << "\n";
	std::cout << " size : " << exma.size() << "\n";
	if (sign == "0")
		std::cout << " Sign : +\n";
	else
		std::cout << " Sign : -\n";
	// Separate exponent
	for (int i = 1; i < m + 1; i++)
		exponent += exma[i];
	std::cout << " Exponent in Binary: " << exponent << "\n";


	// Separate mantissa
	for (int i = m + 1; i < exma.size(); i++) {
		mantissa += exma[i];
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
	long expbias = dec - 127;
	std::cout << " The decimal equivalent of exponent " << bin << " : " << dec << std::endl;
	std::cout << " Exponent with Bias: 2^" << expbias << "\n";

	std::string nbin = "";
	std::string s;
	int expl = std::abs(expbias);

	for (int i = 0; i < expl - 1; i++) {
		s += "0";
	}
	nbin += "." + s + mantissa;//space was here at the end. Converted exponent into binary and added to the representation.

	std::cout << " FP Binary in IEEE 754 form: " << sign << " " << exponent << " " << mantissa << std::endl;
	std::cout << " FP Binary in . form : " << nbin << std::endl;
	std::cout << " FP Binary in scientific notation : ";
	if (sign == "0")
		std::cout << "+ ";
	else
		std::cout << "- ";
	std::cout << "1." << mantissa << " x 2^" << expbias << std::endl;
	

	return 0;
}


	


	


	
	
	



