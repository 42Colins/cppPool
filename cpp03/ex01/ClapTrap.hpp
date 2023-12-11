/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:39:26 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/11 16:18:15 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{

	protected :
			std::string	_name;
			int	_hp;
			int	_ad;
			int	_mana;
	
	public :
			ClapTrap( void );
			ClapTrap( std::string Name );
			~ClapTrap( void );
			void	attack( const std::string &target);
			void	takeDamage(unsigned int amout);
			void	beRepaired(unsigned int amout);
			void	open( void );
};


#endif