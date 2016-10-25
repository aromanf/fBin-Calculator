#pragma once
#include <string>
// binaryf.h : Functions related to the conversion and operation of binary numbers in the IEEE754 Standard.
//
const std::string float2fbin(std::string);
const std::string int2bin(int n);
const std::string float2bin(int);
const float bin2float(const std::string& binString);
double binAdd(double, double);
double binMult(double, double);
short getFractionBinLen();





