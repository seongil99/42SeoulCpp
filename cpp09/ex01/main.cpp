/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:13:12 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/24 18:13:19 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./rpn [input]" << std::endl;
        return 1;
    }

    RPN rpn(argv[1]);
    rpn.calculate();
    std::cout << rpn.getResult() << std::endl;

    return 0;
}