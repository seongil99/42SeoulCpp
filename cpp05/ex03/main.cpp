/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:59:57 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/27 19:44:27 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
    AForm *f1 = NULL;
    Intern intern;
    Bureaucrat b1("b1", 1);
    std::cout << b1 << std::endl;
    std::cout << std::endl;

    try {
        f1 = intern.makeForm("wrong form", "target1");
        std::cout << *f1 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        f1 = intern.makeForm("presidential pardon", "target1");
        std::cout << *f1 << std::endl;
        std::cout << std::endl;

        b1.signForm(*f1);
        std::cout << *f1 << std::endl;
        std::cout << std::endl;

        b1.executeForm(*f1);
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    delete f1;
    return 0;
}
