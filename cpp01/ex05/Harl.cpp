/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:39:52 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/11 13:43:04 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
	return;
}

Harl::~Harl( void )
{
	return;
}

void Harl::debug( void )
{

	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I don't know how to use lldb !" << std::endl;
	// return ;

}

void Harl::info( void )
{

	std::cout << "[INFO]" << std::endl;
	std::cout << "Where can I find that info ? It's not on cplusplus.com !" << std::endl;
	// return ;

}

void Harl::warning( void )
{

	std::cout << "[WARNING]" << std::endl;
	std::cout << "Let me warn you, this function isn't compatible with the version of CPP we have to use !" << std::endl;
	// return ;

}

void Harl::error( void )
{

	std::cout << "[ERROR]" << std::endl;
	std::cout << "Help me, i segfaulted :(" << std::endl;
	// return ;

}

void	Harl::complain( std::string level )
{

	void (Harl::*ptr_array[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::transform(level.begin(), level.end(), level.begin(), toupper);
	std::string	array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (array[i] == level)
		{
			(this->*ptr_array[i])();
			break ;
		}
	}

}
