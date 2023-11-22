/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:36:43 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/22 18:53:28 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newZombie.hpp"

int main() 
{
    
    Zombie *John = newZombie("John");
    randomChump("islem");
    John->annouce();
    
    delete John;
    
}