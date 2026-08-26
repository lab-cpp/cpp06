#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath> 
#include <limits> 

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) { (void)rhs; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::printResult(const ConvertedData& data) {
	if (data.isImpossibleOverall) {
		std::cout << "char: impossible" 
				<< "\nint: impossible"
				<< "\nfloat: impossible"
				<< "\ndouble: impossible" << std::endl;
		
		return ;
	}

	if (data.isCharImpossible)
		std::cout << "char: impossible\n";
	else if (data.isCharNonDisplayable)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << data.c << "'\n";

	if (data.isIntImpossible)
		std::cout << "int: impossible\n";
	else  
		std::cout << "int: " << data.i << "\n";

	if (data.f - static_cast<int>(data.f) == 0.0f && !data.isIntImpossible)
		std::cout << "float: " << data.f << ".0f\n";
	else 
		std::cout << "float: " << data.f << "f\n";

	if (data.d - static_cast<int>(data.d) == 0.0 && !data.isIntImpossible)
		std::cout << "double: " << data.d << ".0\n";
	else
		std::cout << "double: " << data.d << "\n";
}

void ScalarConverter::convert(const std::string& literal) {
	ConvertedData data = {0, 0, 0.0f, 0.0, false, false, false, false};

	if (literal == "nan" || literal == "nanf" || literal == "+inf" ||
		literal == "+inff" || literal == "-inf" || literal == "-inff") {
			data.isCharImpossible = true;
			data.isIntImpossible = true;
			data.d = std::strtod(literal.c_str(), NULL);
			data.f = static_cast<float>(data.d);
			printResult(data);
			return ;
		}
	
	if (literal.length() == 1 && !std::isdigit(literal[0])) {
		data.c = literal[0];
		data.i = static_cast<int>(data.c);
		data.f = static_cast<float>(data.c);
		data.d = static_cast<double>(data.c);
		
		if (!std::isprint(data.c))
			data.isCharNonDisplayable = true;

		printResult(data);
		return ;
	}

	char* endptr;
	double value = std::strtod(literal.c_str(), &endptr);
	
	if (literal.c_str() == endptr) {
		data.isImpossibleOverall = true;
		printResult(data);
		return ;
	}

	if (*endptr != '\0' && !(*endptr == 'f' && *(endptr + 1) == '\0')) {
		data.isImpossibleOverall = true;
		printResult(data);
		return ;
	}

	data.d = value;
	data.f = static_cast<float>(value);

	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || value != value) {
		data.isIntImpossible = true;
	} else {
		data.i = static_cast<int>(value);
	}

	if (value < 0 || value > 127 || value != value) {
		data.isCharImpossible = true;
	} else {
		data.c = static_cast<char>(value);
		if (!std::isprint(data.c))
			data.isCharNonDisplayable = true;
	}

	printResult(data);
}
