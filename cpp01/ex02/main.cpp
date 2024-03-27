/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:14 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/17 17:30:43 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string		stringORG("HI THIS IS BRAIN");

	std::string		*stringPTR = &stringORG;
	std::string		&stringREF = stringORG;

	std::cout << "Address of stringORG: " << &stringORG << std::endl;
	std::cout << "Address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of variable stringORG: " << stringORG << std::endl;
	std::cout << "Value pointed to stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to stringREF: " << stringREF << std::endl;
}
