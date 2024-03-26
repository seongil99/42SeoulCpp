/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:58:47 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/26 12:05:07 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_HPP
#define MATERIA_HPP

#include "AMateria.hpp"

class Materia : public AMateria
{
public:
	Materia(std::string const &type);
	Materia(const Materia &ref);
	virtual ~Materia(void);
	Materia &operator=(const Materia &ref);

	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif