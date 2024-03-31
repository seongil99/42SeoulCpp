/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:46:45 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/30 16:31:15 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource(void) {
    for (int i = 0; i < 4; i++) {
        this->materias[i] = NULL;
    }
}

MateriaSource::~MateriaSource(void) {
    for (int i = 0; i < 4; i++) {
        if (this->materias[i]) {
            delete this->materias[i];
        }
    }
}

MateriaSource::MateriaSource(const MateriaSource &ref) {
    for (int i = 0; i < 4; i++) {
        if (ref.materias[i]) {
            this->materias[i] = ref.materias[i]->clone();
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &ref) {
    if (this == &ref) {
        return (*this);
    }
    for (int i = 0; i < 4; i++) {
        if (this->materias[i]) {
            delete this->materias[i];
        }
        if (ref.materias[i]) {
            this->materias[i] = ref.materias[i]->clone();
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *materia) {
    if (!materia) {
        std::cout << "Invalid materia" << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!this->materias[i]) {
            this->materias[i] = materia;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (this->materias[i] && this->materias[i]->getType() == type) {
            return (this->materias[i]->clone());
        }
    }
    std::cout << "Invalid materia" << std::endl;
    return (NULL);
}
