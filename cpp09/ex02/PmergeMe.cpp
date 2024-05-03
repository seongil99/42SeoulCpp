/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:27:24 by seonyoon          #+#    #+#             */
/*   Updated: 2024/05/03 19:21:07 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>

PergeMe::PergeMe(void) : _m(0), _n(0) {}

PergeMe::PergeMe(const PergeMe &ref)
    : _m(ref._m), _n(ref._n), _vec(ref._vec), _dq(ref._dq) {}

PergeMe::~PergeMe(void) {}

PergeMe &PergeMe::operator=(const PergeMe &ref) {
    if (this == &ref)
        return *this;
    this->_m = ref._m;
    this->_n = ref._n;
    this->_vec = ref._vec;
    this->_dq = ref._dq;
    return *this;
}

void PergeMe::addNumber(int n) {
    _vec.push_back(n);
    _dq.push_back(n);
}

/**
 * Example
 * Before: 3 5 9 7 4
 * After: 3 4 5 7 9
 * Time to process a range of 5 elements with std::[..] : 0.00031 us
 * Time to process a range of 5 elements with std::[..] : 0.00014 us
 */
void PergeMe::print(void) {}
