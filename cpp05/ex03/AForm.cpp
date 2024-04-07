/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:30:15 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/07 12:39:43 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <iostream>

AForm::AForm(void) : name("default"), toSign(150), toExec(150) {}

AForm::AForm(const std::string &name, const unsigned int toSign,
             const unsigned int toExec)
    : name(name), toSign(toSign), toExec(toExec) {
    isSigned = false;
}

AForm::AForm(const AForm &ref)
    : name(ref.name), toSign(ref.toSign), toExec(ref.toExec) {
    isSigned = false;
}

AForm::~AForm(void) {}

AForm &AForm::operator=(const AForm &ref) {
    (void)ref;
    return (*this);
}

const std::string &AForm::getName(void) const { return (this->name); }

bool AForm::getIsSigned(void) const { return (this->isSigned); }

unsigned int AForm::getToSign(void) const { return (this->toSign); }

unsigned int AForm::getToExec(void) const { return (this->toExec); }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->toSign) {
        throw AForm::GradeTooLowException();
    }
    this->isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << "Form: " << form.getName() << ", Sign grade: " << form.getToSign()
       << ", Exec grade: " << form.getToExec()
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No");
    return (os);
}

const char *AForm::GradeTooHighException::what() const throw() {
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw() {
    return ("Form is not signed");
}
