#include <iostream>
#include "binaryf.h"


// Main function for running program and testing binary conversions.
int main()
{
	float floatInput = 0.2;
	int input;
	
	std::cout << "Floating Point Binary Program :\n\n";
	std::cout << "Enter value for floating point: ";
	std::cin >> input;
	std::cout << "Binary Conversion : " << float2bin(input) << "\n";
}