/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:47:32 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/24 15:16:34 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {

public:
	bool			inputFirstname(void);
	bool			inputLastname(void);
	bool			inputNickname(void);
	bool			inputPhoneNumber(void);
	bool			inputDarkestSecret(void);
	void			setFirstname(std::string str);
	void			setLastname(std::string str);
	void			setNickname(std::string str);
	void			setPhoneNumber(std::string str);
	void			setDarkestSecret(std::string str);
	std::string		getFirstname(void);
	std::string		getLastname(void);
	std::string		getNickname(void);
	std::string		getPhoneNumber(void);
	std::string		getDarkestSecret(void);
	void			clear(void);

private:
	std::string		firstname;
	std::string		lastname;
	std::string		nickname;
	std::string		phoneNumber;
	std::string		darkestSecret;
};

#endif
