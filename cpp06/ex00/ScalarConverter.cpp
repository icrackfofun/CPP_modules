/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:38:56 by psantos-          #+#    #+#             */
/*   Updated: 2026/01/10 23:39:43 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {(void)other; return *this;}

//*end - no invalid chars, errno - too large
static bool isInt(const std::string &s) {
    char *end;
    errno = 0;
    strtol(s.c_str(), &end, 10);
    return (*end == '\0' && errno != ERANGE);
}

//handle inf / undefined math, same as last 
static bool isDouble(const std::string &s) {
    if (s == "+inf" || s == "-inf" || s == "nan")
        return true;
    char *end;
    errno = 0;
    strtod(s.c_str(), &end);
    return (*end == '\0' && errno != ERANGE);
}

//same as before, check if last == 'f'
static bool isFloat(const std::string &s) {
    if (s == "+inff" || s == "-inff" || s == "nanf")
        return true;
    if (s[s.length() - 1] != 'f')
        return false;
    std::string sub = s.substr(0, s.length() - 1);
    char *end;
    errno = 0;
    strtof(sub.c_str(), &end);
    return (*end == '\0' && errno != ERANGE);
}

// write char in console with " + ' + char + ' + ", else is won't be recognized
static bool isChar(const std::string &s) {
    return (s.length() == 3 && s[0] == '\'' && s[s.length() - 1] == '\'');
}

//handle conversion from all types
static void printChar(double d) {
    std::cout << "char: ";
    if (std::isnan(d) || d < 0 || d > 255)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(d) << "'\n";
}

//handle conversion from all types
static void printInt(double d) {
    std::cout << "int: ";
    if (std::isnan(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(d) << "\n";
}

//cast down to float, handle cases
static void printFloat(double d) {
    std::cout << "float: ";
    float f = static_cast<float>(d);

    if (std::isnan(f))
        std::cout << "nanf\n";
    else if (std::isinf(f))
        std::cout << (f > 0 ? "+inff\n" : "-inff\n");
    else {
        std::cout << f;
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f\n";
    }
}

//no downcast required
static void printDouble(double d) {
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan\n";
    else if (std::isinf(d))
        std::cout << (d > 0 ? "+inf\n" : "-inf\n");
    else {
        std::cout << d;
        if (d == static_cast<int>(d))
            std::cout << ".0";
        std::cout << "\n";
    }
}

void ScalarConverter::convert(const std::string &literal) {
    double value = 0.0;

    if (isChar(literal)) {
        value = static_cast<double>(literal[1]);
    }
    else if (isInt(literal)) {
        value = static_cast<double>(std::strtol(literal.c_str(), NULL, 10));
    }
    else if (isFloat(literal)) {
        value = static_cast<double>(std::strtof(literal.c_str(), NULL));
    }
    else if (isDouble(literal)) {
        value = std::strtod(literal.c_str(), NULL);
    }
    else {
        std::cout << "Invalid literal\n";
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
