#include <iostream>
#include "binaryf.h"


// Main function for running program and testing binary conversions.
int main()
{
	std::string input;
	std::string integerBinary, fractionBinary, representation, s;
	int integerPart, fractionPart;
	
	std::cout << "Floating Point Binary Program :\n\n";


	std::cout << "Enter value for floating point: ";
	std::cin >> input;

	// Separate Integer from Floating
	integerPart = std::stoi(input.substr(0, input.find(".")));
	fractionPart = std::stoi(input.substr(input.find(".") + 1));
	std::cout << "integerPart = " << integerPart << "\n";
	std::cout << "fractionPart = " << fractionPart << "\n";
	std::cout << "Binary Conversion : " << float2bin(fractionPart) << "\n";
}