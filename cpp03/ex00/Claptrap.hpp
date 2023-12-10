/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:39:26 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/10 17:57:54 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class Claptrap
{

	private :
			int	_hp;
			int	_ad;
			int	_mana;
	
	public :
			Claptrap( void );
			~Claptrap( void );
			void	attack( const std::string &target);
			void	takeDamage(unsigned int amout);
			void	beRepaired(unsigned int amout);
			void	open( void );
};


#endif