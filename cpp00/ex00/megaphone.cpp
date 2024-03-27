/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:41:36 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/15 15:00:03 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	ft_to_upper(char c)
{
	if (std::islower(c))
		c -= 'a' - 'A';
	return c;
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; j < (int)std::strlen(argv[i]); j++)
			argv[i][j] = ft_to_upper(argv[i][j]);
		std::cout << argv[i];
	}
	std::cout << std::endl;
	return 0;
}
