/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:37:25 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/04 13:48:08 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

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
				void get_debug( void );
				void get_info( void );
				void get_warning( void );
				void get_error( void );
};


#endif