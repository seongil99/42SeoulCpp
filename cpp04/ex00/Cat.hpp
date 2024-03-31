/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:25:53 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 12:37:13 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
   public:
    Cat(void);
    Cat(const Cat &ref);
    ~Cat(void);

    Cat &operator=(const Cat &ref);

    void makeSound(void) const;
};

#endif