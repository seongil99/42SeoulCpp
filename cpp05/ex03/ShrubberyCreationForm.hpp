/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:15:29 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/27 19:31:14 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

const std::string asciiTrees = "                ,@@@@@@@,\n"
                               "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
                               "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
                               "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
                               "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
                               "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
                               "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
                               "       |o|        | |         | |\n"
                               "       |.|        | |         | |\n"
                               "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";

class ShrubberyCreationForm : public AForm {
  private:
    const std::string target;

  public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &ref);
    virtual ~ShrubberyCreationForm(void);

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ref);

    void execute(Bureaucrat const &executor) const;
};

#endif
