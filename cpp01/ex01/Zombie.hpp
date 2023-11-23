/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:59:28 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/23 19:39:21 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie 
{
	private :
		std::string name;

	public :

		Zombie( void );
		Zombie(std::string name);
		~Zombie( void );
		
		void setName( std::string name );
		void announce( void );
};

Zombie	*zombieHorde( int N, std::string name );

#endif