/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:15:17 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/07 22:25:32 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
    : AForm(ref), target(ref.target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &ref) {
    (void)ref;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getToExec()) throw GradeTooLowException();
    if (!this->getIsSigned()) throw FormNotSignedException();
    if (std::rand() % 2) {
        std::cout << "RobotomyRequestForm: " << this->getName()
                  << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << "RobotomyRequestForm: " << this->getName()
                  << " failed to robotomize" << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &ref) {
    os << "RobotomyRequestForm: " << ref.getName()
       << ", SignGrade: " << ref.getToSign()
       << ", ExecuteGrade: " << ref.getToExec()
       << ", isSigned: " << ref.getIsSigned();
    return (os);
}