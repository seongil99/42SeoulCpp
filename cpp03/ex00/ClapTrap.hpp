/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:47:03 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/28 11:11:10 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAP_TRAP_HPP__
#define __CLAP_TRAP_HPP__

#include <string>

class ClapTrap {
   private:
    std::string name;
    long long hitPoints;
    long long engergyPoints;
    long long attackDamage;

    void _printNoEnergyPoints(void) const;
    void _printNoHitPoints(void) const;

   public:
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &ref);
    ~ClapTrap(void);

    ClapTrap &operator=(const ClapTrap &ref);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName(void) const;
    int getHitPoints(void) const;
    int getEnergyPoints(void) const;
    int getAttackDamage(void) const;
};

#endif
