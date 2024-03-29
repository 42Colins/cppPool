/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:43:48 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/04 14:19:07 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char **argv)
{

	if (argc != 4)
	{
		std::cout << "Error, must be 3 args !" << std::endl;
		return(-1);
	}
	std::string verif = argv[1];
	std::string verif2 = argv[2];
	std::string verif3 = argv[3];
	if (verif.empty() || verif2.empty() || verif3.empty())
	{
		std::cout << "Bad input !" << std::endl;
		return (-1);
	}

	Sed	toDo(argv);

	toDo.sed_this();
	return (0);

}

