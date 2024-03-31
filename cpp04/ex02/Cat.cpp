/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:25:49 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 15:37:58 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat(void) {
    std::cout << "Cat constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
    if (!brain) {
        std::cerr << "Memory allocation failed" << std::endl;
        std::exit(1);
    }
}

Cat::Cat(const Cat &other) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat::~Cat(void) {
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat operator= called" << std::endl;
    if (this == &other) return (*this);
    this->type = other.type;
    this->brain = new Brain(*other.brain);
    return (*this);
}

void Cat::makeSound(void) const { std::cout << "Meow Meow" << std::endl; }

Brain *Cat::getBrain(void) const { return (this->brain); }
