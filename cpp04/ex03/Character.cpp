/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:24:55 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/05 18:20:39 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"

Character::Character( void )
{
	
	std::cout << "New character appears !" << std::endl;
	this->_name = "John Doe";
	this->_idx = 0;
	
}

Character::Character( std::string name )
{
	
	std::cout << "New character appears !" << std::endl;
	this->_name = name;
	this->_idx = 0;
	
}

Character::Character( const Character &toCopy )
{
	
	std::cout << "New character appears !" << std::endl;
	this->_idx = 0;
	*this = toCopy;
	
}

Character & Character::operator=( const Character &src )
{
	
	this->_name = src.getName();
	this->_idx = src._idx;
	*this->_inventory = *src._inventory;
	return (*this);

}

Character::~Character( void )
{
	
	std::cout << this->_name << " died ..." << std::endl;
	
}

std::string const & Character::getName( void ) const
{
	
	return (this->_name);

}

void	Character::equip(AMateria* m)
{

	this->_idx += 1;
	this->_inventory[_idx + 1] = m;

}

void	Character::unequip( int idx )
{

	int index = idx + 1;
	while (index < 4)
	{
		this->_inventory[index] = NULL;
		this->_inventory[index] = this->_inventory[index + 1];
		index++;
	}

}

void	Character::use( int idx, ICharacter& target )
{

	this->_inventory[idx]->use(target);

}
