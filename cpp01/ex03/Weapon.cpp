/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:19:13 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/18 01:55:59 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void )
{
	std::cout << "Default constructor for Weapon called" << std::endl;
}

Weapon::Weapon( std::string type )
{

	this->_type = type;
	std::cout << "Parameter constructor for Weapon called" << std::endl << std::endl;

}

Weapon::~Weapon( void )
{

	std::cout << "Destructor for Weapon called" << std::endl;

}

const std::string	&Weapon::getType( void )
{

	return (this->_type);

}

void	Weapon::setType( std::string newType )
{

	this->_type = newType;

}