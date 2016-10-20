// binconvert.cpp : Functions related to the conversion of binary numbers in the IEEE754 Standard.
//
#include "binaryf.h"


const std::string float2bin(const float floatp) {
	fval input;

	input.flt = floatp;
	std::bitset<sizeof(float) * CHAR_BIT > fbits(input.intval);
	return fbits.to_string<char, std::char_traits<char>, std::allocator<char>>();
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