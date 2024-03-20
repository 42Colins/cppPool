/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:41:04 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/20 14:37:42 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <locale> 
#include <stdlib.h> 

std::map<std::string, double> filldata(std::map<std::string, double> data, std::fstream &dataBase);
void printMap(std::map<std::string, double> data);
int	checkDate(std::string str);
int	exchange(std::map<std::string, double> data, std::fstream &input);

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
	// printMap(data);
	if (exchange(data, input) == 1)
		return (1);
	return 0;
}

int	exchange(std::map<std::string, double> data, std::fstream &input)
{
	int index = 0;
	std::string str;
	(void) data;
	while (!input.eof())
	{
		std::getline(input, str);
		std::cout << str << std::endl;
		if (index == 0)
		{
			if (str == "date | value") 
			{
				index++;
				continue ;
			}
			std::cout << "invalid format for input.txt : " << str <<  std::endl;
			return (1);
		}
		if (checkDate(str) == 1)
			return (1);
		index++;
	}
	return (0);
}

int	checkDate(std::string str)
{
	std::locale loc;
	const char *newstr = str.substr(0, 10).c_str();
	std::string laststr = str.substr(11, 14);
	int	i = 0;
	while (i < 4)
	{
		if(isdigit(str[i], loc))
			continue ;
		else
		{
			std::cout << "Error : bad input => " << newstr << std::endl;
			return (1);
		}
		i++;
	}
	if (str[i] == '-')
	{
		i++;
	}
	else
	{
		std::cout << "Error : bad input => " << newstr << std::endl;
		return (1);
	}
	while (i < 7)
	{
		if(isdigit(str[i], loc))
			continue ;
		else
		{
			std::cout << "Error : bad input => " << newstr << std::endl;
			return (1);
		}
		i++;
	}
	if (str[i] == '-')
	{
		i++;
	}
	else
	{
		std::cout << "Error : bad input => " << newstr << std::endl;
		return (1);
	}
	while (i < 10)
	{
		if(isdigit(str[i], loc))
			continue ;
		else
		{
			std::cout << "Error : bad input => " << newstr << std::endl;
			return (1);
		}
		i++;
	}
	if (laststr == " | ")
	{
		std::cout << "Error : bad input => " << laststr << std::endl;
		return (0);
	}
	else
		return (1);
}

std::map<std::string, double> filldata(std::map<std::string, double> data, std::fstream &dataBase)
{
	std::string str;
	int index = 0;
	while (!dataBase.eof())
	{
		std::getline(dataBase, str);
		if (index != 0)
			data.insert(std::pair<std::string, double>(str.substr(0, 10), strtod(str.substr(11).c_str(), NULL)));
		index++;
	}
	return (data);
}

void printMap(std::map<std::string, double> data)
{
	for (std::map<std::string, double>::iterator it = data.begin(); it != data.end(); it++)
		std::cout << it->first << " - " << it->second << std::setprecision(7) << std::endl;
}