/*********************************************************
	Computer Architecture Project : Code 2
	Written by Antonio F. Roman , Moises 
    Source.cpp - Main function for converting decimal to 
		binary numbers, and adding two binary 
		representations. 
**********************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include "fBinaryConverter.h"
#include "fBinaryCalculator.h"

// Main function for running program and testing binary conversions.

int main()
{
	
	std::string input; 
	std::string repA = "";
	std::string repB = "";
	std::string A = "";
	std::string B = "";
	short n; // n : bits of mantissa. m < n.
	short m; // m : bits of exponent.

	
	std::cout << "Floating Point Binary Calculator :\n\n";
	std::cout << "Enter bits of mantissa ( 8 to 64 ) : ";
	std::cin >> n;
	std::cout << "Enter bits of exponent ( 7 to 10 ) : ";
	std::cin >> m;

	std::cout << "Enter value of A : ";
	std::cin >> A;
	std::cout << "Enter value of B : ";
	std::cin >> B;
	std::cout << "\n";
	fBinaryConverter a(n, m);
	fBinaryConverter b(n, m);
	repA = a.float2fbin(A);
	repB = b.float2fbin(B);
	std::cout << "Floating point representation: " << repA << "\n\n";
	std::cout << "Floating point representation: " << repB << "\n\n";
	
	fBinaryCalculator calculator(repA,repB);
	calculator.fBinAdd();
	
	return 0;
}


	


	


	
	
	



