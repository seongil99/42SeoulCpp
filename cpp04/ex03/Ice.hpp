/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:36:23 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/30 13:17:28 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
   private:
    Ice(const Ice &ref);
    Ice &operator=(const Ice &ref);

   public:
    Ice(void);
    ~Ice(void);

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif