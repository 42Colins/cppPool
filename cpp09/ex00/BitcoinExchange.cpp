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
#include "BitcoinExchange.hpp"

bool	isLeapYear(int year);
std::map<std::string, double> filldata(std::map<std::string, double> data, std::fstream &dataBase);
void printMap(std::map<std::string, double> data);
int	checkDate(std::string str);
int	exchange(std::map<std::string, double> data, std::fstream &input);
void	findInData(std::string str, std::map<std::string, double> data);
std::string lowerDate(std::string str);

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

int	exchange(std::map<std::string, double> data, std::fstream &input)
{
	int index = 0;
	std::string str;
	(void) data;
	while (!input.eof())
	{
		std::getline(input, str);
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
		{
			index++;
			continue ;
		}
		findInData(str, data);
		index++;
	}
	return (0);
}

void	findInData(std::string str, std::map<std::string, double> data)
{
	std::string date = str.substr(0, 10);
	long err = strtol(str.substr(13, str.size()).c_str(), NULL, 10);
	(void) err;
	if (err < 0.0 || err > 1000.0)
	{
		std::cout << "Error : " << err << " the value should be in the range 0-1000" << std::endl;
		return ;
	}
	double	value = strtod(str.substr(13, str.size()).c_str(), NULL);
	if (value < 0.0 || value > 1000.0)
	{
		std::cout << "Error : " << value << " the value should be in the range 0-1000" << std::endl;
		return ;
	}
	double tmp;
	tmp = data[str.substr(0, 10)];
	if (!tmp)
	{
		str = lowerDate(str);
		findInData(str, data);
		return ;
	}
	std::cout << date << " => " << value << " <==> " << tmp * value << std::endl;
}

std::string lowerDate(std::string str)
{
	std::string end = str.substr(10, str.size());
	int	year = atoi(str.substr(0, 4).c_str());
	int	month = atoi(str.substr(5, 7).c_str());
	int	day = atoi(str.substr(8, 10).c_str());

	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day == 1)
	{
		if (month == 1)
		{
			year = year - 1;
			month = 12;
			day = 31;
			goto end;
		}
		if (month == 3)
		{
			if (isLeapYear(year))
			{
				day = 29;
				month = 2;
				goto end;
			}
		}
		month = month - 1;
		day = months[month - 1];
	}
	else
		day = day - 1;
	
	end :
	std::string y = to_string(year);
	std::string m = to_string(month);
	std::string d = to_string(day);
	if (month < 10)
		m = "0" + m;
	if (day < 10)
		d = "0" + d;
	std::string returned = y + "-" + m + "-" + d + end;
	return (returned);
}

bool	isLeapYear(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0))
		return (true);
	else if (year % 400 == 0)
		return (true);
	return (false);
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

int	checkDate(std::string str)
{
	std::locale loc;
	if (str.size() < 14)
	{
		std::cout << "Error : bad input => " << str << std::endl;
		return (1);
	}
	std::string newstr = str.substr(0, 10);
	std::string laststr = str.substr(11, 14);
	int	i = 0;
	while (i < 4)
	{
		if(isdigit(str[i], loc))
		{
			i++;
			continue ;
		}
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
		{
			i++;
			continue ;
		}
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
		{
			i++;
			continue ;
		}
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
		return (1);
	}
	else
		return (0);
}