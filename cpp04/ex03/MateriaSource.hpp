/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:57:32 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/08 18:21:03 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "Headers.h"

class MateriaSource : public IMateriaSource
{
	private :
			AMateria spellbook[4];
	public :
			MateriaSource( void );
			MateriaSource( const MateriaSource &toCopy );
			~MateriaSource( void );
			MateriaSource & operator=( const MateriaSource & );
			void	learnMateria( AMateria* );
			AMateria* createMateria( std::string const & type );	
};

#endif