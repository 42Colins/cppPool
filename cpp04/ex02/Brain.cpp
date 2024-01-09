/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:26:10 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/19 13:42:00 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

Brain::Brain( void )
{
	
	std::cout << "My man is braining !" << std::endl;

}

Brain::Brain( const Brain &toCopy )
{

	*this = toCopy;

}

Brain::~Brain( void )
{

	std::cout << "My man is now braindead :/" << std::endl;

}

Brain	& Brain::operator=( const Brain &src )
{
	
	for(int i = 0; i < 100; i++)
	{
		this->_ideas[i] = src._ideas[i];
	}
	return (*this);
	
}