/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:24:16 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/30 16:29:59 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include <iostream>

Character::Character(void) {
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
    }
}

Character::Character(const Character &ref) : name(ref.name) {
    for (int i = 0; i < 4; i++) {
        if (ref.inventory[i]) {
            this->inventory[i] = ref.inventory[i]->clone();
        }
    }
}

Character::Character(std::string const &name) : name(name) {
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
    }
}

Character::~Character(void) {
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i]) {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
    }
}

Character &Character::operator=(const Character &ref) {
    if (this == &ref) {
        return (*this);
    }
    this->name = ref.name;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i]) {
            delete this->inventory[i];
        }
        if (ref.inventory[i]) {
            this->inventory[i] = ref.inventory[i]->clone();
        }
    }
    return (*this);
}

std::string const &Character::getName() const { return (this->name); }

void Character::equip(AMateria *m) {
    if (!m) {
        std::cout << "Invalid materia" << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!this->inventory[i]) {
            this->inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || !this->inventory[idx]) {
        return;
    }
    this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    if (!this->inventory[idx]) {
        std::cout << "Empty slot" << std::endl;
        return;
    }
    this->inventory[idx]->use(target);
}
