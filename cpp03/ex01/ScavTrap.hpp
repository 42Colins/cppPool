/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:28:51 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/11 16:18:56 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

	private :
			// std::string	_name;
			
	public :
			ScavTrap( void );
			ScavTrap( std::string Name );
			~ScavTrap( void );
			void	attack( const std::string &target);
			void	guardGate();
};

#endif