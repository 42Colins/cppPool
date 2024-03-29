/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:24:10 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/09 11:20:03 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "Headers.h"

class Cure : public AMateria
{
	private	 :
	
	public 	:
				Cure( void );
				~Cure( void );
				Cure( const Cure &toCopy );
				Cure & operator=( const Cure & );
				AMateria *clone() const;
				void use(ICharacter &target);
};

#endif