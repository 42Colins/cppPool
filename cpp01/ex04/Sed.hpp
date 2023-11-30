/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:41:54 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/30 17:56:21 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>


class Sed
{
	private	:
			std::string	_fileName;
			std::string	_toFind;
			std::string	_toReplace;
			std::string	_string;

	public	:
			Sed  ( char **argv );
			~Sed ( void );

			void	sed_this( void );
};

std::string	findAndReplace( std::string returned, std::string find, std::string toFind, std::string toReplace);

#endif