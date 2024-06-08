#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>

class ScalarConverter
{
    private:
        std::string _str;
        char _char;
        int _int;
        float _float;
        double _double;
        bool _isInf;
        bool _isNan;
        bool _isChar;
        bool _isInt;
        bool _isFloat;
        bool _isDouble;

    public:
        ScalarConverter();
        ScalarConverter(const std::string &str);
        ScalarConverter(const ScalarConverter &other);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &other);

        void convert();
        void print();
};
