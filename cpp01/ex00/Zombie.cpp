/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:02:33 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/18 01:31:17 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	
	this->name = "John Doe";
	std::cout << "Constructor default for Zombie called" << std::endl << std::endl;

}

Zombie::Zombie( std::string name)
{
	
	this->name = name;
	std::cout << "Constructor parameter for Zombie called" << std::endl << std::endl;

}

Zombie::~Zombie( void )
{

	std::cout << std::endl << "Destructor for " << this->name << " called" << std::endl;

}

void    Zombie::annouce ( void )
{

	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;

}

void    Zombie::setName( std::string name )
{
	
	this->name = name;   

}