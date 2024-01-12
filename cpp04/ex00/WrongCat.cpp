/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:50:50 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/12 16:20:19 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

WrongCat::WrongCat( void )
{

	std::cout << "Prossessing WrongCat" << std::endl;
	this->_type = "WrongCat";
	
	
}

WrongCat::WrongCat( const WrongCat &toCopy )
{

	*this = toCopy;
	return ;

}

WrongCat::~WrongCat( void )
{

	std::cout << "Killing WrongCat" << std::endl;

}


WrongCat &	WrongCat::operator=( const WrongCat &src )
{

	if (this == &src)
		return (*this);
	this->_type = src.getType();
	return (*this);

}

void	WrongCat::makeSound( void ) const
{

	std::cout << "WrongCat says : MEOW MEOW" << std::endl;

}

std::string WrongCat::getType( void ) const
{

	std::string returned = this->_type;
	return (returned);

}
