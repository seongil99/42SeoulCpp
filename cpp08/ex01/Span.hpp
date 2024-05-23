/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:45:35 by seonyoon          #+#    #+#             */
/*   Updated: 2024/05/23 15:21:48 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstddef>
#include <vector>

class Span {
  private:
    size_t _n;
    std::vector<int> _v;

  public:
    Span(void);
    Span(unsigned int n);
    Span(const Span &other);
    virtual ~Span(void);

    Span &operator=(const Span &other);

    void addNumber(int n);
    void addNumber(std::vector<int>::iterator b, std::vector<int>::iterator e);
    unsigned int shortestSpan(void);
    unsigned int longestSpan(void);
    std::vector<int>::iterator begin(void);
    std::vector<int>::iterator end(void);
};

#endif
