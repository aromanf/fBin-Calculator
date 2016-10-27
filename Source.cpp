#include <iostream>
#include <string>
#include <stdlib.h>
#include "fBinaryConverter.h"
#include "fBinaryCalculator.h"

// Main function for running program and testing binary conversions.

int main()
{
	
	std::string input; 
	std::string repA = "00111110110011001100110011001101";
	std::string repB = "00111111000110011001100110011010";
	//short n; // n : bits of mantissa. m < n.
	//short m; // m : bits of exponent.

	/*
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
	*/
	fBinaryCalculator calculator(repA,repB);
	calculator.fBinAdd();
	
	return 0;
}


	


	


	
	
	



