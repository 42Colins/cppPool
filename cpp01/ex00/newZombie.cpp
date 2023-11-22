/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:35:58 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/22 18:36:20 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newZombie.hpp"

Zombie* newZombie( std::string name )
{
    
    Zombie *newMate = new Zombie;
    newMate->setName(name);
    
    return (newMate);

}