/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:57:45 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/19 13:14:44 by cprojean         ###   ########.fr       */
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

				std::string	getType() const;
				virtual void	makeSound( void ) const;
};

#endif