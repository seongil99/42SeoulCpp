/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:28:30 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/15 18:42:42 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main(void) {
    std::vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }

    std::vector<int>::iterator it = easyfind(vec, 5);
    if (it != vec.end()) {
        std::cout << "Found: " << *it << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    std::vector<int>::iterator it2 = easyfind(vec, 42);
    if (it2 != vec.end()) {
        std::cout << "Found: " << *it2 << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}