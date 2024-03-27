/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:18:36 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/17 16:55:37 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie 				*zombies;
	std::stringstream	sInt;

	zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		sInt.str("");
		sInt << i;
		zombies[i].setName(name + sInt.str());
	}
	return zombies;
}
