/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:11:30 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 11:44:31 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
   public:
    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &ref);
    ~ScavTrap(void);

    ScavTrap &operator=(const ScavTrap &ref);

    void attack(const std::string &target);
    void guardGate(void) const;
};

#endif