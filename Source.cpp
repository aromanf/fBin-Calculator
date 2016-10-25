#include <iostream>
#include <string>
#include <stdlib.h>
#include "binaryf.h"

// Main function for running program and testing binary conversions.

int main()
{
	std::string input, rep;
	
	
	std::cout << "Floating Point Binary Program :\n\n";

	


	std::cout << "Enter value for floating point: ";
	std::cin >> input;
	rep = float2fbin(input);

	std::cout << "Floating point representation:\n" << rep << "\n";



}