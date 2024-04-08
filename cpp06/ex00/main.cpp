/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:46:00 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/08 17:02:59 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Converter.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }
    Converter::convert(argv[1]);
    return 0;
}
