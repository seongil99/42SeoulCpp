/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:33:31 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/26 17:31:05 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"

AMateria::AMateria(void)
{
	std::cout << "AMateria constructor called" << std::endl;
	this->type = "default";
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria constructor called" << std::endl;
	this->type = type;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	this->type = other.type;
	return (*this);
}

std::string const &AMateria::getType(void) const
{
	return (this->type);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << "* use " << this->type << " on " << target.getName() << " *" << std::endl;
}
