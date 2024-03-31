/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:33:33 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/30 13:21:21 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
   protected:
    std::string type;
    AMateria(void);
    AMateria(const AMateria &ref);
    AMateria &operator=(const AMateria &ref);

   public:
    AMateria(std::string const &type);
    virtual ~AMateria(void);

    std::string const &getType() const;  // Returns the materia type

    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif