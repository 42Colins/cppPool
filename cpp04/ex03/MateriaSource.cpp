/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:01:41 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/19 13:16:03 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"

MateriaSource::MateriaSource( void )
{
	
	// std::cout << "New MateriaSource !" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_spellbook[i] = NULL;
	this->_index = 0;

}

MateriaSource::MateriaSource( const MateriaSource &toCopy )
{
	
	*this = toCopy;

}

MateriaSource::~MateriaSource( void )
{
	
	for (int i = 0; i < 4; i++)
	{
		if (this->_spellbook[i])
			delete this->_spellbook[i];
	}
	// std::cout << "The Materia fell on the floor and broke ;/" << std::endl;
	
}


MateriaSource & MateriaSource::operator=( const MateriaSource &src )
{
	
	if (this == &src)
		return (*this);	
	for(int i = 0; i < 4; i++)
	{
		this->_spellbook[i] = src._spellbook[i]->clone();
	}
	return (*this);

}

void	MateriaSource::learnMateria( AMateria* spell )
{

	if (this->_index < 4)
	{
		this->_spellbook[this->_index] = spell;
		this->_index += 1;
	}
	else
		std::cout << "Cannot learn anymore spells" << std::endl;

}

AMateria *MateriaSource::createMateria( std::string const &materia )
{

	const std::string ice = "ice";
	const std::string cure = "cure";
	AMateria *returned = NULL;
	int isOkay = 0;

	for (int i = 0; i < this->_index; i++)
	{
		if (_spellbook[i]->getType() == materia)
		{
			isOkay = 1;
			break ;
		}
	}
	if (isOkay == 1)
	{
		if (materia == ice)
			returned = new Ice();
		else if (materia == cure)
			returned = new Cure();
	}
	else
		std::cout << "Failed to create this Materia, it doesn't exist" << std::endl;
	return (returned);

}
