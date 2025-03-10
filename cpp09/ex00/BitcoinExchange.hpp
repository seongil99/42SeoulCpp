/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:03:52 by seonyoon          #+#    #+#             */
/*   Updated: 2024/05/27 20:18:46 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
  private:
    std::map<std::string, double> db;
    bool _checkDate(const std::string &date) const;
    double _convertValue(const std::string &value) const;

  public:
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange &ref);
    ~BitcoinExchange(void);
    BitcoinExchange &operator=(const BitcoinExchange &ref);

    void run(const char *filename);
    void processInputFile(const char *filename);
    void readDB(void);

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

    class FileErrorException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
    class NoDataException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
};

#endif
