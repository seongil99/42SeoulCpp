/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:25:46 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/26 09:59:41 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(const Animal &ref);
	virtual ~Animal(void);
	Animal &operator=(const Animal &ref);
	std::string getType(void) const;
	virtual void makeSound(void) const = 0;
};

#endif