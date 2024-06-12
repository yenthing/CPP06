#pragma once

#include <iostream>
#include <climits>
#include <cfloat>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <string>

class ScalarConverter {
public:
    static void convert(const std::string &str);
    
private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);

    static bool isChar(const std::string &str);
    static bool isInt(const std::string &str);
    static bool isFloat(const std::string &str);
    static bool isDouble(const std::string &str);

    static void printChar(char c);
    static void printInt(int i);
    static void printFloat(float f);
    static void printDouble(double d);
};
