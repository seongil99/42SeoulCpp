/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:10:57 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/24 18:13:07 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
   private:
    std::stack<int> stack;
    std::string input;
    int result;

   public:
    RPN(void);
    RPN(std::string input);
    ~RPN(void);

    RPN &operator=(const RPN &other);

    void calculate(void);
    int getResult(void);
};

#endif