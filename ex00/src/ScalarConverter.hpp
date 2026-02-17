
#ifndef SCALAR_HPP
# define SCALAR_HPP
#include <iostream>
#include  <cstdlib> 
#include <cctype>
#include <limits>
#include <climits>
#include <iomanip>
# define MIN_FLOAT std::numeric_limits<float>::min() //-3.40282e+38
# define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
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