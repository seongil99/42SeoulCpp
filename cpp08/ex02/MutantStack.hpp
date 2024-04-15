/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:29:15 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/15 20:29:49 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
   public:
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}
    virtual ~MutantStack() {}

    MutantStack<T>& operator=(const MutantStack<T>& other) {
        std::stack<T>::operator=(other);
        return (*this);
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return (std::stack<T>::c.begin()); }
    iterator end() { return (std::stack<T>::c.end()); }
};

#endif
