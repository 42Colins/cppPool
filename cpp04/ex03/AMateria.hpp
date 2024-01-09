/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:18:26 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/09 10:39:34 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "Headers.h"

class ICharacter;

class AMateria
{
	protected:
			std::string	_type;
	
	public:
			AMateria( void );
			AMateria( const AMateria &toCopy);
			AMateria(std::string const & type);
			~AMateria( void );
			AMateria & operator=( const AMateria & );
			std::string const & getType() const; //Returns the materia type
			virtual AMateria* clone() const = 0;
			virtual void use(ICharacter& target);
};

#endif