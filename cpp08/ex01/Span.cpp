/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:49:39 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/15 18:57:19 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>

Span::Span(void) : _n(0) {}

Span::Span(unsigned int n) : _n(n) {
    _size = 0;
    _v = std::vector<int>(n);
}

Span::Span(const Span &other) { *this = other; }

Span::~Span(void) {}

Span &Span::operator=(const Span &other) {
    if (this == &other) return *this;
    _n = other._n;
    _size = other._size;
    _v = other._v;
    return *this;
}

void Span::addNumber(int n) {
    if (_size >= _n) throw std::exception();
    _v[_size++] = n;
}

unsigned int Span::shortestSpan(void) {
    if (_size <= 1) throw std::exception();
    std::vector<int> v = _v;
    std::sort(v.begin(), v.begin() + _size);
    unsigned int min = UINT_MAX;
    for (unsigned int i = 1; i < _size; i++) {
        unsigned int diff = v[i] - v[i - 1];
        if (diff < min) min = diff;
    }
    return min;
}

unsigned int Span::longestSpan(void) {
    if (_size <= 1) throw std::exception();
    std::vector<int> v = _v;
    std::sort(v.begin(), v.begin() + _size);
    return v[_size - 1] - v[0];
}

void Span::fillRandom(void) {
    for (unsigned int i = 0; i < _n; i++) {
        _v[i] = rand();
    }
    _size = _n;
}