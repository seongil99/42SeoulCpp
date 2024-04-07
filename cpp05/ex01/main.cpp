/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:59:57 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/07 12:36:01 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    try {
        Bureaucrat b1("b1", 1);
        std::cout << b1 << std::endl;
        Form f1("f1", 1, 1);
        std::cout << f1 << std::endl;
        b1.signForm(f1);
        std::cout << f1 << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat b2("b2", 150);
        std::cout << b2 << std::endl;
        Form f2("f2", 150, 150);
        std::cout << f2 << std::endl;
        b2.signForm(f2);
        std::cout << f2 << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat b3("b3", 1);
        std::cout << b3 << std::endl;
        Form f3("f3", 150, 150);
        std::cout << f3 << std::endl;
        b3.signForm(f3);
        std::cout << f3 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    try {
        Bureaucrat b4("b4", 150);
        std::cout << b4 << std::endl;
        Form f4("f4", 1, 1);
        std::cout << f4 << std::endl;
        b4.signForm(f4);
        std::cout << f4 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
