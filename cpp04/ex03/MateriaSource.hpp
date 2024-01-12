/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:57:32 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/12 13:44:21 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "Headers.h"

class AMateria;

class MateriaSource : public IMateriaSource
{
	private :
			AMateria *_spellbook[4];
			int		 _index;
			
	public :
			MateriaSource( void );
			MateriaSource( const MateriaSource &toCopy );
			~MateriaSource( void );
			MateriaSource & operator=( const MateriaSource & );
			void	learnMateria( AMateria* );
			AMateria* createMateria( std::string const & type );
};

#endif