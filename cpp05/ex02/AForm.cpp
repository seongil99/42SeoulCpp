/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:30:15 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/06 19:08:31 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

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

AForm &AForm::operator=(const AForm &ref) { this->isSigned = ref.isSigned; }

const char *AForm::GradeTooHighException::what() const throw() {
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}
