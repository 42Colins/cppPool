/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:44:04 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/09 16:41:02 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"

Ice::Ice( void )
{
	
	// std::cout << "Ice spell created !" << std::endl;
	this->_type = "ice";
	
}

Ice::Ice( const Ice &toCopy )
{

	*this = toCopy;

}

Ice::~Ice( void )
{
	
	// std::cout << "Ice spell broke on the floor !" << std::endl;
	return ;
	
	
}

Ice & Ice::operator=( const Ice &src )
{

	this->_type = src._type;
	return (*this);

}

void Ice::use( ICharacter &name )
{

	std::cout << "* shoots an ice bolt at " << name.getName() << " *" << std::endl;

}

AMateria *Ice::clone() const
{

	return (new Ice());

}