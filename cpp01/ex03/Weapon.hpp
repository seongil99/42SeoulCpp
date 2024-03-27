/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:48:52 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/17 18:49:53 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON__
#define __WEAPON__

#include <string>

class Weapon
{
private:
	std::string	type;
public:
	Weapon( void );
	Weapon( std::string type );
	~Weapon();
	const std::string	&getType( void ) const;
	void				setType( const std::string type );
};

#endif
