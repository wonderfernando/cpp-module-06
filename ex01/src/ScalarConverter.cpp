#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default Contruct ScalarConverter" << std::endl;
};

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    std::cout << "Copy Contruct ScalarConverter" << std::endl;
    (void)other;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Delete Contruct ScalarConverter" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this == &other)
        return *this;
    return *this;
}

bool isChar(const std::string &literal)
{
    if (literal.length() == 1 && !isdigit(literal[0]))
        return true;
    return false;
}
bool isInt(const std::string &literal)
{
    const size_t foundMinus = literal.find('-');
    if (foundMinus != std::string::npos && foundMinus != 0)
        return (false);

    if (literal.find_first_not_of("0123456789", foundMinus == std::string::npos ? 0 : 1) != std::string::npos)
        return (false);
    return (true);
}
void convertToChar(double c)
{
    char real_value = static_cast<char>(c);
    if (static_cast<int>(c) < std::numeric_limits<char>::min() || static_cast<int>(c) > std::numeric_limits<char>::max())
        std::cout << "char: overflow char value" << std::endl;
    else if (!isprint(real_value))
        std::cout << "char: is not printble" << std::endl;
    else
        std::cout << "char: '" << real_value << "'" << std::endl;
}

void isCharConverter(const std::string &literal)
{
    char c = literal[0];
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

bool isInfinite(const std::string &literal)
{
    if (literal == "-inff" || literal == "+inff" ||
        literal == "nanf" || literal == "-inf" ||
        literal == "+inf" || literal == "nan" 
    ) 
        return true;
    return false;
}

void invalid()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void infiniteNaNValues(const std::string &literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (literal.find("nan") != std::string::npos)
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else
    {
        std::cout << "float: " << literal[0] << "inff" << std::endl;
        std::cout << "double: " << literal[0] << "inf" << std::endl;
    }
}

bool isFloat(const std::string &literal)
{
    if (literal.find('+') != std::string::npos)
        return false;

    size_t foundMinus = literal.find("-");
    if (foundMinus != std::string::npos && foundMinus != 0)
        return false;

    size_t foundDot = literal.find(".");
    if (foundDot == std::string::npos)
        return false;

    if (foundDot != std::string::npos && (literal.length() == 1 || literal.length() == 2))
        return false;

    size_t firstF = literal.find("f");
    if (firstF == std::string::npos)
        return false;
    if (firstF != literal.length() - 1)
        return false;

    size_t index = foundMinus != std::string::npos ? 1 : 0; // inicio da string caso tenha sinal comeca no 1
    std::string leftDotNumber = literal.substr(index, foundDot - index);
    std::string rightDotNumber = literal.substr(foundDot + 1, firstF - foundDot - 1);

    if (leftDotNumber.find_first_not_of("0123456789") != std::string::npos ||
        rightDotNumber.find_first_not_of("0123456789f") != std::string::npos)
        return false;

    if (leftDotNumber.empty() || rightDotNumber.empty())
        return false;

    return true;
}

bool isDouble(const std::string &literal)
{
    if (literal.find('+') != std::string::npos)
        return false;

    size_t foundMinus = literal.find("-");
    if (foundMinus != std::string::npos && foundMinus != 0)
        return false;

    size_t foundDot = literal.find(".");
    if (foundDot == std::string::npos)
        return false;

    if (foundDot != std::string::npos && (literal.length() == 1 || literal.length() == 2))
        return false;

    size_t init = foundMinus != std::string::npos ? 1 : 0; // inicio da string caso tenha sinal comeca no 1
    std::string leftDotNumber = literal.substr(init, foundDot - init);
    std::string rightDotNumber = literal.substr(foundDot + 1);

    if (leftDotNumber.find_first_not_of("0123456789") != std::string::npos ||
        rightDotNumber.find_first_not_of("0123456789") != std::string::npos)
        return false;
    if (leftDotNumber.empty() || rightDotNumber.empty())
        return false;

    return true;
}
void convertInt(long double number)
{
    convertToChar(number);
    if (number < std::numeric_limits<int>::min() ||
        number > std::numeric_limits<int>::max())
        std::cout << "int: overflow integer value" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(number) << std::endl;

    if (number < -std::numeric_limits<float>::max() ||
        number > std::numeric_limits<float>::max())
        std::cout << "float: overflow float value" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(number) << ".0f"
                  << std::endl;

    if (number < -std::numeric_limits<double>::max() ||
        number > std::numeric_limits<double>::max())
        std::cout << "double: overflow double value" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << "double: " << (number) << std::endl;
}

void convertToNumber(long double number)
{
    convertToChar(number);
    if (number < std::numeric_limits<int>::min() ||
        number > std::numeric_limits<int>::max())
        std::cout << "int: overflow integer value" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(number) << std::endl;

    if (number < -std::numeric_limits<float>::max() ||
        number > std::numeric_limits<float>::max())
        std::cout << "float: overflow float value" << std::endl;
    else
    {
        if (static_cast<int>(number) == static_cast<float>(number))
            std::cout << "float: " << static_cast<float>(number) << ".0f"
                      << std::endl;
        else
            std::cout << "float: " << static_cast<float>(number) << "f"
                      << std::endl;
    }

    if (number < -std::numeric_limits<double>::max() ||
        number > std::numeric_limits<double>::max())
        std::cout << "double: overflow double value" << std::endl;
    else
    {
         if (static_cast<int>(number) == static_cast<double>(number))
            std::cout << "double: " << static_cast<double>(number) << ".0" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(number) << std::endl ;
    }
}

void ScalarConverter::convert(const std::string &literal)
{
    if (isInfinite(literal))
        infiniteNaNValues(literal);
    else if (isChar(literal))
        isCharConverter(literal);
    else if (isInt(literal))
        convertInt(std::atof(literal.c_str()));
    else if (isFloat(literal))
        convertToNumber(std::atof(literal.c_str()));
    else if (isDouble(literal))
        convertToNumber(std::atof(literal.c_str()));
    else
        invalid();
}