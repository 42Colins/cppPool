/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:55:02 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/11 15:04:49 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main (void)
{

	ScavTrap scavvy("Scavvy");
	scavvy.attack("clappy");
	scavvy.guardGate();
	scavvy.beRepaired(10);
	scavvy.takeDamage(15);

}