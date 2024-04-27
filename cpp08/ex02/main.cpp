/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:29:07 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/26 19:10:30 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

#include "MutantStack.hpp"

int main(void) {
    std::cout << "------------------------------" << std::endl;
    std::cout << "MutantStack test" << std::endl;
    std::cout << "------------------------------" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
        while (!s.empty()) {
            std::cout << s.top() << std::endl;
            s.pop();
        }
    }
    std::cout << "------------------------------" << std::endl;
    std::cout << "<list> test" << std::endl;
    std::cout << "------------------------------" << std::endl;
    {
        std::list<int> list;
        list.push_back(5);
        list.push_back(17);
        std::cout << list.back() << std::endl;
        list.pop_back();
        std::cout << list.size() << std::endl;
        list.push_back(3);
        list.push_back(5);
        list.push_back(737);
        list.push_back(0);
        std::list<int>::iterator it = list.begin();
        std::list<int>::iterator ite = list.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(list);
        while (s.size()) {
            std::cout << s.back() << std::endl;
            s.pop_back();
        }
    }

    return 0;
}
