/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:57:44 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/09 11:25:31 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"

AMateria::AMateria( void )
{

	std::cout << "Generating a new Materia" << std::endl;

}

AMateria::AMateria( const AMateria &toCopy )
{

	std::cout << "Copying a Materia" << std::endl;
	*this = toCopy;

}

AMateria::AMateria( const std::string & type)
{

	this->_type = type;
	
}

AMateria::~AMateria( void )
{

	std::cout << "Sorry, your Materia broke" << std::endl;

}

AMateria & AMateria::operator=( const AMateria &src )
{

	this->_type = src._type;
	return (*this);

}

const std::string	&AMateria::getType( ) const
{

	return (this->_type);

}

void	AMateria::use(ICharacter& target)
{

	if (this->_type == "ice")
		std::cout << "* shhots an ice bolt at " << target.getName() << " *" << std::endl; 
	else if (this->_type == "cure")
		std::cout << "* heals " << target.getName() << " 's wounds *" << std::endl;
	else
		std::cout << "Nothing seems to happen when targeting " << target.getName() << std::endl;
	
}