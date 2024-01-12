/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:33:03 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/12 16:19:39 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

Dog::Dog( void )
{

	std::cout << "Creating Dog" << std::endl;
	this->_type = "Dog";

}

Dog::Dog( const Dog &toCopy )
{

	*this = toCopy;
	return;

}

Dog::~Dog( void )
{

	std::cout << "Doggo dying.." << std::endl;
	
}

Dog & Dog::operator=(const Dog &src )
{

	if (this == &src)
		return (*this);
	this->_type = src.getType();
	return(*this);

}

void	Dog::makeSound( void ) const
{

	std::cout << "Doggo says : BARK BARK" << std::endl;

}

std::string	Dog::getType( void ) const
{
	
	std::string returned = this->_type;
	return (returned);

}