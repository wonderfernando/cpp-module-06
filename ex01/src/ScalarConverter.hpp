
#ifndef SCALAR_HPP
# define SCALAR_HPP
#include <iostream>
#include  <cstdlib> 
#include <cctype>
#include <limits>
#include <climits>
#include <iomanip>

class ScalarConverter {
    public:
        static void convert(const std::string& literal);
    
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ~ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter &other);
};

#endif