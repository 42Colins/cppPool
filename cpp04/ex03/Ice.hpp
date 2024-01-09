/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:37:06 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/09 11:21:58 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "Headers.h"

class Ice : public AMateria
{
	public 	:
		Ice( void );
		~Ice( void );
		Ice( const Ice &toCopy );
		Ice & operator=( const Ice & );
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif