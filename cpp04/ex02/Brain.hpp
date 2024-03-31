/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:15:41 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/29 14:28:31 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
   private:
    std::string ideas[100];

   public:
    Brain(void);
    Brain(const Brain &ref);
    ~Brain(void);

    Brain &operator=(const Brain &ref);

    std::string getIdea(int idx) const;
    void setIdea(int idx, std::string idea);
};

#endif