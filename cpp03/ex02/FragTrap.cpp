/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:07:13 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/11 16:51:24 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name )
{
	this->_name = name;
	this->_hp = 100;
	this->_mana = 100;
	this->_ad = 30;
	std::cout << "Building " << this->_name << std::endl << "   Setting AD" << std::endl << "   Setting HP" << std::endl << "  Setting MANA" << std::endl << "      DONE" << std::endl;
	return ;

}

FragTrap::FragTrap( const FragTrap &toCopy )
{

	*this = toCopy;
	return ;

}

FragTrap::FragTrap( void )
{

	return ;

}

FragTrap::~FragTrap( void )
{
	
	std::cout << "Dismantling " << this->_name << std::endl << "He's dead" << std::endl;
	return ;
	
}

void	FragTrap::highFiveGuys( void )
{

	std::cout << "Do you wanna high five w/ me ????? pls" << std::endl;

}

FragTrap &	ClapTrap::operator=(const FragTrap &src)
{

	std::cout << "Copy assignement operator called !" << std::endl;
	return (*this);

}