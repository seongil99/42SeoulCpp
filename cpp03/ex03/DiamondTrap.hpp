/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:35:02 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 12:22:38 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMOND_TRAP_HPP__
#define __DIAMOND_TRAP_HPP__

#include <string>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
   private:
    std::string name;

   public:
    DiamondTrap(void);
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &ref);
    ~DiamondTrap(void);

    DiamondTrap &operator=(const DiamondTrap &ref);

    void attack(const std::string &target);
    void whoAmI(void);

    std::string getName(void) const;
};

#endif