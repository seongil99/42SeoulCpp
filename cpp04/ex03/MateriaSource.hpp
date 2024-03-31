/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:46:51 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/30 15:59:40 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
   private:
    AMateria *materias[4];

   public:
    MateriaSource(void);
    ~MateriaSource(void);
    MateriaSource(const MateriaSource &ref);
    MateriaSource &operator=(const MateriaSource &ref);

    void learnMateria(AMateria *materia);
    AMateria *createMateria(std::string const &type);
};

#endif