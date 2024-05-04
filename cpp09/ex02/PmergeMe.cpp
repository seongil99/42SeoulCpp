/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:27:24 by seonyoon          #+#    #+#             */
/*   Updated: 2024/05/04 17:52:32 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>
#include <cstdlib>
#include <limits>

PmergeMe::PmergeMe(void) : _t_deq(0), _t_vec(0) {}

PmergeMe::PmergeMe(const PmergeMe &ref)
    : _t_deq(ref._t_deq), _t_vec(ref._t_vec), _before(ref._before),
      _dq(ref._dq), _vec(ref._vec) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &ref) {
    if (this == &ref)
        return *this;
    this->_t_deq = ref._t_deq;
    this->_t_vec = ref._t_vec;
    this->_before = ref._before;
    this->_vec = ref._vec;
    this->_dq = ref._dq;
    return *this;
}

bool PmergeMe::_is_integer(const char *str) {
    for (int i = 0; str[i]; i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void PmergeMe::_addNumber(int n) { _before.push_back(n); }

void PmergeMe::addNumber(int ac, char *av[]) {
    for (int i = 1; i < ac; i++) {
        double value = std::strtod(av[i], NULL);
        if (value > std::numeric_limits<int>::max() || value < 0 ||
            !_is_integer(av[i]))
            throw PmergeMe::BadInputException();
        _addNumber(static_cast<int>(value));
    }
}

/**
 * Example
 * Before: 3 5 9 7 4
 * After: 3 4 5 7 9
 * Time to process a range of 5 elements with std::[..] : 0.00031 us
 * Time to process a range of 5 elements with std::[..] : 0.00014 us
 */
void PmergeMe::print(void) {
    std::cout << "Before: ";
    for (unsigned int i = 0; i < _before.size(); i++)
        std::cout << _before[i] << " ";
    std::cout << std::endl;
    std::cout << "After: ";
    for (unsigned int i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of 5 elements with std::vector : "
              << _t_vec << " us" << std::endl;
    std::cout << "Time to process a range of 5 elements with std::deq : "
              << _t_deq << " us" << std::endl;
}

void PmergeMe::sort(void) {}

const char *PmergeMe::BadInputException::what() const throw() {
    return "Bad Input";
}
