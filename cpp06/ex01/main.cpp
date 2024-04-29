/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:53:06 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/29 18:43:06 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Serializer.hpp"

int main(void) {
    Data *data = new Data;
    if (!data)
        return 1;
    data->n = 42;
    data->f = 42.42;
    data->c = 'a';

    uintptr_t raw = Serializer::serialize(data);
    if (!raw) {
        delete data;
        return 1;
    }
    std::cout << "raw: " << raw << std::endl;

    Data *newData = Serializer::deserialize(raw);
    std::cout << "Data: " << newData->n << ", " << newData->f << ", "
              << newData->c << std::endl;

    delete data;
    delete newData;

    return 0;
}
