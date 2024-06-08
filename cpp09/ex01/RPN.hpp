/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:10:57 by seonyoon          #+#    #+#             */
/*   Updated: 2024/06/03 16:59:17 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
  private:
    std::stack<int> stack;
    std::string input;
    int result;

    bool _is_digit(std::string &str);

  public:
    RPN(void);
    RPN(const RPN &ref);
    RPN(std::string input);
    ~RPN(void);

    RPN &operator=(const RPN &ref);

    void calculate(void);
    int getResult(void);

    class BadInputException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class DivisionByZeroException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
};

#endif
