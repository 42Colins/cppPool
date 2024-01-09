/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:01:41 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/08 16:53:41 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"

MateriaSource::MateriaSource( void )
{
	
	std::cout << "New MateriaSource !" << std::endl;

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
		
	*this ;
	return (*this);

}

void	MateriaSource::learnMateria( AMateria* )
{

	

}
