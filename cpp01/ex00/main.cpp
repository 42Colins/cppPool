/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:36:43 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/23 17:43:17 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newZombie.hpp"

int main() 
{
    
    Zombie *John = newZombie("John");
    randomChump("Jane");
    John->annouce();
    
    delete John;
    
}