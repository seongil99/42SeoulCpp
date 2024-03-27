/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:37:02 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/17 16:26:14 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <string>

class Zombie {

public:
	void	announce( void );
	void	setName( std::string name );
	Zombie ( std::string name );
	Zombie ( void );
	~Zombie( void );

private:
	std::string	_name;

};

Zombie* zombieHorde( int N, std::string name );

#endif
