/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:25:53 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 14:28:41 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
   private:
    Brain *brain;

   public:
    Cat(void);
    Cat(const Cat &ref);
    ~Cat(void);

    Cat &operator=(const Cat &ref);

    void makeSound(void) const;
    Brain *getBrain(void) const;
};

#endif