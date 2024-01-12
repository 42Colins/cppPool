/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:51:29 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/12 13:35:51 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "Polymorphism.h"

class WrongCat : public WrongAnimal
{
	private :
	
	public :
			WrongCat( void );
			WrongCat( const WrongCat &toCopy );
			~WrongCat( void );
			WrongCat & operator=( const WrongCat & );
			void	makeSound( void ) const ;
			std::string	getType( void ) const;
};


#endif