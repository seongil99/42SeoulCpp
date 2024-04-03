/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:59:57 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/03 23:23:45 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat b1("b1", 0);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("b2", 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("b3", 1);
        std::cout << b3 << std::endl;
        b3.incrementGrade(INT_MAX);
        std::cout << b3 << std::endl;
        b3.decrementGrade(INT_MAX);
        std::cout << b3 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("b4", 150);
        std::cout << b4 << std::endl;
        b4.decrementGrade(INT_MAX);
        std::cout << b4 << std::endl;
        b4.incrementGrade(INT_MAX);
        std::cout << b4 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
