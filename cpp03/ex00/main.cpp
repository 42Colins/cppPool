/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:55:02 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/11 16:21:17 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main (void)
{

	ClapTrap clappy("Clappy");
	clappy.attack("my grandmother");
	clappy.takeDamage(5);
	clappy.beRepaired(4);
}