/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:48:49 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/17 18:50:03 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon(void) {}

const std::string	&Weapon::getType(void) const
{
	return this->type;
}

void	Weapon::setType(const std::string type)
{
	this->type = type;
}
