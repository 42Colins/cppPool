/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:56:57 by cprojean          #+#    #+#             */
/*   Updated: 2024/02/28 16:49:12 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int argc, char **argv)
{
	(void) argv;
	if (argc != 2)
	{
		std::cout << "Wrong arguments !" << std::endl;
		return 1;
	}
	Data *value = new Data;
	value->str = argv[2];
	std::cout << value << std::endl;
	Data *newVal = Serializer::deserialize(Serializer::serialize(value));
	std::cout << newVal << std::endl;
	delete value;
	return 0;
}