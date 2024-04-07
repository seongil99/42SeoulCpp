/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:30:23 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/06 22:22:01 by seonyoon         ###   ########.fr       */
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

    const std::string &getName(void) const;
    bool getIsSigned(void) const;
    unsigned int getToSign(void) const;
    unsigned int getToExec(void) const;

    void beSigned(const Bureaucrat &bureaucrat);

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
