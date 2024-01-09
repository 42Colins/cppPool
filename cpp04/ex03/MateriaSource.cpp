/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:01:41 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/09 11:26:16 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"

MateriaSource::MateriaSource( void )
{
	
	std::cout << "New MateriaSource !" << std::endl;
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
	
	std::cout << "The Materia fell on the floor and broke ;/" << std::endl;
	
}


MateriaSource & MateriaSource::operator=( const MateriaSource &src )
{
		
	for(int i = 0; i < 4; i++)
	{
		this->_spellbook[i] = src._spellbook[i]->clone();
	}
	return (*this);

}

void	MateriaSource::learnMateria( AMateria* spell )
{

	if (this->_index <= 2)
	{
		this->_spellbook[this->_index] = spell;
		this->_index += 1;
	}
	else
		std::cout << "Cannot learn anymore spells sadly" << std::endl;

}

AMateria *MateriaSource::createMateria( std::string const &materia )
{

	const std::string ice = "Ice";
	const std::string cure = "Cure";
	AMateria *returned;

	if (materia == ice)
		returned = new Ice();
	else if (materia == cure)
		returned = new Cure();
	else
		returned = NULL;
	return (returned);

}