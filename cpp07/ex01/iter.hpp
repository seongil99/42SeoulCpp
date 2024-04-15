/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:33:08 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/15 17:51:55 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T *arr, size_t len, void (*func)(T const &)) {
    if (!arr || !func) {
        return;
    }
    for (size_t i = 0; i < len; i++) {
        func(arr[i]);
    }
}

template <typename T>
void print(T const &elem) {
    std::cout << elem << ' ';
}

#endif