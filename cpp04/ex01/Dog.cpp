/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:25:56 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 15:38:15 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog(void) {
    std::cout << "Dog constructor called" << std::endl;
    type = "Dog";
    brain = new Brain();
    if (!brain) {
        std::cerr << "Memory allocation failed" << std::endl;
        std::exit(1);
    }
}

Dog::Dog(const Dog &other) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog::~Dog(void) {
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog operator= called" << std::endl;
    if (this == &other) return (*this);
    this->type = other.type;
    this->brain = new Brain(*other.brain);
    return (*this);
}

void Dog::makeSound(void) const { std::cout << "Woof Woof" << std::endl; }

Brain *Dog::getBrain(void) const { return (this->brain); }
