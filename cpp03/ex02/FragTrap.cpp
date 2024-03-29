/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:16:05 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 11:25:20 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap(void) {
    std::cout << "FragTrap default constructor called." << std::endl;
    this->name = "default";
    this->hitPoints = 100;
    this->engergyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) {
    std::cout << "FragTrap string constructor called." << std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->engergyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &ref) { *this = ref; }

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &ref) {
    if (this != &ref) {
        this->name = ref.getName();
        this->attackDamage = ref.getAttackDamage();
        this->engergyPoints = ref.getEnergyPoints();
        this->hitPoints = ref.getHitPoints();
    }
    return *this;
}

void FragTrap::highFivesGuys(void) {
    if (this->engergyPoints <= 0) {
        _printNoEnergyPoints();
        return;
    }
    if (this->hitPoints <= 0) {
        _printNoHitPoints();
        return;
    }
    std::cout << "FragTrap " << this->name << " requests a high five!"
              << std::endl;
}