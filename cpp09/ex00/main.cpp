/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:03:58 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/26 15:06:03 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    BitcoinExchange exchange;

    if (argc != 2) {
        std::cerr << "Usage: ./btc [filename]" << std::endl;
        return 1;
    }
    try {
        exchange.run(argv[1]);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
