/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:15:25 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/25 15:38:34 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref)
    : AForm(ref), target(ref.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref) {
    (void)ref;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getToExec())
        throw GradeTooLowException();
    if (!this->getIsSigned())
        throw FormNotSignedException();
    std::string suffix = "_shrubbery";
    std::string filename = this->target + suffix;
    std::ofstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return;
    }
    file << asciiTrees;
    file.close();
    std::cout << this->getName() << ": "
              << " created a file: " << this->target << "_shrubbery"
              << std::endl;
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &ref) {
    os << "ShrubberyCreationForm: " << ref.getName()
       << ", SignGrade: " << ref.getToSign()
       << ", ExecuteGrade: " << ref.getToExec()
       << ", isSigned: " << ref.getIsSigned();
    return (os);
}
