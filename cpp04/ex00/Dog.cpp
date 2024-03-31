/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:25:56 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 15:23:01 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog(void) {
    std::cout << "Dog constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &other) { *this = other; }

Dog::~Dog(void) { std::cout << "Dog destructor called" << std::endl; }

Dog &Dog::operator=(const Dog &other) {
    if (this == &other) return (*this);
    this->type = other.type;
    return (*this);
}

void Dog::makeSound(void) const { std::cout << "Woof Woof" << std::endl; }
