#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &str)
{
    if (isChar(str))
    {
        char c = str[0];
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
    }
    else if (isInt(str))
    {
        long l = std::strtol(str.c_str(), NULL, 10);
        if (l < INT_MIN || l > INT_MAX) {
            std::cerr << "int: impossible" << std::endl;
        }
        else
        {
            int i = static_cast<int>(l);
            printChar(static_cast<char>(i));
            printInt(i);
            printFloat(static_cast<float>(i));
            printDouble(static_cast<double>(i));
        }
    }
    else if (isFloat(str))
    {
        float f = std::strtof(str.c_str(), NULL);
        if ((f == HUGE_VALF || f == -HUGE_VALF) && errno == ERANGE)
            std::cerr << "float: impossible" << std::endl;
        else
        {
            if (std::isnan(f) || std::isinf(f))
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
            }
            else
            {
                printChar(static_cast<char>(f));
                printInt(static_cast<int>(f));
            }
            printFloat(f);
            printDouble(static_cast<double>(f));
        }
    }
    else if (isDouble(str))
    {
        double d = std::strtod(str.c_str(), NULL);
        if ((d == HUGE_VAL || d == -HUGE_VAL) && errno == ERANGE)
            std::cerr << "double: impossible" << std::endl;
        else
        {
            if (std::isnan(d) || std::isinf(d))
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
            }
            else
            {
                printChar(static_cast<char>(d));
                printInt(static_cast<int>(d));
            }
            printFloat(static_cast<float>(d));
            printDouble(d);
        }
    }
    else
        std::cerr << "Error: str format is not recognized" << std::endl;
}

bool ScalarConverter::isChar(const std::string &str) 
{
    return str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]);
}

bool ScalarConverter::isInt(const std::string &str)
{
    char *endptr;
    errno = 0;
    long val = std::strtol(str.c_str(), &endptr, 10);
    return *endptr == '\0' && errno != ERANGE && val <= INT_MAX && val >= INT_MIN;
}

bool ScalarConverter::isFloat(const std::string &str)
{
    char *endptr;
    errno = 0;
    std::strtof(str.c_str(), &endptr);
    return *endptr == 'f' && endptr[1] == '\0' && errno != ERANGE;
}

bool ScalarConverter::isDouble(const std::string &str)
{
    char *endptr;
    errno = 0;
    std::strtod(str.c_str(), &endptr);
    return *endptr == '\0' && errno != ERANGE;
}

void ScalarConverter::printChar(char c)
{
    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(int i)
{
    std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f)
{
    std::cout << std::fixed << std::setprecision(1) << "float: " << f << 'f' << std::endl;
}

void ScalarConverter::printDouble(double d)
{
    std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}
