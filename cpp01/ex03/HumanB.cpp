/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:48:33 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/19 15:22:03 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB(void) {}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
void	HumanB::attack(void) const
{
	if (!weapon)
	{
		std::cout << name << " does not have weapon" << std::endl;
		return;
	}
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
