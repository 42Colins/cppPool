/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:48:39 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/08 15:49:14 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"

Cure::Cure( void )
{
	
	std::cout << "Cure spell created !" << std::endl;
	
}

Cure::Cure( const Cure &toCopy )
{

	*this = toCopy;

}

Cure::~Cure( void )
{
	
	std::cout << "Cure spell broke on the floor !" << std::endl;
	
}

Cure & Cure::operator=( const Cure &src )
{

	this->_type = src._type;
	return (*this);

}

void Cure::use( ICharacter &name )
{

	std::cout << "* Healing " << name.getName() << " *" << std::endl;

}