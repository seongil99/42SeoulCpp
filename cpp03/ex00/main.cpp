/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:50:09 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/28 16:58:23 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap clapTrap1("CT1");
    ClapTrap clapTrap2("CT2");

    std::cout << std::endl;
    std::cout << "==Test energy points==" << std::endl;
    clapTrap1.attack("CT2");
    clapTrap1.attack("CT2");
    clapTrap1.attack("CT2");
    clapTrap1.attack("CT2");
    clapTrap1.attack("CT2");
    clapTrap1.attack("CT2");
    clapTrap1.attack("CT2");
    clapTrap1.attack("CT2");
    clapTrap1.attack("CT2");
    clapTrap1.attack("CT2");
    clapTrap1.attack("CT2");
    clapTrap1.beRepaired(10);
    std::cout << std::endl;

    std::cout << "==Test hit points==" << std::endl;
    clapTrap2.takeDamage(5);
    clapTrap2.beRepaired(3);
    clapTrap2.takeDamage(100);
    clapTrap2.takeDamage(5);
    clapTrap2.beRepaired(10);
    clapTrap2.takeDamage(5);
    clapTrap2.attack("CT1");
    std::cout << std::endl;

    return 0;
}
