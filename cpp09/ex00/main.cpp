/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:44:52 by cprojean          #+#    #+#             */
/*   Updated: 2024/05/22 17:55:09 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error, could not open this file" << std::endl;
		return (-1);
	}
	(void) argv;
	std::fstream	dataBase;
	std::fstream	input;
	std::map<std::string, float> data; 
	
	dataBase.open("data.csv", std::fstream::in);
	if (dataBase.fail())
	{
		std::cout << "Problem opening the database" << std::endl;
		return 1;
	}
	input.open(argv[1], std::fstream::in);
	if (input.fail())
	{
		std::cout << "Problem while opening the input file" << std::endl;
		return 1;
	}
	data = filldata(data, dataBase);
	if (exchange(data, input) == 1)
		return (1);
		
	// printMap(data);
	return 0;
}