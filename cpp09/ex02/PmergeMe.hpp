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
#include <list>

class PmergeMe {
  private:
    double _t_deq;
    double _t_vec;
    double _t_lst;
    std::vector<int> _before;
    std::deque<int> _dq;
    std::list<int> _lst;
    std::vector<int> _vec;
    void _addNumber(int n);
    bool _is_integer(const char *str);
    std::vector<int> fordJohnsonSort(std::vector<int> &vec);
    std::list<int> fordJohnsonSort(std::list<int> &lst);
    std::deque<int> fordJohnsonSort(std::deque<int> &dq);
    std::vector<int> insertMerge(std::vector<int> &result,
                                 std::vector<std::pair<int, int> > &pair);
    std::deque<int> insertMerge(std::deque<int> &result,
                                std::deque<std::pair<int, int> > &pair);
    std::list<int> insertMerge(std::list<int> &result,
                               std::list<std::pair<int, int> > &pair);
    std::list<int> getPair(std::list<int> &large,
                           std::list<std::pair<int, int> > &pair);
    std::deque<int> getPair(std::deque<int> &large,
                            std::deque<std::pair<int, int> > &pair);
    std::vector<int> getPair(std::vector<int> &large,
                            std::vector<std::pair<int, int> > &pair);
    int findSmall(std::list<std::pair<int, int> > &pair, int large);
    int findSmall(std::deque<std::pair<int, int> > &pair, int large);
    int findSmall(std::vector<std::pair<int, int> > &pair, int large);
    
    template <typename T>
    bool isSorted(T &container) {
        typename T::iterator it = container.begin();
        typename T::iterator ite = container.end();
        if (it == ite)
            return true;
        typename T::iterator it2 = it;
        while (++it2 != ite) {
            if (*it > *it2)
                return false;
            it = it2;
        }
        return true;
    }

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
