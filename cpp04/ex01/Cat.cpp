/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:22:37 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/19 14:42:09 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

Cat::Cat( void )
{

	this->_ideas = new Brain();
	std::cout << "Prossessing Cat" << std::endl;
	
}

Cat::Cat( const Cat &toCopy )
{

	*this = toCopy;
	return ;

}

Cat::~Cat( void )
{
	delete this->_ideas;
	std::cout << "Killing Cat" << std::endl;

}


Cat &	Cat::operator=( const Cat &src )
{
	
	this->_type = src.getType();
	return (*this);

}

void	Cat::makeSound( void ) const
{

	std::cout << "Cat says : MEOW MEOW" << std::endl;

}