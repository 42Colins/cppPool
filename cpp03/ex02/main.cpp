/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:55:02 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/11 16:12:01 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main (void)
{

	FragTrap fraggy("Fraggy");
	fraggy.attack("clappy");
	fraggy.highFiveGuys();
	fraggy.beRepaired(10);
	fraggy.takeDamage(15);

}