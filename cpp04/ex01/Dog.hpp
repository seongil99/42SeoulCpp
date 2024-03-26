/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:25:58 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/26 00:31:26 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;

public:
	Dog(void);
	Dog(const Dog &ref);
	~Dog(void);
	Dog &operator=(const Dog &ref);
	void makeSound(void) const;
	Brain *getBrain(void) const;
};

#endif
