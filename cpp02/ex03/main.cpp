/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:02:44 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/23 16:27:16 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void) {
	Point	t1(-5, 0);
	Point	t2(5, 0);
	Point	t3(0, 5);

	Point	p1(0, 1);
	Point	p2(5, 5);

	std::cout << bsp(t1, t2, t3, p1) << std::endl;
	std::cout << bsp(t1, t2, t3, p2) << std::endl;
	return 0;
}
