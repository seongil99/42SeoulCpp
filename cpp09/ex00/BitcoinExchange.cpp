/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:03:55 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/27 17:04:54 by seonyoon         ###   ########.fr       */
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
    if (this == &ref)
        return *this;
    this->db = ref.db;
    return *this;
}

bool BitcoinExchange::_checkDate(const std::string &date) const {}

void BitcoinExchange::readInputFile(const char *filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw BitcoinExchange::FileErrorException();

    std::string line;
    while (std::getline(file, line)) {
        size_t idx = line.find('|');
        std::string date = line.substr(0, idx);
        std::string value = line.substr(idx + 1);
        std::cout << date << "|" << value << ";" << std::endl;
    }
}

void BitcoinExchange::readCSV(void) {
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw BitcoinExchange::FileErrorException();

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line, ',')) {
        std::istringstream iss(line);
        std::string key;
        iss >> key;

        std::getline(file, line);
        std::istringstream iss2(line);
        double value;
        iss2 >> value;

        db[key] = value;
    }
}

void BitcoinExchange::run(const char *filename) {
    this->readCSV();
    this->readInputFile(filename);
    // this->printResult();
    (void)filename;
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

const char *BitcoinExchange::FileErrorException::what() const throw() {
    return "Error: file error";
}
