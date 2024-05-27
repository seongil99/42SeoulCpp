/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:03:55 by seonyoon          #+#    #+#             */
/*   Updated: 2024/05/27 20:25:14 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>

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

bool BitcoinExchange::_checkDate(const std::string &date) const {
    std::string temp = date;
    int year = 0, month = 0, day = 0, cnt = 0;
    for (size_t i = 0; i < temp.size(); i++) {
        if (temp[i] != '-' && !std::isdigit(temp[i]))
            return false;
        if (temp[i] == '-') {
            temp[i] = ' ';
            cnt++;
        }
    }
    if (cnt != 2)
        return false;
    std::istringstream ss(temp);
    ss >> year;
    ss >> month;
    ss >> day;
    if (year < 1)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    return true;
}

double BitcoinExchange::_convertValue(const std::string &value) const {
    char *end = NULL;
    const char *cstr = value.c_str();
    double ret = std::strtod(cstr, &end);
    if (ret < 0)
        throw BitcoinExchange::NegativeNumberException();
    if (ret > 1000)
        throw BitcoinExchange::LargeNumberException();
    if (*end || end == cstr)
        throw BitcoinExchange::BadInputException();
    return ret;
}

bool cmp(const std::pair<const std::string, double> &pair,
         const std::string &value) {
    return pair.first < value;
}

void BitcoinExchange::processInputFile(const char *filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw BitcoinExchange::FileErrorException();

    std::string line;
    while (std::getline(file, line)) {
        try {
            size_t idx = line.find('|');
            std::string date = line.substr(0, idx - 1);
            std::string value = line.substr(idx + 1);
            std::map<std::string, double>::iterator iter;

            if (!_checkDate(date) || idx == std::string::npos)
                throw BitcoinExchange::BadInputException();

            double t = _convertValue(value);

            iter = db.find(date);
            if (iter == db.end()) {
                iter = std::lower_bound(db.begin(), db.end(), date, cmp);
                if (iter == db.begin() || db.begin() == db.end())
                    throw BitcoinExchange::NoDataException();
                iter--;
            }

            std::cout << date << " => " << (*iter).second * t << std::endl;
        } catch (const BitcoinExchange::BadInputException &e) {
            std::cerr << e.what() << " => " << line << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void BitcoinExchange::readDB(void) {
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
    this->readDB();
    this->processInputFile(filename);
}

const char *BitcoinExchange::NegativeNumberException::what() const throw() {
    return "Error: not a positive number";
}

const char *BitcoinExchange::LargeNumberException::what() const throw() {
    return "Error: too large number";
}

const char *BitcoinExchange::BadInputException::what() const throw() {
    return "Error: bad input";
}

const char *BitcoinExchange::FileErrorException::what() const throw() {
    return "Error: could not open file";
}

const char *BitcoinExchange::NoDataException::what() const throw() {
    return "Error: no data exist";
}
