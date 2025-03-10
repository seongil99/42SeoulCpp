/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:30:23 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/06 22:22:01 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <string>

#include "Bureaucrat.hpp"

class AForm {
   private:
    const std::string name;
    bool isSigned;
    const unsigned int toSign;
    const unsigned int toExec;

   public:
    AForm(void);
    AForm(const std::string &name, const unsigned int toSign,
          const unsigned int toExec);
    AForm(const AForm &ref);
    virtual ~AForm(void);

    AForm &operator=(const AForm &ref);

    const std::string &getName(void) const;
    bool getIsSigned(void) const;
    unsigned int getToSign(void) const;
    unsigned int getToExec(void) const;

    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException : public std::exception {
       public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        virtual const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
       public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif
