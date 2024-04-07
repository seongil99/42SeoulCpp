/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:00:00 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/07 12:34:50 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Form;

class Bureaucrat {
   private:
    const std::string name;
    unsigned int grade;

   public:
    Bureaucrat(void);
    Bureaucrat(const std::string &name, unsigned int grade);
    Bureaucrat(const Bureaucrat &ref);
    ~Bureaucrat(void);

    Bureaucrat &operator=(const Bureaucrat &ref);

    const std::string &getName(void) const;
    unsigned int getGrade(void) const;

    void incrementGrade(unsigned int value);
    void decrementGrade(unsigned int value);

    void signForm(Form &form);

    class GradeTooHighException : public std::exception {
       public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
