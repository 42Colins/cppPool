/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:58:03 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/12 16:19:17 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

Animal::Animal( void )
{
	
	std::cout << "Animal created" << std::endl;
	this->_type = "Animal";

}

Animal::Animal( const Animal &toCopy )
{

	*this = toCopy;
	return ;

}

Animal::~Animal( void )
{

	std::cout << "Animal destroyed" << std::endl;

}

void	Animal::makeSound( void ) const
{

	std::cout << "Animal says : wtf ?" << std::endl;

}

std::string	Animal::getType( void ) const
{
	
	std::string returned = this->_type;
	return (returned);

}

Animal &	Animal::operator=(const Animal &src )
{

	if (this == &src)
		return (*this);
	this->_type = src.getType();
	return (*this);

}