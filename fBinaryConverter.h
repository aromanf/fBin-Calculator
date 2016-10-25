#pragma once
#include <string>
// binaryf.h : Functions related to the conversion and operation of binary numbers in the IEEE754 Standard.
//
class fBinaryConverter {
private:
	short MANTRISSA_LENGTH, EXPONENT_LENGTH;
	short fractionBinaryLength;
	short integerBinaryLength;
	std::string integerBinary, fractionBinary, representation, s;
	int integerPart, fractionPart, exponent, i;
public:
	fBinaryConverter(); // Constructor
	fBinaryConverter(short mantisse, short exp);
	~fBinaryConverter();
	const std::string int2bin(int n);
	const std::string float2bin(int);
	const std::string float2fbin(std::string);
	
	short getFractionBinLen();
};






