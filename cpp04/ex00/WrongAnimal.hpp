/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:10:37 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 12:37:40 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
   protected:
    std::string type;

   public:
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal &ref);
    virtual ~WrongAnimal(void);

    WrongAnimal &operator=(const WrongAnimal &ref);

    std::string getType(void) const;
    void makeSound(void) const;
};

#endif