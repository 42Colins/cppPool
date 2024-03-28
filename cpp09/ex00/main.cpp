/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:44:52 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/28 13:45:06 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	std::fstream	dataBase;
	std::fstream	input;
	std::map<std::string, double> data; 
	
	dataBase.open("data.csv", std::fstream::in);
	if (dataBase.fail())
	{
		std::cout << "Problem opening the database" << std::endl;
		return 1;
	}
	input.open("input.txt", std::fstream::in);
	if (input.fail())
	{
		std::cout << "Problem while opening the input file" << std::endl;
		return 1;
	}
	data = filldata(data, dataBase);
	if (exchange(data, input) == 1)
		return (1);
	return 0;
}