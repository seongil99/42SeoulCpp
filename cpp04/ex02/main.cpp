/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:26:00 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/26 10:01:02 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::string str;
	Animal *meta[10];

	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			meta[i] = new Dog();
		}
		else
		{
			meta[i] = new Cat();
		}
	}
	std::cout << std::endl;

	for (size_t i = 0; i < 10; i++)
	{
		delete meta[i];
	}
	std::cout << std::endl;

	Dog *d = new Dog();
	Dog *d2 = new Dog();
	std::cout << std::endl;
	str = d->getBrain()->getIdea(0);
	std::cout << "Dog1's first idea is " << str << std::endl;

	d->getBrain()->setIdea(0, "something");
	str = d->getBrain()->getIdea(0);
	std::cout << "Dog1's first idea is " << str << std::endl;

	*d2 = *d;
	str = d2->getBrain()->getIdea(0);
	std::cout << "Dog2's first idea is " << str << std::endl;

	std::cout << std::endl;
	delete d;
	d = NULL;
	delete d2;
	d2 = NULL;

	return 0;
}