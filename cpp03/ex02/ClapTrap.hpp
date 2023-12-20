/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:39:26 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/20 12:43:28 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{

	protected :
			int	_hp;
			int	_ad;
			int	_mana;
			std::string _name;
	
	public :
			ClapTrap( void );
			ClapTrap( std::string name );
			~ClapTrap( void );
			ClapTrap( const ClapTrap &toCopy );
			ClapTrap &	operator=(const ClapTrap &src);
			void	attack( const std::string &target);
			void	takeDamage(unsigned int amout);
			void	beRepaired(unsigned int amout);
			void	open( void );
};


#endif