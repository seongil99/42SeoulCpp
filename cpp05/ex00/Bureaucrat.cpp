/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:00:04 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/07 13:02:44 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(void) : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade)
    : name(name), grade(grade) {
    if (grade < 1) throw Bureaucrat::GradeTooHighException();
    if (grade > 150) throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref)
    : name(ref.name), grade(ref.grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref) { return (*this); }

const std::string &Bureaucrat::getName(void) const { return (this->name); }

unsigned int Bureaucrat::getGrade(void) const { return (this->grade); }

void Bureaucrat::incrementGrade(unsigned int value) {
    if (value >= this->grade) throw Bureaucrat::GradeTooHighException();
    this->grade -= value;
}

void Bureaucrat::decrementGrade(unsigned int value) {
    if (value >= 150) throw Bureaucrat::GradeTooLowException();
    if (this->grade + value > 150) throw Bureaucrat::GradeTooLowException();
    this->grade += value;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade "
       << bureaucrat.getGrade();
    return (os);
}
