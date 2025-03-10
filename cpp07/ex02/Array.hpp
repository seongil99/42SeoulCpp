/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:42:49 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/15 17:36:37 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T> class Array {
  private:
    T *_arr;
    unsigned int _size;

  public:
    Array(void) : _arr(NULL), _size(0) {}

    Array(unsigned int n) : _arr(new T[n]), _size(n) {}

    Array(const Array &other) : _size(other._size) {
        if (!other._arr)
            return;
        _arr = new T[other._size];
        if (!_arr)
            return;
        for (unsigned int i = 0; i < _size; i++)
            _arr[i] = other._arr[i];
    }

    virtual ~Array() { delete[] _arr; }

    Array &operator=(const Array &other) {
        if (this == &other || !other._arr)
            return *this;
        T *t = new T[other._size];
        if (!t)
            return *this;
        for (unsigned int i = 0; i < other._size; i++)
            t[i] = other._arr[i];
        delete[] _arr;
        _size = other._size;
        _arr = t;
        return *this;
    }

    T &operator[](unsigned int i) {
        if (!_arr)
            throw NullArrayException();
        if (i >= _size)
            throw OutOfRangeException();
        return _arr[i];
    }

    const T &operator[](unsigned int i) const {
        if (!_arr)
            throw NullArrayException();
        if (i >= _size)
            throw OutOfRangeException();
        return _arr[i];
    }

    unsigned int size(void) const { return _size; }

    class OutOfRangeException : public std::exception {
        virtual const char *what() const throw() { return "Out of range"; }
    };

    class NullArrayException : public std::exception {
        virtual const char *what() const throw() { return "Null Array"; }
    };
};

#endif
