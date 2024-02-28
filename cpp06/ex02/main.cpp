/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:56:57 by cprojean          #+#    #+#             */
/*   Updated: 2024/02/28 18:16:46 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(int argc, char **argv)
{
	(void) argv;
	if (argc != 2)
	{
		std::cout << "Wrong arguments !" << std::endl;
		return 1;
	}
	else
	{
		Base *newBase = generate();
		identify(newBase);
	}
	return 0;
}