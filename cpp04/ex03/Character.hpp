/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:56:20 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/05 18:06:07 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "Headers.h"

class Character : public ICharacter
{
	private :
			std::string _name;
			AMateria *_inventory[4];
			int _idx;
	public :
			Character( void );
			Character( std::string name );
			~Character( void );
			Character( const Character &toCopy );
			Character & operator=( const Character & );
			std::string const & getName( void ) const;
			void equip( AMateria* m );
			void unequip( int idx );
			void use( int idx, ICharacter& target );
};

#endif