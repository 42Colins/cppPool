/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:33:03 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/18 13:35:39 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

Dog::Dog( void )
{

	std::cout << "Creating Dog" << std::endl;

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

	this->_type = src.getType();
	return(*this);

}

void	Dog::makeSound( void ) const
{

	std::cout << "Doggo says : BARK BARK" << std::endl;

}