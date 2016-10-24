// binaryf.h : Functions related to the conversion and operation of binary numbers in the IEEE754 Standard.
//
#pragma once
#include <iostream>
#include <bitset>

union fval {
	float flt;
	double val2b;
	int intval;
};

const std::string float2bin(int);
const float bin2float(const std::string& binString);
double binAdd(double, double);
double binMult(double, double);



