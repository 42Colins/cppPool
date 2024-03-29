/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:23:42 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/12 13:38:26 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Polymorphism.h"

class Cat : public Animal
{
	private :
			Brain *_ideas;
	public :
			Cat( void );
			Cat( const Cat &toCopy );
			virtual ~Cat( void );
			Cat & operator=( const Cat & );
			void	makeSound( void ) const ;
			std::string	getType( void ) const;
};


#endif