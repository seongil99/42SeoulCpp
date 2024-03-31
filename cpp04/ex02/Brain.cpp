/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:16:49 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 15:37:39 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

Brain::Brain(void) { std::cout << "Brain constructor called" << std::endl; }

Brain::Brain(const Brain &ref) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = ref;
}

Brain::~Brain(void) { std::cout << "Brain destructor called" << std::endl; }

Brain &Brain::operator=(const Brain &ref) {
    std::cout << "Brain operator= called" << std::endl;
    if (this == &ref) return (*this);
    for (int i = 0; i < 100; i++) this->ideas[i] = ref.ideas[i];
    return (*this);
}

std::string Brain::getIdea(int idx) const {
    if (idx < 0 || idx >= 100) return ("");
    return (this->ideas[idx]);
}

void Brain::setIdea(int idx, std::string idea) {
    if (idx < 0 || idx >= 100) return;
    this->ideas[idx] = idea;
}
