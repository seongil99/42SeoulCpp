/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:26:00 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/25 18:13:42 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	const WrongAnimal *wrong = new WrongCat();

	std::cout << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << std::endl;

	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound();

	std::cout << std::endl;
	delete meta;
	meta = NULL;
	delete j;
	j = NULL;
	delete i;
	i = NULL;
	delete wrong;
	wrong = NULL;
	return 0;
}