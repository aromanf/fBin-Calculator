
/*********************************************************
Computer Architecture Project : Code 2
Written by Antonio F. Roman , Moises
fBinaryConverter.cpp - Definition for
	fBinaryConverter.h. Converts decimal numbers to binary
	representations.
**********************************************************/
#include <iostream>
#include <string>
#include "fBinaryConverter.h"



	fBinaryConverter::fBinaryConverter() {
		MANTRISSA_LENGTH = 23;
		EXPONENT_LENGTH = 8;
		fractionBinaryLength = 0;
		integerBinaryLength = 0;

		integerPart = 0;
		fractionPart = 0;
		exponent = 0;
		i = 0;
		integerBinary = "";
		fractionBinary = "";
		representation = "";
		s = "";
	}

	fBinaryConverter::fBinaryConverter(short mantisse, short exp) {
		MANTRISSA_LENGTH = mantisse;
		EXPONENT_LENGTH = exp;
		fractionBinaryLength = 0;
		integerBinaryLength = 0;

		integerPart = 0;
		fractionPart = 0;
		exponent = 0;
		i = 0;
		integerBinary = "";
		fractionBinary = "";
		representation = "";
		s = "";
	}

	fBinaryConverter::~fBinaryConverter() {

	}
	
	const std::string fBinaryConverter::int2bin(int n) {
		std::string res;

		while (n)
		{
			res.push_back((n & 1) + '0');
			n >>= 1;
		}

		if (res.empty())
			res = "0";
		else
			std::reverse(res.begin(), res.end());

		return res;
	}

	const std::string fBinaryConverter::float2bin(int input) {
		std::string s = "", t;
		int ceiling, i = 0, j = 0, k;
		//std::cout << "float2Bin(" << input << ")\n";

		if (input == 0) return "0";

		for (ceiling = 10; input >= ceiling; ceiling *= 10);
		//std::cout << "Ceiling: " << ceiling << "\n";

		while (input > 0 && i <= MANTRISSA_LENGTH) {
			for (k = input, t = ""; k < ceiling / 10; k *= 10, t += "0");
			//std::cout << "0." << t << input << " * 2 = ";
			j = input * 2;

			if (j >= ceiling) {
				for (k = j, t = ""; k - ceiling < ceiling / 10; k *= 10, t += "0");
				//std::cout << "1." << t << (j - ceiling) << "\n";
			}
			else {
				for (k = j, t = ""; k < ceiling / 10; k *= 10, t += "0");
				//std::cout << "0." << t << j << "\n";
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

	const std::string fBinaryConverter::float2fbin(std::string input) {
		// Separate Integer from Floating
		integerPart = std::stoi(input.substr(0, input.find(".")));
		fractionPart = std::stoi(input.substr(input.find(".") + 1));
		std::cout << "integerPart = " << integerPart << "\n";
		std::cout << "fractionPart = " << fractionPart << "\n";

		integerPart = abs(integerPart);
		//std::cout << "abs : " << integerPart << "\n";
		integerBinary = int2bin(integerPart);
		fractionBinary = float2bin(fractionPart);

		//Display in Binary
		std::cout << integerPart << "." << fractionPart << " in binary: "
			<< integerBinary << "." << fractionBinary << "\n";

		// Create exponent in decimal
		if (integerPart != 0)
			exponent = 127 + integerBinary.length() - 1;
		else if (fractionPart != 0)
			exponent = 127 - fractionBinary.find("1");
		else
			exponent = 0;

		//setting bit sign
		representation = (input[0] == '-' ? "1" : "0"); // space was after the number sign bits

		//representation loop
		std::string expBin = int2bin(exponent);
		if (expBin.size() > EXPONENT_LENGTH)
			std::cout << "Error. Required exponent " << expBin.size() << " is higher than the exponent entered : " << EXPONENT_LENGTH << ".\n";

		for (s = "", i = expBin.size(); i < EXPONENT_LENGTH; s += "0", i++);
		representation += s + int2bin(exponent); //space was here at the end. Converted exponent into binary and added to the representation.

		if (integerPart != 0) {
			s = integerBinary + fractionBinary;
			representation += s.substr(1, s.length() - 1 < MANTRISSA_LENGTH ? s.length() : MANTRISSA_LENGTH);
		}
		else if (fractionPart != 0)
			representation += fractionBinary.substr(fractionBinary.find("1") + 1);

		for (s = "", i = getFractionBinLen() - 1; i < MANTRISSA_LENGTH - 1; s += "0", i++);
		representation += s;

		return representation;
	}

	short fBinaryConverter::getFractionBinLen()
	{
		return fractionBinaryLength;
	}




	// Convert binary to decimal.
	long fBinaryConverter::bin2dec(std::string calinput)
	{
		long num = stoi(calinput);
		long bin = num;
		long rem, dec = 0, base = 1;
		while (num > 0) {
			rem = num % 10;
			dec = dec + rem * base;
			base = base * 2;
			num = num / 10;
		}
		return dec;
	}
