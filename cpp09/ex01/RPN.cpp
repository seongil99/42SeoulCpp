/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:11:23 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/26 16:20:16 by seonyoon         ###   ########.fr       */
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
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(b + a);
        } else if (token == "-") {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(b - a);
        } else if (token == "*") {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(b * a);
        } else if (token == "/") {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            if (a == 0)
                throw RPN::DivisionByZero();
            stack.pop();
            stack.push(b / a);
        } else if (_is_digit(token)) {
            stack.push(std::atoi(token.c_str()));
        } else {
            throw RPN::BadInputError();
        }
    }
    result = stack.top();
}

int RPN::getResult(void) { return result; }

const char *RPN::BadInputError::what() const throw() { return "Error"; }

const char *RPN::DivisionByZero::what() const throw() {
    return "Division by zero";
}
