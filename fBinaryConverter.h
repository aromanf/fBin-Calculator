/*********************************************************
Computer Architecture Project : Code 2
Written by Antonio F. Roman , Moises
fBinaryConverter.cpp - Declaration for
	fBinaryConverter.h. Converts decimal numbers to binary
	representations.
**********************************************************/
#pragma once
#include <string>

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
	// Convert binary to decimal.
	long bin2dec(std::string calinput);
};






