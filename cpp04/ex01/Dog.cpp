/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:25:56 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/26 00:31:31 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog(void)
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	*this = other;
}

Dog::~Dog(void)
{
	if (this->brain)
		delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	this->type = other.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*other.brain);
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Woof Woof" << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return (this->brain);
}
