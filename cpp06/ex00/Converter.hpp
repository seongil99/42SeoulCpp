/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:47:41 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/23 16:06:28 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>

class Converter {
  private:
    Converter(void);
    Converter(const Converter &ref);
    Converter &operator=(const Converter &ref);
    ~Converter(void);

  public:
    static void convert(const std::string &input);
};

#endif
