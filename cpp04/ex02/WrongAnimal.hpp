/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:52:53 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/18 13:53:38 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include "Polymorphism.h"

class WrongAnimal 
{
	protected :
				std::string	_type;

	public :
				WrongAnimal( void );
				WrongAnimal( const WrongAnimal &toCopy );
				~WrongAnimal( void );
				WrongAnimal & operator=( const WrongAnimal & );

				std::string	getType() const;
				void	makeSound( void ) const;
};

#endif