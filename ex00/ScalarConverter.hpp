#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter& operator=(const ScalarConverter& rhs);
        ~ScalarConverter();
		
		struct ConvertedData {
			char c;
			int i;
			float f;
			double d;
			bool isImpossibleOverall;
			bool isCharImpossible;
			bool isCharNonDisplayable;
			bool isIntImpossible;
		};
		static void printResult(const ConvertedData& data);

    public:
        static void convert(const std::string& literal);
};

#endif
