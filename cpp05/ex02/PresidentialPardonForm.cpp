/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:15:12 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/25 15:38:11 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &ref)
    : AForm(ref), target(ref.target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &ref) {
    (void)ref;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getToExec())
        throw GradeTooLowException();
    if (!this->getIsSigned())
        throw FormNotSignedException();
    std::cout << this->getName() << ": " << this->target
              << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &ref) {
    os << "PresidentialPardonForm: " << ref.getName()
       << ", SignGrade: " << ref.getToSign()
       << ", ExecuteGrade: " << ref.getToExec()
       << ", isSigned: " << ref.getIsSigned();
    return (os);
}
