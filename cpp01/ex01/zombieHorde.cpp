/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:47:01 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/23 19:39:42 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{

	Zombie *zombArr;

	zombArr = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombArr[i].setName(name);
		zombArr[i].announce();
	}
	return (zombArr);

}