/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:27:21 by seonyoon          #+#    #+#             */
/*   Updated: 2024/05/03 19:07:55 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>

class PergeMe {
  private:
    int _n;
    int _m;
    std::deque<int> _dq;
    std::vector<int> _vec;

  public:
    PergeMe(void);
    PergeMe(const PergeMe &other);
    ~PergeMe(void);

    PergeMe &operator=(const PergeMe &other);

    void addNumber(int n);
    void merge(void);
    void print(void);
};

#endif
