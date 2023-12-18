/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:02:33 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/18 01:31:11 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{

	this->name = "John Doe";
	std::cout << "Constructor default for Zombie called" << std::endl << std::endl;

}

Zombie::~Zombie( void )
{

	std::cout << std::endl << "Destructor for Zombie called" << std::endl;

}

void    Zombie::announce ( void )
{

	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl << std::endl;

}

void    Zombie::setName( std::string name )
{

	this->name = name;

}
