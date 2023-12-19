/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:53:22 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/18 13:53:29 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

WrongAnimal::WrongAnimal( void )
{
	
	std::cout << "WrongAnimal created" << std::endl;

}

WrongAnimal::WrongAnimal( const WrongAnimal &toCopy )
{

	*this = toCopy;
	return ;

}

WrongAnimal::~WrongAnimal( void )
{

	std::cout << "WrongAnimal destroyed" << std::endl;

}

void	WrongAnimal::makeSound( void ) const
{

	std::cout << "WrongAnimal says : wtf ?" << std::endl;

}

std::string	WrongAnimal::getType( void ) const
{
	
	return (this->_type);

}

WrongAnimal &	WrongAnimal::operator=(const WrongAnimal &src )
{

	this->_type = src.getType();
	return (*this);

}