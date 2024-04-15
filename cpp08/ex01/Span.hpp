/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:45:35 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/15 18:57:06 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
   private:
    unsigned int _n;
    unsigned int _size;
    std::vector<int> _v;

   public:
    Span(void);
    Span(unsigned int n);
    Span(const Span &other);
    virtual ~Span(void);

    Span &operator=(const Span &other);

    void addNumber(int n);
    unsigned int shortestSpan(void);
    unsigned int longestSpan(void);

    void fillRandom(void);
};

#endif
