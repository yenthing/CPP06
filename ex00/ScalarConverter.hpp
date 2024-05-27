#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>



class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(const std::string &str);
        ScalarConverter(const ScalarConverter &other);
        ~ScalarConverter();

        ScalarConverter &operator=(const ScalarConverter &other);

        void convert();
        void print() const;
        void getStr() const;

    private:
        void toChar();
        void toInt();
        void toFloat();
        void toDouble();

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
};
