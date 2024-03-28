/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:50:17 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/28 10:24:33 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor called." << std::endl;
	this->name = "default";
	this->hitPoints = 10;
	this->engergyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "String constructor called." << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->engergyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &ref)
{
	*this = ref;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ref)
{
	if (this != &ref)
	{
		this->name = ref.getName();
		this->attackDamage = ref.getAttackDamage();
		this->engergyPoints = ref.getEnergyPoints();
		this->hitPoints = ref.getHitPoints();
	}
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->engergyPoints <= 0)
	{
		_printNoEnergyPoints();
		return;
	}
	if (this->hitPoints <= 0)
	{
		_printNoHitPoints();
		return;
	}
	this->engergyPoints--;
	std::cout << "ClapTrap "
			  << this->name
			  << " attacks "
			  << target
			  << ", causing "
			  << this->attackDamage
			  << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		_printNoHitPoints();
		return;
	}
	this->hitPoints -= amount;
	if (this->hitPoints <= 0)
	{
		this->hitPoints = 0;
	}
	std::cout << "ClapTrap "
			  << this->name
			  << " takes "
			  << amount
			  << " points of damage! "
			  << this->hitPoints
			  << " points left." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->engergyPoints <= 0)
	{
		_printNoEnergyPoints();
		return;
	}
	if (this->hitPoints <= 0)
	{
		_printNoHitPoints();
		return;
	}
	this->hitPoints += amount;
	if (hitPoints >= INT_MAX)
	{
		hitPoints = INT_MAX;
	}
	this->engergyPoints--;
	std::cout << "ClapTrap "
			  << this->name
			  << " is repaired "
			  << amount
			  << " points! "
			  << this->hitPoints
			  << " points left." << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return this->name;
}

int ClapTrap::getHitPoints(void) const
{
	return this->hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return this->engergyPoints;
}

int ClapTrap::getAttackDamage(void) const
{
	return this->attackDamage;
}

void ClapTrap::_printNoEnergyPoints(void) const
{
	std::cout << "ClapTrap "
			  << this->name
			  << " doesn't have energy points." << std::endl;
}

void ClapTrap::_printNoHitPoints(void) const
{
	std::cout << "ClapTrap "
			  << this->name
			  << " doesn't have hit points." << std::endl;
}
