/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:25:49 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/26 00:31:48 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat(void)
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	*this = other;
}

Cat::~Cat(void)
{
	if (this->brain)
		delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	this->type = other.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*other.brain);
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return (this->brain);
}
