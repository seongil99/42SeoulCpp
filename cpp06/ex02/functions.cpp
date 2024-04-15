/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:57:03 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/15 15:06:05 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base *generate(void) {
    int random = std::rand() % 3;

    if (random == 0) {
        std::cout << "A class generated" << std::endl;
        return (new A());
    } else if (random == 1) {
        std::cout << "B class generated" << std::endl;
        return (new B());
    } else {
        std::cout << "C class generated" << std::endl;
        return (new C());
    }
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B *>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C *>(p)) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base &p) {
    try {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    } catch (std::bad_cast &e) {
        try {
            B &b = dynamic_cast<B &>(p);
            (void)b;
            std::cout << "B" << std::endl;
        } catch (std::bad_cast &e) {
            try {
                C &c = dynamic_cast<C &>(p);
                (void)c;
                std::cout << "C" << std::endl;
            } catch (std::bad_cast &e) {
                std::cout << "Unknown class" << std::endl;
            }
        }
    }
}
