/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:46:59 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/23 19:15:40 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() 
{

	Zombie *zombArr;
	zombArr = zombieHorde(10, "Zombar");

	delete[] zombArr;

}