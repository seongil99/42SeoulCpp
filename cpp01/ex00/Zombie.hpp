/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:37:02 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/17 16:00:03 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <string>

class Zombie {

public:
	void	announce( void );
	Zombie ( std::string name );
	~Zombie( void );

private:
	std::string	_name;

};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
