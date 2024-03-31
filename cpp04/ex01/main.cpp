/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:26:00 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 15:49:07 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
    Animal *meta[4];

    for (int i = 0; i < 2; i++) meta[i] = new Dog();
    for (int i = 2; i < 4; i++) meta[i] = new Cat();
    std::cout << std::endl;

    for (int i = 0; i < 4; i++) {
        std::cout << meta[i]->getType() << " " << std::endl;
        meta[i]->makeSound();
    }
    std::cout << std::endl;

    for (int i = 0; i < 4; i++) delete meta[i];
    std::cout << std::endl;

    Dog dog1;
    dog1.getBrain()->setIdea(0, "dog1 idea 0");
    dog1.getBrain()->setIdea(1, "dog1 idea 1");
    dog1.getBrain()->setIdea(2, "dog1 idea 2");
    std::cout << std::endl;

    Dog dog2 = dog1;
    std::cout << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << dog2.getBrain()->getIdea(1) << std::endl;
    std::cout << dog2.getBrain()->getIdea(2) << std::endl;
    std::cout << std::endl;

    std::cout << "dog1 brain address: " << dog1.getBrain() << std::endl;
    std::cout << "dog2 brain address: " << dog2.getBrain() << std::endl;
    std::cout << std::endl;

    return 0;
}