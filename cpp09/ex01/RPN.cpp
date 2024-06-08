/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:11:23 by seonyoon          #+#    #+#             */
/*   Updated: 2024/06/03 17:01:44 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <cstdlib>
#include <sstream>

RPN::RPN(void) : result(0) {}

RPN::RPN(std::string input) : input(input), result(0) {}

RPN::RPN(const RPN &ref) : input(ref.input), result(ref.result) {}

RPN::~RPN(void) {}

RPN &RPN::operator=(const RPN &ref) {
    if (this == &ref)
        return *this;
    this->input = ref.input;
    this->result = ref.result;
    return *this;
}

bool RPN::_is_digit(std::string &str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void RPN::calculate(void) {
    std::string token;
    std::istringstream iss(input);
    while (iss >> token) {
        if (token == "+") {
            if (stack.size() < 2)
                throw RPN::BadInputException();
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(b + a);
        } else if (token == "-") {
            if (stack.size() < 2)
                throw RPN::BadInputException();
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(b - a);
        } else if (token == "*") {
            if (stack.size() < 2)
                throw RPN::BadInputException();
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(b * a);
        } else if (token == "/") {
            if (stack.size() < 2)
                throw RPN::BadInputException();
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            if (a == 0)
                throw RPN::DivisionByZeroException();
            stack.pop();
            stack.push(b / a);
        } else if (_is_digit(token)) {
            stack.push(std::atoi(token.c_str()));
        } else {
            throw RPN::BadInputException();
        }
    }
    if (stack.size() != 1)
        throw RPN::BadInputException();
    result = stack.top();
}

int RPN::getResult(void) { return result; }

const char *RPN::BadInputException::what() const throw() { return "Bad input"; }

const char *RPN::DivisionByZeroException::what() const throw() {
    return "Division by zero";
}
