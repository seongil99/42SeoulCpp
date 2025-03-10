/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:50:09 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/28 17:09:18 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"

int main(void) {
    ClapTrap clapTrap1("CT1");
    ScavTrap scavTrap1("ST1");
    std::cout << std::endl;

    scavTrap1.attack("CT1");
    clapTrap1.takeDamage(scavTrap1.getAttackDamage());
    std::cout << std::endl;

    clapTrap1.beRepaired(10);
    scavTrap1.guardGate();
    std::cout << std::endl;

    return 0;
}
