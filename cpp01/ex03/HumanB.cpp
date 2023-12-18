/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:22:06 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/18 01:55:46 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( void )
{

	std::cout << "Default constructor for HumanB has been called" << std::endl;
	this->_type = NULL;

}

HumanB::HumanB( std::string name )
{

	std::cout << "Default constructor for HumanB has been called" << std::endl;
	this->_type = NULL;
	this->_name = name;

}

HumanB::~HumanB ( void )
{

	std::cout << "Destructor for HumanB has been called" << std::endl;

}

void	HumanB::setWeapon( Weapon &newWeapon )
{

	this->_type = &newWeapon;

}

void	HumanB::attack( void )
{

	if (!_type)
	{
		std::cout << this->_name << " can't attack without a weapon !" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks with " << this->_type->getType() << std::endl;

}