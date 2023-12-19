/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:23:42 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/18 13:22:28 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Polymorphism.h"

class Cat : public Animal
{
	private :
	
	public :
			Cat( void );
			Cat( const Cat &toCopy );
			~Cat( void );
			Cat & operator=( const Cat & );
			void	makeSound( void ) const ;
};


#endif