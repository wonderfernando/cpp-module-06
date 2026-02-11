#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
    std::cout << "Default Contruct ScalarConverter" << std::endl;
};

ScalarConverter::ScalarConverter(const ScalarConverter& other){
    std::cout << "Copy Contruct ScalarConverter" << std::endl;
    (void)other;
}

ScalarConverter::~ScalarConverter(){
    std::cout << "Delete Contruct ScalarConverter" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
    if (this == &other)
        return *this;
    return *this;
}

bool isChar ( const std::string& literal){
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return true;
    return false;
}

bool isFloat( const std::string& literal) {
    if (!literal.empty())
        if (literal[literal.length() - 1] == 'f')
            return true;
    return false;
}

void toFloat( const std::string& literal) {
   // std::string literal_without_f = literal.substr(0, literal.length() - 1);

    float literal_value =   std::atof(literal.c_str());

    //char
    if (literal_value >= -128 && literal_value <= 127)
        if (isprint(static_cast<char>(literal_value)))
            std::cout <<"char: '" << static_cast<char>(literal_value) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    else
        std::cout << "char: Impossible" << std::endl;
    
    
    //int
    if (literal_value >= INT_MIN && literal_value <= INT_MAX)
        std::cout <<"int: " << static_cast<int>(literal_value) << std::endl;
    else
        std::cout << "int: Impossible" << std::endl;    
    
    //float
    if (literal_value >= MIN_FLOAT && li)
    std::cout << "float: " << literal_value << "f" << std::endl;
    
    //double
    double db = static_cast<double>(literal_value);
    std::cout << "double: " << db << std::endl;

}

// void toChar(const std::string& literal) {

// }

void ScalarConverter::convert(const std::string& literal)  {
    toFloat(literal);
}