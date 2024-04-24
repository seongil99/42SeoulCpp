/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:03:55 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/24 18:09:33 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) {
    this->db = ref.db;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref) {
    if (this == &ref) return *this;
    this->db = ref.db;
    return *this;
}

void BitcoinExchange::readFile(std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: file open failed" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string key;
        double value;
        std::istringstream iss(line);
        if (!(iss >> key >> value)) {
            throw BitcoinExchange::BadInputException();
        }
        if (value < 0) {
            throw BitcoinExchange::NegativeNumberException();
        }
        if (value > 1000000) {
            throw BitcoinExchange::LargeNumberException();
        }
        this->db[key] = value;
    }
}

void BitcoinExchange::run(const char *filename) {
    std::string str(filename);
    this->readFile(str);
    this->printResult();
}

void BitcoinExchange::printResult(void) {
    for (std::map<std::string, double>::iterator it = this->db.begin();
         it != this->db.end(); it++) {
        std::cout << it->first << " : " << it->second << std::endl;
    }
}

const char *BitcoinExchange::NegativeNumberException::what() const throw() {
    return "Error: negative number";
}

const char *BitcoinExchange::LargeNumberException::what() const throw() {
    return "Error: large number";
}

const char *BitcoinExchange::BadInputException::what() const throw() {
    return "Error: bad input";
}
