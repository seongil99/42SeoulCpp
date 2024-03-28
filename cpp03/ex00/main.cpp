/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:50:09 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/28 10:24:55 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clapTrap1("CT1");
	ClapTrap clapTrap2("CT2");

	clapTrap1.attack("CT2");
	clapTrap1.attack("CT2");
	clapTrap1.attack("CT2");
	clapTrap1.attack("CT2");
	clapTrap1.attack("CT2");
	clapTrap1.attack("CT2");
	clapTrap1.attack("CT2");
	clapTrap1.attack("CT2");
	clapTrap1.attack("CT2");
	clapTrap1.attack("CT2");
	clapTrap1.attack("CT2");
	clapTrap2.takeDamage(5);
	clapTrap2.beRepaired(3);
	clapTrap2.takeDamage(100);
	clapTrap2.takeDamage(5);
	clapTrap2.beRepaired(10);
	return 0;
}
