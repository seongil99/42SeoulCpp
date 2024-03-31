/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:25:40 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 15:22:42 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal(void) {
    std::cout << "Animal constructor called" << std::endl;
    type = "Animal";
}

Animal::Animal(const Animal &other) { *this = other; }

Animal::~Animal(void) { std::cout << "Animal destructor called" << std::endl; }

Animal &Animal::operator=(const Animal &other) {
    if (this == &other) return (*this);
    this->type = other.type;
    return (*this);
}

std::string Animal::getType(void) const { return (this->type); }

void Animal::makeSound(void) const { std::cout << "Animal sound" << std::endl; }