/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:14:53 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 11:44:18 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAG_TRAP_HPP__
#define __FRAG_TRAP_HPP__

#include <string>

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
   public:
    FragTrap(void);
    FragTrap(std::string name);
    FragTrap(const FragTrap &ref);
    ~FragTrap(void);

    FragTrap &operator=(const FragTrap &ref);

    void highFivesGuys(void);
};

#endif