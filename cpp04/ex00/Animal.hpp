/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:57:45 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/12 16:07:13 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "Polymorphism.h"

class Animal 
{
	protected :
				std::string	_type;

	public :
				Animal( void );
				Animal( const Animal &toCopy );
				virtual ~Animal( void );
				Animal & operator=( const Animal & );

				std::string	getType( void ) const;
				virtual void	makeSound( void ) const;
};

#endif