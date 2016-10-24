// binconvert.cpp : Functions related to the conversion of binary numbers in the IEEE754 Standard.
//
#include "binaryf.h"
static short MANTRISSA_LENGTH = 23, EXPONENT_LENGTH = 8;
short fractionBinaryLength = 0;
short integerBinaryLength = 0;

const std::string float2bin(int input) {
	std::string s = "", t;
	int ceiling, i = 0, j = 0, k;
	std::cout << "float2Bin(" << input << ")\n";

	if(input == 0) return "0";

	for (ceiling = 10; input >= ceiling; ceiling *= 10);
	std::cout << "Ceiling: " << ceiling << "\n";

	while (input > 0 && i <= MANTRISSA_LENGTH) {
		for (k = input, t = ""; k < ceiling / 10; k *= 10, t += "0");
		std::cout << "0." << t << input << " * 2 = ";
		j = input * 2;

		if (j >= ceiling) {
			for (k = j, t = ""; k - ceiling < ceiling / 10; k *= 10, t += "0");
			std::cout << "1." << t << (j - ceiling) << "\n";
		}
		else {
			for (k = j, t = ""; k < ceiling / 10; k *= 10, t += "0");
			std::cout << "0." << t << j << "\n";
		}

		input *= 2;

		if (input >= ceiling) {
			s += "1";
			input -= ceiling;
		}
		else
			s += "0";

		i++;
		fractionBinaryLength++;
	}

	return s;	
}

const float bin2float(const std::string& binString) {
	std::cout << "Hello bin2float.\n";
	return 0.0;
}

double binAdd(double a, double b) {
	return 0;
}

double binMult(double a, double b) {
	return 0;
}