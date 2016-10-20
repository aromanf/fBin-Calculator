#include <iostream>
#include "binaryf.h"


// Main function for running program and testing binary conversions.
int main()
{
	float floatInput = 0.2;
	
	std::cout << "Floating Point Binary Program ::.\n\n";
	std::cout << "Enter value for float: ";
	std::cin >> floatInput;
	std::cout << "float2bin : " << float2bin(floatInput) << "\n";
}