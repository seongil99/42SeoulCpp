/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:14:08 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/27 12:40:44 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

void	PhoneBook::add(void)
{
	if (
		this->contact[this->idx].inputFirstname()
		|| this->contact[this->idx].inputLastname()
		|| this->contact[this->idx].inputNickname()
		|| this->contact[this->idx].inputPhoneNumber()
		|| this->contact[this->idx].inputDarkestSecret()
	)
	{
		this->contact[this->idx].clear();
		std::cerr << "  Contact not saved" << std::endl;
		return;
	}
	this->idx = (this->idx + 1) % 8;
}

static bool	is_all_digit(std::string str)
{
	for(int i = 0; i < (int)str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void	PhoneBook::search(void)
{
	std::string	input;
	int			i;

	std::cout << "  Enter index: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return;
	}
	if (!input.size() || !is_all_digit(input))
	{
		std::cerr << "  Wrong index" << std::endl;
		return;
	}
	i = std::stoi(input);
	if (!(1 <= i && i <= 8))
	{
		std::cerr << "  Wrong index" << std::endl;
		return;
	}
	std::cout << std::setfill('.') << std::setw(10);
	std::cout << i << '|';
	std::cout << std::setfill('.') << std::setw(10);
	std::cout << this->contact[i - 1].getFirstname() << '|';
	std::cout << std::setfill('.') << std::setw(10);
	std::cout << this->contact[i - 1].getLastname() << '|';
	std::cout << std::setfill('.') << std::setw(10);
	std::cout << this->contact[i - 1].getNickname() << std::endl;
}

void	PhoneBook::loop(void)
{
	std::string	input;

	while (true)
	{
		if (std::cin.eof())
		{
			std::cin.clear();
			std::clearerr(stdin);
		}
		std::cout << "Enter a command(ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);
		if (input == "ADD")
			this->add();
		else if (input == "SEARCH")
			this->search();
		else if (input == "EXIT" || std::cin.eof())
		{
			std::cout << "exit" << std::endl;
			return;
		}
	}
}
