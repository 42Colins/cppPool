/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:49:46 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/24 17:11:14 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// HumanA::HumanA ( void ) : _type()
// {

// 	std::cout << "Default constructor for HumanA called" << std::endl;

// }

HumanA::HumanA ( std::string name, Weapon &newWeapon ) : _type(newWeapon)
{

	std::cout << "Constructor with parameters for HumanA called" << std::endl;
	this->_name = name;
	// this->_type = newWeapon;

}

HumanA::~HumanA ( void )
{

	std::cout << "Destructor for HumanA called" << std::endl;

}

void	HumanA::setWeapon( Weapon &newWeapon )
{

	this->_type = newWeapon;

}

void	HumanA::attack( void )
{

	std::cout << this->_name << " attacks with " << *this->_type.getType() << std::endl;

}