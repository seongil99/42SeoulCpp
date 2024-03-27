/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:18:01 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/20 12:15:12 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	std::string		filename;
	std::string		fromStr;
	std::string		toStr;
	std::string		line;
	std::ofstream	ofs;
	std::ifstream	ifs;

	if (argc != 4)
	{
		std::cerr << "Error: need three arguments" << std::endl;
		return 1;
	}
	filename = argv[1];
	fromStr = argv[2];
	toStr = argv[3];
	if (!filename.size() || !fromStr.size() || !toStr.size())
	{
		std::cerr << "Error: argument lenght should not be zero" << std::endl;
		return 1;
	}
	ifs.open(filename);
	if (ifs.fail())
	{
		std::cerr << "Error: cannot open " << filename << std::endl;
		return 1;
	}
	ofs.open(filename.append(".replace"));
	if (ofs.fail())
	{
		std::cerr << "Error: cannot open replace file " << filename.append(".replace") << std::endl;
		return 1;
	}
	while (std::getline(ifs, line))
	{
		std::size_t idx;
		while (true)
		{
			idx = line.find(fromStr);
			if (idx == std::string::npos)
				break;
			line.erase(idx, fromStr.size());
			line.insert(idx, toStr);
		}
		ofs << line;
		if (ifs.eof())
			break ;
		ofs << std::endl;
	}
	ifs.close();
	ofs.close();
	return 0;
}
