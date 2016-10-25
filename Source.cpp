#include <iostream>
#include <string>
#include <stdlib.h>
#include "fBinaryConverter.h"

// Main function for running program and testing binary conversions.

int main()
{
	std::string input, rep;
	
	
	std::cout << "Floating Point Binary Program :\n\n";

	


	std::cout << "Enter value for floating point: ";
	std::cin >> input;
	fBinaryConverter a;
	fBinaryConverter b(23,5);
	rep = a.float2fbin(input);
	std::cout << "Floating point representation:\n" << rep << "\n";

	rep = b.float2fbin(input);
	std::cout << "Floating point representation:\n" << rep << "\n";

	



}