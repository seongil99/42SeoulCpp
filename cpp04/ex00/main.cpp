/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:26:00 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 15:27:36 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    const WrongAnimal *wrong = new WrongCat();
    std::cout << std::endl;

    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;
    j->makeSound();
    std::cout << std::endl;

    std::cout << meta->getType() << " " << std::endl;
    meta->makeSound();
    std::cout << std::endl;

    std::cout << wrong->getType() << " " << std::endl;
    wrong->makeSound();
    std::cout << std::endl;

    delete meta;
    delete j;
    delete i;
    delete wrong;
    return 0;
}