/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:27:24 by seonyoon          #+#    #+#             */
/*   Updated: 2024/06/04 13:53:08 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
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
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << _t_vec << " us"
              << std::endl;
    std::cout << "Time to process a range of " << _dq.size()
              << " elements with std::deque  : " << _t_deq << " us" << std::endl;
    std::cout << "Time to process a range of " << _lst.size()
                << " elements with std::list   : " << _t_lst << " us" << std::endl;
    std::cout << "Is sorted of std::vector<int>: " << (isSorted(_vec) ? "Yes" : "No") << std::endl;
    std::cout << "Is sorted of std::deque<int> : " << (isSorted(_dq) ? "Yes" : "No") << std::endl;
    std::cout << "Is sorted of std::list<int>  : " << (isSorted(_lst) ? "Yes" : "No") << std::endl;
}

int PmergeMe::findSmall(std::vector<std::pair<int, int> > &pair, int large) {
    for (unsigned int i = 0; i < pair.size(); i++) {
        if (pair[i].first == large)
            return pair[i].second;
    }
    return -1;
}

int PmergeMe::findSmall(std::deque<std::pair<int, int> > &pair, int large) {
    for (unsigned int i = 0; i < pair.size(); i++) {
        if (pair[i].first == large)
            return pair[i].second;
    }
    return -1;
}

int PmergeMe::findSmall(std::list<std::pair<int, int> > &pair, int large) {
    for (std::list<std::pair<int, int> >::iterator it = pair.begin(); it != pair.end(); it++) {
        if (it->first == large)
            return it->second;
    }
    return -1;
}

std::vector<int> PmergeMe::getPair(std::vector<int> &large,
                          std::vector<std::pair<int, int> > &pair) {
    std::vector<int> small;
    for (unsigned int i = 0; i < large.size(); i++) {
        small.push_back(findSmall(pair, large[i]));
    }
    if (large.size() % 2 == 1)
        small.push_back(pair[pair.size() - 1].second);
    return small;
}

std::deque<int> PmergeMe::getPair(std::deque<int> &large,
                        std::deque<std::pair<int, int> > &pair) {
    std::deque<int> small;
    for (unsigned int i = 0; i < large.size(); i++) {
        small.push_back(findSmall(pair, large[i]));
    }
    if (large.size() % 2 == 1)
        small.push_back(pair[pair.size() - 1].second);
    return small;
}

std::list<int> PmergeMe::getPair(std::list<int> &large,
                       std::list<std::pair<int, int> > &pair) {
    std::list<int> small;
    std::list<int>::iterator it = large.begin();
    for (unsigned int i = 0; i < large.size(); i++) {
        small.push_back(findSmall(pair, *it));
        it++;
    }
    if (large.size() % 2 == 1)
        small.push_back(pair.back().second);
    return small;
}

std::vector<int> PmergeMe::insertMerge(std::vector<int> &result,
                                       std::vector<std::pair<int, int> > &pair) {
    std::vector<int> large(result);
    std::vector<int> small = getPair(large, pair);

    result.insert(result.begin(), small[0]);

    int jacob_prev = 1;
    int jacob_now = 3;
    int jacob_next = jacob_prev * 2 + jacob_now;
    int idx = std::min(jacob_now, static_cast<int>(large.size()));
    for (unsigned int i = 1; i < large.size(); i++) {
        if (idx == jacob_prev) {
            jacob_next = jacob_prev * 2 + jacob_now;
            jacob_prev = jacob_now;
            jacob_now = jacob_next;
            idx = std::min(jacob_now, static_cast<int>(large.size()));
        }
        std::vector<int>::iterator find_idx_it = std::find(result.begin(), result.end(), large[idx - 1]);
        std::vector<int>::iterator insert_idx_it = std::lower_bound(result.begin(), find_idx_it, small[idx - 1]);
        result.insert(insert_idx_it, small[idx - 1]);
        --idx;
    }
    if (large.size() % 2 == 1) {
        std::vector<int>::iterator insert_idx_it = std::lower_bound(result.begin(), result.end(), small[small.size() - 1]);
        result.insert(insert_idx_it, small[small.size() - 1]);
    }
    return result;
}

std::deque<int> PmergeMe::insertMerge(std::deque<int> &result,
                                      std::deque<std::pair<int, int> > &pair) {
    std::deque<int> large(result);
    std::deque<int> small = getPair(large, pair);

    result.push_front(small[0]);

    int jacob_prev = 1;
    int jacob_now = 3;
    int jacob_next = jacob_prev * 2 + jacob_now;
    int idx = std::min(jacob_now, static_cast<int>(large.size()));
    for (unsigned int i = 1; i < large.size(); i++) {
        if (idx == jacob_prev) {
            jacob_next = jacob_prev * 2 + jacob_now;
            jacob_prev = jacob_now;
            jacob_now = jacob_next;
            idx = std::min(jacob_now, static_cast<int>(large.size()));
        }
        std::deque<int>::iterator find_idx_it = std::find(result.begin(), result.end(), large[idx - 1]);
        std::deque<int>::iterator insert_idx_it = std::lower_bound(result.begin(), find_idx_it, small[idx - 1]);
        result.insert(insert_idx_it, small[idx - 1]);
        --idx;
    }
    if (large.size() % 2 == 1) {
        std::deque<int>::iterator insert_idx_it = std::lower_bound(result.begin(), result.end(), small[small.size() - 1]);
        result.insert(insert_idx_it, small[small.size() - 1]);
    }
    return result;
}

std::list<int> PmergeMe::insertMerge(std::list<int> &result,
                                     std::list<std::pair<int, int> > &pair) {
    std::list<int> large(result);
    std::list<int> small = getPair(large, pair);

    result.push_front(small.front());

    int jacob_prev = 1;
    int jacob_now = 3;
    int jacob_next = jacob_prev * 2 + jacob_now;
    int idx = std::min(jacob_now, static_cast<int>(large.size()));
    for (unsigned int i = 1; i < large.size(); i++) {
        if (idx == jacob_prev) {
            jacob_next = jacob_prev * 2 + jacob_now;
            jacob_prev = jacob_now;
            jacob_now = jacob_next;
            idx = std::min(jacob_now, static_cast<int>(large.size()));
        }
        std::list<int>::iterator large_idx_it = large.begin();
        std::advance(large_idx_it, idx - 1);
        std::list<int>::iterator find_idx_it = std::find(result.begin(), result.end(), *large_idx_it);
        std::list<int>::iterator small_idx_it = small.begin();
        std::advance(small_idx_it, idx - 1);
        std::list<int>::iterator insert_idx_it = std::lower_bound(result.begin(), find_idx_it, *small_idx_it);
        result.insert(insert_idx_it, *small_idx_it);
        --idx;
    }
    if (large.size() % 2 == 1) {
        std::list<int>::iterator insert_idx_it = std::lower_bound(result.begin(), result.end(), small.back());
        result.insert(insert_idx_it, small.back());
    }
    return result;
}

std::vector<int> PmergeMe::fordJohnsonSort(std::vector<int> &c) {
    if (c.size() <= 1)
        return c;
    std::vector<int> large;
    std::vector<std::pair<int, int> > pair;
    for (unsigned int i = 0; i < c.size() - 1; i += 2) {
        if (c[i] > c[i + 1]) {
            large.push_back(c[i]);
            pair.push_back(std::make_pair(c[i], c[i + 1]));
        } else {
            large.push_back(c[i + 1]);
            pair.push_back(std::make_pair(c[i + 1], c[i]));
        }
    }
    if (c.size() % 2 == 1)
        pair.push_back(std::make_pair(c[c.size() - 1], c[c.size() - 1]));
    std::vector<int> result = fordJohnsonSort(large);
    insertMerge(result, pair);
    return result;
}

std::deque<int> PmergeMe::fordJohnsonSort(std::deque<int> &c) {
    if (c.size() <= 1)
        return c;
    std::deque<int> large;
    std::deque<std::pair<int, int> > pair;
    for (unsigned int i = 0; i < c.size() - 1; i += 2) {
        if (c[i] > c[i + 1]) {
            large.push_back(c[i]);
            pair.push_back(std::make_pair(c[i], c[i + 1]));
        } else {
            large.push_back(c[i + 1]);
            pair.push_back(std::make_pair(c[i + 1], c[i]));
        }
    }
    if (c.size() % 2 == 1)
        pair.push_back(std::make_pair(c[c.size() - 1], c[c.size() - 1]));
    std::deque<int> result = fordJohnsonSort(large);
    insertMerge(result, pair);
    return result;
}

std::list<int> PmergeMe::fordJohnsonSort(std::list<int> &c) {
    if (c.size() <= 1)
        return c;
    std::list<int> large;
    std::list<std::pair<int, int> > pair;
    std::list<int>::iterator it = c.begin();
    for (unsigned int i = 0; i < c.size() - 1; i += 2) {
        if (*it > *(++it)) {
            large.push_back(*it);
            pair.push_back(std::make_pair(*it, *(it--)));
        } else {
            large.push_back(*it);
            pair.push_back(std::make_pair(*it, *(it--)));
        }
    }
    if (c.size() % 2 == 1)
        pair.push_back(std::make_pair(c.back(), c.back()));
    std::list<int> result = fordJohnsonSort(large);
    insertMerge(result, pair);
    return result;
}

void PmergeMe::sort(void) {
    struct timespec start, end;

    _vec = std::vector<int>(_before.begin(), _before.end());
    clock_gettime(CLOCK_REALTIME, &start);
    _vec = fordJohnsonSort(_vec);
    clock_gettime(CLOCK_REALTIME, &end);
    _t_vec = (end.tv_sec - start.tv_sec) * 1000000 +
             (end.tv_nsec - start.tv_nsec) / 1000;

    _dq = std::deque<int>(_before.begin(), _before.end());
    clock_gettime(CLOCK_REALTIME, &start);
    _dq = fordJohnsonSort(_dq);
    clock_gettime(CLOCK_REALTIME, &end);
    _t_deq = (end.tv_sec - start.tv_sec) * 1000000 +
             (end.tv_nsec - start.tv_nsec) / 1000;

    _lst = std::list<int>(_before.begin(), _before.end());
    clock_gettime(CLOCK_REALTIME, &start);
    _lst = fordJohnsonSort(_lst);
    clock_gettime(CLOCK_REALTIME, &end);
    _t_lst = (end.tv_sec - start.tv_sec) * 1000000 +
             (end.tv_nsec - start.tv_nsec) / 1000;
}

// void PmergeMe::initJacobstal(int size) {
//     _jacobsthal.push_back(0);
//     _jacobsthal.push_back(1);
//     for (int i = 2; i < size; i++) {
//         _jacobsthal.push_back(_jacobsthal[i - 1] + 2 * _jacobsthal[i - 2]);
//     }
// }

const char *PmergeMe::BadInputException::what() const throw() {
    return "Bad Input";
}
