/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:33:12 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/19 13:16:25 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Polymorphism.h"

class Dog : public Animal
{
	private :
			Brain *_ideas;
	public :
			Dog( void );
			~Dog( void );
			Dog( const Dog &toCopy );
			Dog & operator=(const Dog &);
			void	makeSound( void ) const;

};

#endif