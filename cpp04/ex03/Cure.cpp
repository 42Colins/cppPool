/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:48:39 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/09 16:40:45 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"

Cure::Cure( void )
{
	
	// std::cout << "Cure spell created !" << std::endl;
	this->_type = "cure";
	
}

Cure::Cure( const Cure &toCopy )
{

	*this = toCopy;

}

Cure::~Cure( void )
{
	
	// std::cout << "Cure spell broke on the floor !" << std::endl;
	return ;
	
}

Cure & Cure::operator=( const Cure &src )
{

	this->_type = src._type;
	return (*this);

}

void Cure::use( ICharacter &name )
{

	std::cout << "* heals " << name.getName() << "'s wounds *" << std::endl;

}

AMateria *Cure::clone() const
{

	return (new Cure());

}