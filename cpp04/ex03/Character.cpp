/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:24:55 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/12 16:26:23 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"

Character::Character( void )
{
	
	// std::cout << "New character appears !" << std::endl;
	this->_name = "John Doe";
	this->_idx = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	
}

Character::Character( std::string name )
{
	
	// std::cout << "New character appears !" << std::endl;
	this->_name = name;
	this->_idx = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	
}

Character::Character( const Character &toCopy )
{
	
	// std::cout << "New character appears !" << std::endl;
	this->_idx = 0;
	*this = toCopy;
	
}

Character & Character::operator=( const Character &src )
{
	
	if (this == &src)
		return (*this);
	this->_name = src.getName();
	this->_idx = src._idx;
	*this->_inventory = *src._inventory;
	return (*this);

}

Character::~Character( void )
{
	
	for(int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
	}
	// std::cout << this->_name << " died ..." << std::endl;
	
}

std::string const & Character::getName( void ) const
{
	
	return (this->_name);

}

void	Character::equip(AMateria* m)
{

	if (_idx < 3)
	{
		this->_inventory[_idx] = m;
		_idx+=1;
		// this->_inventory[_idx + 1]->_type = m->getType();
	}
	else
		std::cout << "I can't have more than 4 materias bruv" << std::endl;

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

	if (idx >= 0 && idx < 4)
	{
		this->_inventory[idx]->use(target);
	}
	else
		return ;

}
