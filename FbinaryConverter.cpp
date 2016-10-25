
// binconvert.cpp : Functions related to the conversion of binary numbers in the IEEE754 Standard.
//
#include <iostream>
#include <string>
#include "fBinaryConverter.h"
#include "trim.h"


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

		/*	std::string s = "";
		int i, j = 0;

		for (i = 1; input >= i; i *= 2);
		if (i == 1) return "0";

		i /= 2;
		do {
		if (input >= i) {
		s += "1";
		input -= i;
		}
		else
		s += "0";

		//			if (++j == 3) {
		//				s += " ";
		//				j = 0;
		//			}

		i /= 2;
		integerBinaryLength++;
		} while (i > 1);

		s = trim(s);

		return s; */
	}

	const std::string fBinaryConverter::float2bin(int input) {
		std::string s = "", t;
		int ceiling, i = 0, j = 0, k;
		std::cout << "float2Bin(" << input << ")\n";

		if (input == 0) return "0";

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

	const std::string fBinaryConverter::float2fbin(std::string input) {
		// Separate Integer from Floating
		integerPart = std::stoi(input.substr(0, input.find(".")));
		fractionPart = std::stoi(input.substr(input.find(".") + 1));
		std::cout << "integerPart = " << integerPart << "\n";
		std::cout << "fractionPart = " << fractionPart << "\n";

		integerPart = abs(integerPart);
		std::cout << "abs : " << integerPart << "\n";
		integerBinary = int2bin(integerPart);
		fractionBinary = float2bin(fractionPart);

		//Display in Binary
		std::cout << integerPart << "." << fractionPart << " in binary: "
			<< "\n" << integerBinary << "." << fractionBinary << "\n";

		if (integerPart != 0)
			exponent = 127 + integerBinary.length() - 1;
		else if (fractionPart != 0)
			exponent = 127 - fractionBinary.find("1");
		else
			exponent = 0;

		//setting bit sign
		representation = (input[0] == '-' ? "1 " : "0 ");

		//representation loop
		for (s = "", i = sizeof(int2bin(exponent)); i < EXPONENT_LENGTH; s += "0", i++);
		representation += s + int2bin(exponent) + " ";

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


