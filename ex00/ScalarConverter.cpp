#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _str(""), _char(0), _int(0), _float(0), _double(0.0), _isInf(false), _isNan(false), _isChar(false), _isInt(false), _isFloat(false), _isDouble(false)
{
}

ScalarConverter::ScalarConverter(const std::string &str) : _str(str), _char(0), _int(0), _float(0), _double(0.0), _isInf(false), _isNan(false), _isChar(false), _isInt(false), _isFloat(false), _isDouble(false)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) : _str(other._str), _char(other._char), _int(other._int), _float(other._float), _double(other._double), _isInf(other._isInf), _isNan(other._isNan), _isChar(other._isChar), _isInt(other._isInt), _isFloat(other._isFloat), _isDouble(other._isDouble)
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
    {
        _str = other._str;
        _char = other._char;
        _int = other._int;
        _float = other._float;
        _double = other._double;
        _isInf = other._isInf;
        _isNan = other._isNan;
        _isChar = other._isChar;
        _isInt = other._isInt;
        _isFloat = other._isFloat;
        _isDouble = other._isDouble;
    }
    return *this;
}

void ScalarConverter::convert()
{
   
    if (_str == "nan" || _str == "nanf")
    {
        _isNan = true;
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (_str == "inf" || _str == "inff" || _str == "+inf" || _str == "+inff")
    {
        _isInf = true;
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return;
    }
    if (_str == "-inf" || _str == "-inff")
    {
        _isInf = true;
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }
    
}

void ScalarConverter::print() const
{
}

   

void ScalarConverter::toChar()
{
    try
    {
        while(_str.length() > 1 && _str[0] == '0')
            _str.erase(0, 1);
        _char = static_cast<char>(std::atoi(_str.c_str()));
        if (_char == '0')
        {
            _char = 0;
            std::cout << "char: Non displayable" << std::endl;
            _isChar = true;
            return;
        }
        else if (!std::isprint(_char) && std::isprint(_str[0]))
            std::cerr << "char: non displayable" << std::endl;
            // throw std::exception();
        _isChar = true;
    }
    catch (std::exception &e)
    {
        std::cerr << "char: non displayable" << std::endl;
        _isChar = false;
    }
}

void ScalarConverter::toInt()
{
    try
    {
        _int = std::atoi(_str.c_str());
        _isInt = true;
    }
    catch (std::exception &e)
    {
        _isInt = false;
    }
}

void ScalarConverter::toFloat()
{
    try
    {
        _float = std::atof(_str.c_str());
        _isFloat = true;
    }
    catch (std::exception &e)
    {
        _isFloat = false;
    }
}

void ScalarConverter::toDouble()
{
    try
    {
        _double = std::atof(_str.c_str());
        _isDouble = true;
    }
    catch (std::exception &e)
    {
        _isDouble = false;
    }
}
