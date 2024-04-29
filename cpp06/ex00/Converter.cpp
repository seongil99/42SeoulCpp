/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:47:51 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/29 19:01:54 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>

Converter::Converter(void) {}

Converter::Converter(const Converter &ref) { *this = ref; }

Converter &Converter::operator=(const Converter &ref) {
    (void)ref;
    return *this;
}

Converter::~Converter(void) {}

void Converter::convert(const std::string &input) {
    double value = 0;
    try {
        char *end = NULL;
        const char *cstr = input.c_str();
        value = std::strtod(cstr, &end);
        if (!end)
            throw std::exception();
        if (cstr == end || !((*end == 'f' && !*(end + 1)) || !*end))
            value = std::numeric_limits<double>::quiet_NaN();
    } catch (std::exception &e) {
        std::cout << "Conversion failed" << std::endl;
        return;
    }

    std::cout << "char: ";
    try {
        if (value < std::numeric_limits<char>::min() ||
            value > std::numeric_limits<char>::max() || std::isnan(value))
            throw std::exception();
        if (std::isprint(static_cast<int>(value)))
            std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    } catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "int: ";
    try {
        if (value < std::numeric_limits<int>::min() ||
            value > std::numeric_limits<int>::max() || std::isnan(value))
            throw std::exception();
        std::cout << static_cast<int>(value) << std::endl;
    } catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "float: ";
    try {
        if (std::isnan(value))
            throw std::exception();
        if (value < -std::numeric_limits<float>::max())
            std::cout << "-inff" << std::endl;
        else if (value > std::numeric_limits<float>::max())
            std::cout << "+inff" << std::endl;
        else {
            std::cout << static_cast<float>(value);
            if (static_cast<int>(value) == value && value / 1000000 < 1.0)
                std::cout << ".0";
            std::cout << "f" << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "nanf" << std::endl;
    }

    std::cout << "double: ";
    try {
        if (std::isnan(value))
            throw std::exception();
        if (value < -std::numeric_limits<double>::max())
            std::cout << "-inf" << std::endl;
        else if (value > std::numeric_limits<double>::max())
            std::cout << "+inf" << std::endl;
        else {
            std::cout << static_cast<double>(value);
            if (static_cast<int>(value) == value && value / 1000000 < 1.0)
                std::cout << ".0";
            std::cout << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "nan" << std::endl;
    }
}
