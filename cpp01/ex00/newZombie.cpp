/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:37:09 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/27 14:46:39 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*ret = new Zombie;
	if (!ret)
	{
		std::cerr << "Mem error" << std::endl;
		std::exit(1);
	}
	ret->setName(name);
	return ret;
}
