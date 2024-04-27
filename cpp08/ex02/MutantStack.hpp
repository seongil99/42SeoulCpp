/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:29:15 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/26 19:07:17 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
  public:
    MutantStack(void) : std::stack<T>() {}
    MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {}
    virtual ~MutantStack(void) {}

    MutantStack<T> &operator=(const MutantStack<T> &other) {
        if (this == &other)
            return (*this);
        *this = other;
        return (*this);
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin(void) { return (std::stack<T>::c.begin()); }
    iterator end(void) { return (std::stack<T>::c.end()); }

    typedef typename MutantStack<T>::stack::container_type::reverse_iterator
        reverse_iterator;
    reverse_iterator rbegin(void) { return (std::stack<T>::c.rbegin()); }
    reverse_iterator rend(void) { return (std::stack<T>::c.rend()); }
};

#endif
