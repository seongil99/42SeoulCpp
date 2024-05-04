/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:27:28 by seonyoon          #+#    #+#             */
/*   Updated: 2024/05/04 15:43:52 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char *av[]) {
    if (ac < 2) {
        std::cerr << "Usage: ./PmergeMe [positive integers ..]" << std::endl;
        return 1;
    }
    PmergeMe pmergeMe;

    try {
        pmergeMe.addNumber(ac, av);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    pmergeMe.sort();
    pmergeMe.print();
    return 0;
}
