/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:27:21 by seonyoon          #+#    #+#             */
/*   Updated: 2024/06/03 13:44:07 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <vector>

class PmergeMe {
  private:
    double _t_deq;
    double _t_vec;
    std::vector<int> _before;
    std::deque<int> _dq;
    std::vector<int> _vec;
    std::vector<int> _jacobstal;
    void _addNumber(int n);
    bool _is_integer(const char *str);
    void mergeInsertionSort(std::vector<int> &vec, int start, int end);
    void mergeInsertionSort(std::deque<int> &dq, int start, int end);
    void initJacobstal(int size);

  public:
    PmergeMe(void);
    PmergeMe(const PmergeMe &other);
    ~PmergeMe(void);

    PmergeMe &operator=(const PmergeMe &other);

    void addNumber(int ac, char *av[]);
    void sort(void);
    void print(void);

    class BadInputException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
};

#endif
