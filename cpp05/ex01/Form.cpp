/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:30:15 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/06 19:08:31 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

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

Form &Form::operator=(const Form &ref) { this->isSigned = ref.isSigned; }

const char *Form::GradeTooHighException::what() const throw() {
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}
