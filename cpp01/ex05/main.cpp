/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:48:37 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/04 13:49:41 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv )
{
	if (argc != 2)
	{
		std::cout << "Must enter Debug, Info, Warning or Error !" << std::endl;
		return (0);
	}

	Harl ajakubcz;
	std::string level = argv[1];
	ajakubcz.complain( level );
	return (0);

}