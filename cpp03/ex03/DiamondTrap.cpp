/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:34:53 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 12:26:41 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap(void) {
    std::cout << "DiamondTrap default constructor called." << std::endl;
    ClapTrap::name = "default_clap_name";
    this->name = "default";
    this->hitPoints = FragTrap::getHitPoints();
    this->engergyPoints = ScavTrap::getEnergyPoints();
    this->attackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(std::string name) {
    std::cout << "DiamondTrap string constructor called." << std::endl;
    ClapTrap::name = name + "_clap_name";
    this->name = name;
    this->hitPoints = FragTrap::getHitPoints();
    this->engergyPoints = ScavTrap::getEnergyPoints();
    this->attackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) { *this = ref; }

DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap destructor called." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &ref) {
    if (this != &ref) {
        this->name = ref.getName();
        this->attackDamage = ref.getAttackDamage();
        this->engergyPoints = ref.getEnergyPoints();
        this->hitPoints = ref.getHitPoints();
    }
    return *this;
}

void DiamondTrap::whoAmI(void) {
    std::cout << "I am " << this->name << " and my ClapTrap name is "
              << ClapTrap::getName() << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
    if (this->engergyPoints <= 0) {
        _printNoEnergyPoints();
        return;
    }
    if (this->hitPoints <= 0) {
        _printNoHitPoints();
        return;
    }
    this->engergyPoints--;
    std::cout << "DiamondTrap " << this->name << " attacks " << target
              << ", causing " << this->attackDamage << " points of damage!"
              << std::endl;
}

std::string DiamondTrap::getName(void) const { return this->name; }
