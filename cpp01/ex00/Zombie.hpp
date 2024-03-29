/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:59:28 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/24 10:56:38 by cprojean         ###   ########.fr       */
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
	    void annouce( void );
};

#endif