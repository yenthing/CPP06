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
    if (_str.length() == 1 && !std::isdigit(_str[0]))
    {
        _char = _str[0];
        _isChar = true;
        _isInt = true;
        _isFloat = true;
        _isDouble = true;
    }
    else
    {
        char *end;
        try
        {
            if (_str.back() == 'f')
            {
                std::string tempStr = _str.substr(0, _str.size() - 1);
                size_t dotPos = tempStr.find('.');
                if (dotPos != std::string::npos && dotPos < tempStr.size() - 1 && std::all_of(tempStr.begin() + dotPos + 1, tempStr.end(), ::isdigit))
                {
                    _char = '*';
                    _isChar = true;
                    _isInt = true;
                    _isFloat = true;
                    _isDouble = true;
                }
            }
            else
            {
                _char = _str[0];
                _int = std::stoi(_str);
                _isInt = true;
                _isFloat = true;
                _isDouble = true;
            }
           
        }
        catch (const std::exception &e)
        {
            _isInt = false;
        }
        try
        {
            _float = std::strtof(_str.c_str(), &end);
            if (*end == 'f')
                end++;
            if (end != _str && *end == '\0')
            {
                if (_float == std::numeric_limits<float>::infinity() || _float == -std::numeric_limits<float>::infinity())
                    _isInf = true;
                if (std::isnan(_float))
                    _isNan = true;
                if (_float == std::numeric_limits<float>::infinity() || _float == -std::numeric_limits<float>::infinity())
                    _isInf = true;
                if (std::isnan(_float))
                    _isNan = true;
            }
            else
            {
                _isFloat = false;
                _double = false;
            }
            
        }
        catch (const std::exception &e)
        {
            _isFloat = false;
        }
        try
        {
            _double = std::strtod(_str.c_str(), &end);
            if (*end == 'f')
                end++;
            if (end != _str && *end == '\0')
            {
                if (_double == std::numeric_limits<double>::infinity() || _double == -std::numeric_limits<double>::infinity())
                    _isInf = true;
                if (std::isnan(_double))
                    _isNan = true;
            }
            else
                _isDouble = false;
        }
        catch (const std::exception &e)
        {
            _isDouble = false;
        }
    }
    if (_str == "nan" || _str == "+inf" || _str == "-inf" || _str == "-inff" || _str == "+inff")
    {
        _isInf = true;
        _isNan = true;
    }
}

void ScalarConverter::print()
{
    std::cout << "char: ";
    if (_isChar)
    {
        if (_char == '*' || std::isalpha(_char))
            std::cout << "'" << _char << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else if (std::isdigit(_char) && !_isChar)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "int: ";
    if (_isInt)
        std::cout << _int << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "float: ";
    if (_isFloat)
        std::cout << std::fixed << std::setprecision(1) << _float << "f" << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "double: ";
    if (_isDouble)
        std::cout << _double << "" << std::endl;
    else
        std::cout << "impossible" << std::endl;
}
