/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:50:09 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 12:24:25 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    ClapTrap clapTrap1("CT1");
    FragTrap fragTrap1("FT1");
    ScavTrap scavTrap1("ST1");
    DiamondTrap diamondTrap1("DT1");
    std::cout << std::endl;

    diamondTrap1.whoAmI();
    std::cout << diamondTrap1.getName() << " has "
              << diamondTrap1.ClapTrap::getName() << " as ClapTrap name, "
              << diamondTrap1.getHitPoints() << " hit points, "
              << diamondTrap1.getEnergyPoints() << " energy points, and "
              << diamondTrap1.getAttackDamage() << " attack damage."
              << std::endl;
    std::cout << std::endl;

    diamondTrap1.attack("FT1");
    fragTrap1.takeDamage(diamondTrap1.getAttackDamage());
    std::cout << std::endl;

    diamondTrap1.attack("CT1");
    clapTrap1.takeDamage(diamondTrap1.getAttackDamage());
    std::cout << std::endl;

    scavTrap1.attack("DT1");
    diamondTrap1.takeDamage(scavTrap1.getAttackDamage());
    std::cout << std::endl;

    diamondTrap1.guardGate();
    std::cout << std::endl;

    diamondTrap1.highFivesGuys();
    std::cout << std::endl;

    diamondTrap1.beRepaired(10);
    std::cout << std::endl;

    return 0;
}
