/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:53:06 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/23 16:13:38 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"

int main(void) {
    Data *data = new Data;
    data->str = "Hello";
    data->num = 42;

    uintptr_t raw = Serializer::serialize(data);
    std::cout << "raw: " << raw << std::endl;

    Data *newData = Serializer::deserialize(raw);
    std::cout << "Data: " << newData->str << " " << newData->num << std::endl;

    delete data;

    return 0;
}
