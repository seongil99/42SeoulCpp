/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:47:41 by seonyoon          #+#    #+#             */
/*   Updated: 2024/04/06 20:00:17 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>

class Converter {
  private:
    std::string value;

  public:
    Converter(void);
    Converter(const Converter &ref);
    Converter(const std::string value);
    ~Converter(void);

    Converter &operator=(const Converter &ref);
};

std::ostream &operator<<(std::ostream &os, const Converter &converter);

#endif
