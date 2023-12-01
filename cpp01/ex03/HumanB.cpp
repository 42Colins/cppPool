/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:22:06 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/24 17:13:36 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( void )
{

	std::cout << "Default constructor for HumanB has been called" << std::endl;

}

HumanB::HumanB( std::string name )
{

	std::cout << "Default constructor for HumanB has been called" << std::endl;
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

	// if (!_name)
	// {
	// 	std::cout << this->_name << " can't attack without a weapon !" << std::endl;
	// }
	std::cout << this->_name << " attacks with " << *this->_type->getType() << std::endl;

}