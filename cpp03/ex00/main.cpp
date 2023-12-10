/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:55:02 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/10 17:59:23 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

int	main (void)
{

	Claptrap clappy;
	clappy.attack("my grandmother");
	clappy.takeDamage(5);
	clappy.beRepaired(4);
}