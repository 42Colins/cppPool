/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:28:51 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/20 12:44:01 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

	private :
			
	public :
			ScavTrap( void );
			ScavTrap( std::string Name );
			ScavTrap( const ScavTrap &toCopy );
			ScavTrap &	operator=(const ScavTrap &);
			~ScavTrap( void );
			void	attack( const std::string &target);
			void	guardGate();
};

#endif