/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 22:33:30 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/27 20:02:56 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &ref) { *this = ref; }

Intern::~Intern(void) {}

Intern &Intern::operator=(const Intern &ref) {
    (void)ref;
    return (*this);
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) {
    AForm *ret = NULL;
    const std::string formNames[3] = {"presidential pardon", "robotomy request",
                                      "shrubbery creation"};

    AForm *forms[3] = {new PresidentialPardonForm(target),
                       new RobotomyRequestForm(target),
                       new ShrubberyCreationForm(target)};

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << " form" << std::endl;
            ret = forms[i];
        } else
            delete forms[i];
    }
    if (!ret)
        throw Intern::FormNotFoundException();
    return (ret);
}

const char *Intern::FormNotFoundException::what() const throw() {
    return ("Intern couldn't create form. Form not found");
}
