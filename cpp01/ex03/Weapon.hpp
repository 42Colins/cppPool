/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:16:29 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/18 01:55:23 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{

	private	:
				std::string	_type;

	public	:
				Weapon( void );
				Weapon( std::string );
				~Weapon( void );

				const std::string	&getType( void );
				void				setType( std::string newType );

};

#endif