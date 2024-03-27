/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:18:36 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/27 14:49:38 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <sstream>

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie 				*zombies;
	std::stringstream	sInt;

	zombies = new Zombie[N];
	if (!zombies)
	{
		std::cerr << "Mem error" << std::endl;
		std::exit(1);
	}
	for (int i = 0; i < N; i++)
	{
		sInt.str("");
		sInt << i;
		zombies[i].setName(name + sInt.str());
	}
	return zombies;
}
