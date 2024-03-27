/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:17:41 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/20 13:36:34 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl	harl;

	if (argc !=2)
	{
		std::cerr << "program argument error" << std::endl;
		return 1;
	}
	harl.complain(argv[1]);
	return 0;
}
