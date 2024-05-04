/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:35:03 by seonyoon          #+#    #+#             */
/*   Updated: 2024/05/04 14:42:25 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    iter<int>(arr, 5, print<int>);
    std::cout << std::endl;
    iter(arr, 5, print);
    std::cout << std::endl;

    float arr2[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    iter(arr2, 5, print);
    std::cout << std::endl;

    std::string arr3[] = {"one", "two", "three", "four", "five"};
    iter(arr3, 5, print);
    std::cout << std::endl;

    return 0;
}
