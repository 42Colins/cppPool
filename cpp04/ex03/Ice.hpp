/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:37:06 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/08 15:50:18 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "Headers.h"

class Ice : public AMateria
{
	private	 :
	
	public 	:
		Ice( void );
		~Ice( void );
		Ice( const Ice &toCopy );
		Ice & operator=( const Ice & );
		AMateria & operator=( const AMateria & );
		void use(ICharacter &target);
};

#endif