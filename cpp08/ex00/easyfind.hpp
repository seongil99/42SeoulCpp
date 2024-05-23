/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:27:46 by seonyoon          #+#    #+#             */
/*   Updated: 2024/05/23 13:36:35 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T> typename T::iterator easyfind(T &container, int value) {
    return std::find(container.begin(), container.end(), value);
}

template <typename T>
typename T::iterator easyfind(T const &container, const int value) {
    return std::find(container.begin(), container.end(), value);
}

#endif
