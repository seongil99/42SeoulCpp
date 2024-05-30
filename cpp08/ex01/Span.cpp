/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:49:39 by seonyoon          #+#    #+#             */
/*   Updated: 2024/05/28 18:56:18 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>
#include <limits>

Span::Span(void) : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &other) { *this = other; }

Span::~Span(void) {}

Span &Span::operator=(const Span &other) {
    if (this == &other)
        return *this;
    _n = other._n;
    _v = other._v;
    return *this;
}

void Span::addNumber(int n) {
    if (_v.size() + 1 > _n)
        throw std::out_of_range("out of range");
    _v.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator b,
                     std::vector<int>::iterator e) {
    for (; b != e && _v.size() <= _n; b++) {
        if (_v.size() == _n)
            throw std::out_of_range("out of range");
        _v.push_back(*b);
    }
}

unsigned int Span::shortestSpan(void) {
    if (_v.size() <= 1)
        throw std::runtime_error("not enough number stored");
    std::vector<int> v = _v;
    std::sort(v.begin(), v.begin() + _v.size());
    unsigned int min = std::numeric_limits<unsigned int>::max();
    for (size_t i = 1; i < _v.size(); i++) {
        unsigned int diff = v[i] - v[i - 1];
        if (diff < min)
            min = diff;
    }
    return min;
}

unsigned int Span::longestSpan(void) {
    if (_v.size() <= 1)
        throw std::runtime_error("not enough number stored");
    std::vector<int> v = _v;
    std::sort(v.begin(), v.begin() + _v.size());
    return v[_v.size() - 1] - v[0];
}

std::vector<int>::iterator Span::begin(void) { return _v.begin(); }
std::vector<int>::iterator Span::end(void) { return _v.end(); }
