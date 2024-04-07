/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:30:15 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/07 12:54:54 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <iostream>

Form::Form(void) : name("default"), toSign(150), toExec(150) {}

Form::Form(const std::string &name, const unsigned int toSign,
           const unsigned int toExec)
    : name(name), toSign(toSign), toExec(toExec) {
    isSigned = false;
}

Form::Form(const Form &ref)
    : name(ref.name), toSign(ref.toSign), toExec(ref.toExec) {
    isSigned = false;
}

Form::~Form(void) {}

Form &Form::operator=(const Form &ref) { return (*this); }

const std::string &Form::getName(void) const { return (this->name); }

bool Form::getIsSigned(void) const { return (this->isSigned); }

unsigned int Form::getToSign(void) const { return (this->toSign); }

unsigned int Form::getToExec(void) const { return (this->toExec); }

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->toSign) {
        throw Form::GradeTooLowException();
    }
    this->isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form: " << form.getName() << ", Sign grade: " << form.getToSign()
       << ", Exec grade: " << form.getToExec()
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No");
    return (os);
}

const char *Form::GradeTooHighException::what() const throw() {
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}
