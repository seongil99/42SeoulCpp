/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:48:36 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/19 15:16:32 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMAN_A__
#define __HUMAN_A__

#include "Weapon.hpp"
#include <string>

class HumanA
{
private:
	std::string	name;
	Weapon		&weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack(void) const;
};

#endif
