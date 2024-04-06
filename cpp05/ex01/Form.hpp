/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:30:23 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/06 19:03:03 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>

#include "Bureaucrat.hpp"

class Form {
  private:
    const std::string name;
    bool isSigned;
    const unsigned int toSign;
    const unsigned int toExec;

  public:
    Form(void);
    Form(const std::string &name, const unsigned int toSign,
         const unsigned int toExec);
    Form(const Form &ref);
    ~Form(void);

    Form &operator=(const Form &ref);

    class GradeTooHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
