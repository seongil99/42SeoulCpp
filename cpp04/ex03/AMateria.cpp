/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:33:31 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/30 16:07:15 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <iostream>

#include "Character.hpp"

AMateria::AMateria(void) {}

AMateria::AMateria(const AMateria &ref) : type(ref.type) {}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::~AMateria(void) {}

std::string const &AMateria::getType(void) const { return (this->type); }

void AMateria::use(ICharacter &target) {
    std::cout << "* use " << this->type << " on " << target.getName() << " *"
              << std::endl;
}
