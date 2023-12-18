/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:37:25 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/18 01:50:00 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string.h>

class Harl
{
	private :
				void	debug( void );
				void	info( void );
				void	warning( void );
				void	error( void );

	public :
				Harl( void );
				~Harl( void );
				void complain ( std::string level );
};

#endif