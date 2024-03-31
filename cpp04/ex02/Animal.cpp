/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:25:40 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 15:48:07 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal(void) {
    std::cout << "Animal constructor called" << std::endl;
    type = "Animal";
}

Animal::Animal(const Animal &other) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal::~Animal(void) { std::cout << "Animal destructor called" << std::endl; }

Animal &Animal::operator=(const Animal &other) {
    std::cout << "Animal operator= called" << std::endl;
    if (this == &other) return (*this);
    this->type = other.type;
    return (*this);
}

std::string Animal::getType(void) const { return (this->type); }
