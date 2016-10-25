#include <iostream>
#include <stdlib.h>
#include "binaryf.h"

static short TEMP_EXPONENT = 8, TEMP_MANTISSA = 23;


// Main function for running program and testing binary conversions.

int main()
{
	std::string input;
	std::string integerBinary, fractionBinary, representation, s;
	int integerPart, fractionPart, exponent, i;
	
	std::cout << "Floating Point Binary Program :\n\n";

	


	std::cout << "Enter value for floating point: ";
	std::cin >> input;

	// Separate Integer from Floating
	integerPart = std::stoi(input.substr(0, input.find(".")));
	fractionPart = std::stoi(input.substr(input.find(".") + 1));
	std::cout << "integerPart = " << integerPart << "\n";
	std::cout << "fractionPart = " << fractionPart << "\n";
	

	integerPart = abs(integerPart);
	std::cout << "abs : " << integerPart << "\n";
	integerBinary = int2bin(integerPart);
	fractionBinary = float2bin(fractionPart);

	//Display in Binary
	std::cout << integerPart << "." << fractionPart << " in binary: "  
		<< "\n" << integerBinary << "." << fractionBinary << "\n";

	if (integerPart != 0)
		exponent = 127 + integerBinary.length() - 1;
	else if (fractionPart != 0)
		exponent = 127 - fractionBinary.find("1");
	else
		exponent = 0;

	//setting bit sign
	representation = (input[0] == '-' ? "1 " : "0 ");

	//representation loop
	for (s = "", i = sizeof(int2bin(exponent)); i < TEMP_EXPONENT; s += "0", i++);
	representation += s + int2bin(exponent) + " ";

	if (integerPart != 0) {
		s = integerBinary + fractionBinary;
		representation += s.substr(1, s.length() - 1 < TEMP_MANTISSA ? s.length() : TEMP_MANTISSA);
	}
	else if (fractionPart != 0)
		representation += fractionBinary.substr(fractionBinary.find("1") + 1);

	for (s = "", i = getFractionBinLen()-1; i < TEMP_MANTISSA - 1; s += "0", i++);
	representation += s;

	std::cout << "Floating point representation:\n" << representation << "\n";



}