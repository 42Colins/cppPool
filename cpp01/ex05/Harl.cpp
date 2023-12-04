/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:39:52 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/04 13:50:14 by cprojean         ###   ########.fr       */
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
	return ;

}

void Harl::get_debug( void )
{

	this->debug();

}

void Harl::info( void )
{

	std::cout << "[INFO]" << std::endl;
	std::cout << "Where can I find that info ? It's not on cplusplus.com !" << std::endl;
	return ;

}

void Harl::get_info( void )
{

	this->info();

}

void Harl::warning( void )
{

	std::cout << "[WARNING]" << std::endl;
	std::cout << "Let me warn you, this function isn't compatible with the version of CPP we have to use !" << std::endl;
	return ;

}

void Harl::get_warning( void )
{

	this->warning();

}

void Harl::error( void )
{

	std::cout << "[ERROR]" << std::endl;
	std::cout << "Help me, i segfaulted :(" << std::endl;
	return ;

}

void Harl::get_error( void )
{

	this->error();

}

void	Harl::complain( std::string level )
{

	if (level == "Debug" || level == "DEBUG" || level == "debug")
		this->get_debug();
	if (level == "Info" || level == "INFO" || level == "info")
		this->get_info();
	if (level == "Warning" || level == "WARNING" || level == "warning")
		this->get_warning();
	if (level == "Error" || level == "ERROR" || level == "error")
		this->get_error();

}