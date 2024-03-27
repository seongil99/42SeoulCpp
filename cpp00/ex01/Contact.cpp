/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:13:44 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/24 20:13:08 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

bool	Contact::inputFirstname(void)
{
	std::string	input;

	std::cout << "  Firstname\n  > ";
	std::getline(std::cin, input);
	if (std::cin.eof() || !input.size())
	{
		if (!input.size())
			std::cerr << "  Nothing was entered" << std::endl;
		return true;
	}
	this->firstname = input;
	return false;
}

bool	Contact::inputLastname(void)
{
	std::string	input;

	std::cout << "  Lastname\n  > ";
	std::getline(std::cin, input);
	if (std::cin.eof() || !input.size())
	{
		if (!input.size())
			std::cerr << "  Nothing was entered" << std::endl;
		return true;
	}
	this->lastname = input;
	return false;
}

bool	Contact::inputNickname(void)
{
	std::string	input;

	std::cout << "  Nickname\n  > ";
	std::getline(std::cin, input);
	if (std::cin.eof() || !input.size())
	{
		if (!input.size())
			std::cerr << "  Nothing was entered" << std::endl;
		return true;
	}
	this->nickname = input;
	return false;
}

bool	Contact::inputPhoneNumber(void)
{
	std::string	input;

	std::cout << "  Phone number\n  > ";
	std::getline(std::cin, input);
	if (std::cin.eof() || !input.size())
	{
		if (!input.size())
			std::cerr << "  Nothing was entered" << std::endl;
		return true;
	}
	this->phoneNumber = input;
	return false;

}

bool	Contact::inputDarkestSecret(void)
{
	std::string	input;

	std::cout << "  Darkest secret\n  > ";
	std::getline(std::cin, input);
	if (std::cin.eof() || !input.size())
	{
		if (!input.size())
			std::cerr << "  Nothing was entered" << std::endl;
		return true;
	}
	this->darkestSecret = input;
	return false;
}

void	Contact::setFirstname(std::string str)
{
	this->firstname = str;
}

void	Contact::setLastname(std::string str)
{
	this->lastname = str;
}

void	Contact::setNickname(std::string str)
{
	this->nickname = str;
}

void	Contact::setPhoneNumber(std::string str)
{
	this->phoneNumber = str;
}

void	Contact::setDarkestSecret(std::string str)
{
	this->darkestSecret = str;
}

static std::string	ftGetString(std::string str)
{
	std::string	ret;

	if (str.length() <= 10)
		ret = str;
	else
		for (int i = 0; i < 10; i++)
			ret.push_back(str[i]);
	return (ret);
}

std::string		Contact::getFirstname(void)
{
	return ftGetString(this->firstname);
}

std::string		Contact::getLastname(void)
{
	return ftGetString(this->lastname);
}

std::string		Contact::getNickname(void)
{
	return ftGetString(this->nickname);
}

std::string		Contact::getPhoneNumber(void)
{
	return ftGetString(this->phoneNumber);
}

std::string		Contact::getDarkestSecret(void)
{
	return ftGetString(this->darkestSecret);
}

void	Contact::clear(void)
{
	this->firstname.clear();
	this->lastname.clear();
	this->nickname.clear();
	this->phoneNumber.clear();
	this->darkestSecret.clear();
}
