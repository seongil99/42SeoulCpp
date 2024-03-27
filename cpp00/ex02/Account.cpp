/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:35:26 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/27 12:44:50 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created"
		<< std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed"
		<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount;

	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	bool	ret;
	int		p_amount;

	p_amount = _amount;
	_amount -= withdrawal;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";withdrawal:";
	if (checkAmount())
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals
			<< std::endl;
		ret = true;
	}
	else
	{
		std::cout << "refused" << std::endl;
		_amount += withdrawal;
		ret = false;
	}
	return ret;
}

int	Account::checkAmount(void) const
{
	if (_amount < 0)
		return 0;
	return 1;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t	t;
	char	buf[20] = {0, };

	std::time(&t);
	std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", std::localtime(&t));
	std::cout << "[" << buf << "]";
}
