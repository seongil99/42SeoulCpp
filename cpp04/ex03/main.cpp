/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:29:50 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/30 16:37:36 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main(void) {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    std::cout << "learnMateria(NULL): ";
    src->learnMateria(NULL);
    std::cout << std::endl;

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << "createMateria(wrong type): ";
    tmp = src->createMateria("wrong type");
    std::cout << std::endl;
    std::cout << "me.equip(NULL): ";
    me->equip(tmp);
    std::cout << std::endl;

    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << std::endl;

    std::cout << "me.use(2, *bob): ";
    me->use(2, *bob);
    std::cout << std::endl;

    me->unequip(0);
    me->use(0, *bob);

    delete bob;
    delete me;
    delete src;

    return 0;
}