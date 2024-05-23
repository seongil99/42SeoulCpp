/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:30:35 by seonyoon          #+#    #+#             */
/*   Updated: 2024/05/23 14:52:18 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Array.hpp"

int main(void) {
    const Array<int> emptyArray;
    Array<int> intArray(5);
    Array<std::string> stringArray(3);

    try {
        std::cout << "emptyArray[0]: ";
        std::cout << emptyArray[0] << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    intArray[0] = 1;
    intArray[1] = 2;
    intArray[2] = 3;
    intArray[3] = 4;
    intArray[4] = 5;

    try {
        std::cout << "intArray[5]: ";
        std::cout << intArray[5] << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "!";

    std::cout << "intArray: ";
    for (unsigned int i = 0; i < intArray.size(); i++)
        std::cout << ++intArray[i] << " ";
    std::cout << std::endl;

    std::cout << "stringArray: ";
    for (unsigned int i = 0; i < stringArray.size(); i++)
        std::cout << stringArray[i] << " ";
    std::cout << std::endl;

    return 0;
}
