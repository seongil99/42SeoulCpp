/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:53:00 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/29 19:08:50 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include <cstring>

uintptr_t Serializer::serialize(Data *ptr) {
    unsigned char *newData = new unsigned char[sizeof(Data)];
    if (!newData)
        return 0;
    std::memcpy(newData, ptr, sizeof(Data));
    return reinterpret_cast<uintptr_t>(newData);
}

Data *Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}
