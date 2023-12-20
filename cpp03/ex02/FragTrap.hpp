/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:59:56 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/20 12:45:23 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <ScavTrap.hpp>

class FragTrap : public ClapTrap
{
	private :

	public :
			FragTrap( void );
			FragTrap( std::string name );
			FragTrap( const FragTrap &toCopy );
			FragTrap &	operator=(const FragTrap &);
			~FragTrap( void );
			void	highFiveGuys( void );
};

#endif