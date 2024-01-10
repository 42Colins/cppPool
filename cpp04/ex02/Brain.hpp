/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:22:35 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/10 17:36:03 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Polymorphism.h"

class Brain
{
	private	:
				std::string	_ideas[100];
	public	:
				Brain( void );
				Brain( const Brain &toCopy );
				~Brain( void );
				Brain & operator=( const Brain & );
};

#endif