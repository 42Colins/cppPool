/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:50:50 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/18 13:51:10 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

WrongCat::WrongCat( void )
{

	std::cout << "Prossessing WrongCat" << std::endl;
	
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

	this->_type = src.getType();
	return (*this);

}

void	WrongCat::makeSound( void ) const
{

	std::cout << "WrongCat says : MEOW MEOW" << std::endl;

}