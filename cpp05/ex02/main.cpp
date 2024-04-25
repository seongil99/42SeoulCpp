/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:59:57 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/25 15:39:31 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
    Bureaucrat b1("b1", 1);
    std::cout << b1 << std::endl;
    Bureaucrat b2("b2", 50);
    std::cout << b2 << std::endl;
    Bureaucrat b3("b3", 140);
    std::cout << b3 << std::endl;
    std::cout << std::endl;

    PresidentialPardonForm f1("target1");
    std::cout << f1 << std::endl;
    RobotomyRequestForm f2("target2");
    std::cout << f2 << std::endl;
    ShrubberyCreationForm f3("target3");
    std::cout << f3 << std::endl;
    std::cout << std::endl;

    try {
        b3.signForm(f1);
        b3.signForm(f2);
        b3.signForm(f3);
    } catch (std::exception &e) {
        std::cout << "cannot sign form" << std::endl;
        std::cout << e.what() << std::endl;
    }
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;
    std::cout << std::endl;

    try {
        b2.executeForm(f1);
        b2.executeForm(f2);
        b2.executeForm(f3);
    } catch (std::exception &e) {
        std::cout << "cannot execute form" << std::endl;
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        b1.signForm(f1);
        b1.signForm(f2);
        b1.signForm(f3);
    } catch (std::exception &e) {
        std::cout << "cannot sign form" << std::endl;
        std::cout << e.what() << std::endl;
    }
    try {
        b1.executeForm(f1);
        b1.executeForm(f2);
        b1.executeForm(f3);
    } catch (std::exception &e) {
        std::cout << "cannot execute form" << std::endl;
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
