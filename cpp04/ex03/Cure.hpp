/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:36:09 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/30 13:15:22 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
   private:
    Cure(const Cure &ref);
    Cure &operator=(const Cure &ref);

   public:
    Cure(void);
    ~Cure(void);

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif