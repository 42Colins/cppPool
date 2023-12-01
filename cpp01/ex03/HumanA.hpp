/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:36:51 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/24 17:08:51 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{

	private	:
				std::string	_name;
				Weapon		&_type;

	public	:
				// HumanA ( void );
				HumanA ( std::string name, Weapon &newWeapon );
				~HumanA ( void );

				void	setWeapon( Weapon &newWeapon );
				void	attack( void );

};

#endif