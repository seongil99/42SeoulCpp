/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:03:52 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/24 18:09:12 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
   private:
    std::map<std::string, double> db;

   public:
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange &ref);
    ~BitcoinExchange(void);
    BitcoinExchange &operator=(const BitcoinExchange &ref);

    void run(const char *filename);
    void readFile(std::string &filename);
    void printResult(void);

    class NegativeNumberException : public std::exception {
       public:
        virtual const char *what() const throw();
    };

    class LargeNumberException : public std::exception {
       public:
        virtual const char *what() const throw();
    };

    class BadInputException : public std::exception {
       public:
        virtual const char *what() const throw();
    };
};

#endif
