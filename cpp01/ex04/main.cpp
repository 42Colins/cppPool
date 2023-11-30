/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:43:48 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/30 17:26:36 by cprojean         ###   ########.fr       */
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
	Sed	toDo(argv);

	toDo.sed_this();
	return (0);

}

