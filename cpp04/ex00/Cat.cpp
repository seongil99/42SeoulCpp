/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:25:49 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 15:22:54 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat(void) {
    std::cout << "Cat constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat &other) { *this = other; }

Cat::~Cat(void) { std::cout << "Cat destructor called" << std::endl; }

Cat &Cat::operator=(const Cat &other) {
    if (this == &other) return (*this);
    this->type = other.type;
    return (*this);
}

void Cat::makeSound(void) const { std::cout << "Meow Meow" << std::endl; }
