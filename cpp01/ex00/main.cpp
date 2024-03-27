/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:37:11 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/17 16:02:48 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	stack("stack1");
	Zombie	*heap = newZombie("heap1");

	randomChump("stack2");
	stack.announce();
	heap->announce();
	delete heap;
	return 0;
}
