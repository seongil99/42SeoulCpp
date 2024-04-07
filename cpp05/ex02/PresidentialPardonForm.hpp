/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:15:14 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/07 22:23:00 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
   private:
    const std::string target;

   public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &ref);
    virtual ~PresidentialPardonForm(void);

    PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);

    void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &ref);

#endif