/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:11:23 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/24 18:12:40 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <sstream>

RPN::RPN(void) : result(0) {}

RPN::RPN(std::string input) : input(input), result(0) {}

RPN::~RPN(void) {}

RPN &RPN::operator=(const RPN &other) {
    if (this == &other) return *this;
    this->input = other.input;
    this->result = other.result;
    return *this;
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
            stack.pop();
            stack.push(b / a);
        } else {
            stack.push(std::stoi(token));
        }
    }
    result = stack.top();
}

int RPN::getResult(void) { return result; }