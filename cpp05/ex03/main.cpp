/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:59:57 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/23 00:08:47 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
    AForm *f1;
    Intern intern;
    Bureaucrat b1("b1", 1);
    std::cout << b1 << std::endl;
    try {
        f1 = intern.makeForm("wrong form", "f1");
        std::cout << *f1 << std::endl;
    } catch (std::exception &e) {
        std::cout << "cannot make form" << std::endl;
        std::cout << e.what() << std::endl;
    }
    try {
        f1 = intern.makeForm("presidential pardon", "f1");
        std::cout << *f1 << std::endl;
    } catch (std::exception &e) {
        std::cout << "cannot make form" << std::endl;
        std::cout << e.what() << std::endl;
    }
    try {
        b1.signForm(*f1);
    } catch (std::exception &e) {
        std::cout << "cannot sign form" << std::endl;
        std::cout << e.what() << std::endl;
    }
    std::cout << *f1 << std::endl;
    try {
        b1.executeForm(*f1);
    } catch (std::exception &e) {
        std::cout << "cannot execute form" << std::endl;
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    delete f1;
    return 0;
}
