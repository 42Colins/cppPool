/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:19:41 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/24 17:13:17 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB 
{
	private	:
				std::string	_name;
				Weapon	*_type;

	public	:
				HumanB ( void );
				HumanB ( std::string name );
				~HumanB ( void );

				void	setWeapon( Weapon &newWeapon );
				void	attack( void );
};

#endif