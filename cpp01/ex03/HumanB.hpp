/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:48:40 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/17 19:32:26 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMAN_B__
#define __HUMAN_B__

#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string	name;
	Weapon	*weapon;
public:
	HumanB(std::string name);
	~HumanB();
	void	setWeapon(Weapon &weapon);
	void	attack(void) const;
};


#endif
