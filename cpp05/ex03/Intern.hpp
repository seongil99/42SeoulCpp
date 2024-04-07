/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 22:33:05 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/07 22:49:14 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "AForm.hpp"

class Intern {
   public:
    Intern(void);
    Intern(const Intern &ref);
    ~Intern(void);

    Intern &operator=(const Intern &ref);

    AForm *makeForm(const std::string &formName, const std::string &target);

    class FormNotFoundException : public std::exception {
        virtual const char *what() const throw();
    };
};

#endif