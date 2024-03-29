/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:11:27 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 12:11:43 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap(void) {
    std::cout << "ScavTrap default constructor called." << std::endl;
    this->name = "default";
    this->hitPoints = 100;
    this->engergyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) {
    std::cout << "ScavTrap string constructor called." << std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->engergyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &ref) { *this = ref; }

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ref) {
    if (this != &ref) {
        this->name = ref.getName();
        this->attackDamage = ref.getAttackDamage();
        this->engergyPoints = ref.getEnergyPoints();
        this->hitPoints = ref.getHitPoints();
    }
    return *this;
}

void ScavTrap::attack(const std::string &target) {
    if (this->engergyPoints <= 0) {
        _printNoEnergyPoints();
        return;
    }
    if (this->hitPoints <= 0) {
        _printNoHitPoints();
        return;
    }
    this->engergyPoints--;
    std::cout << "ScavTrap " << this->name << " attacks " << target
              << ", causing " << this->attackDamage << " points of damage!"
              << std::endl;
}

void ScavTrap::guardGate(void) const {
    if (this->engergyPoints <= 0) {
        _printNoEnergyPoints();
        return;
    }
    if (this->hitPoints <= 0) {
        _printNoHitPoints();
        return;
    }
    std::cout << "ScavTrap " << this->name
              << " has entered in Gate keeper mode." << std::endl;
}
