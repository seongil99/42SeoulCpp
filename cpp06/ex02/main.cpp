/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:02:18 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/15 15:07:32 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

int main(void) {
    Base *random1 = generate();
    Base *random2 = generate();
    Base *random3 = generate();

    Base &random1_ref = *random1;
    Base &random2_ref = *random2;
    Base &random3_ref = *random3;
    std::cout << std::endl;

    identify(random1);
    identify(random2);
    identify(random3);
    std::cout << std::endl;

    identify(random1_ref);
    identify(random2_ref);
    identify(random3_ref);

    delete random1;
    delete random2;
    delete random3;

    return 0;
}