/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:39:26 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/11 16:43:36 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{

	private :
			int	_hp;
			int	_ad;
			int	_mana;
			std::string _name;
	
	public :
			ClapTrap( void );
			ClapTrap( std::string name );
			~ClapTrap( void );
			ClapTrap( const ClapTrap &toCopy );
			ClapTrap &	operator=(const ClapTrap &);
			void	attack( const std::string &target);
			void	takeDamage(unsigned int amout);
			void	beRepaired(unsigned int amout);
			void	open( void );
};


#endif