/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:41:04 by cprojean          #+#    #+#             */
/*   Updated: 2024/05/02 17:23:35 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	exchange(std::map<std::string, float> data, std::fstream &input)
{
	int index = 0;
	std::string str;
	std::string temp;
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
		findInData(str, data, 0, temp);
		index++;
	}
	return (0);
}

void	findInData(std::string str, std::map<std::string, float> data, int index, std::string temp)
{
	if (index == 0)
		temp = str;
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
		if (str.empty())
		{
			return ;
		}
		findInData(str, data, 1, temp);
		return ;
	}
	std::cout << temp.substr(0, 10) << " => " << value << " = " << (float) tmp * value << std::endl;
}

std::string lowerDate(std::string str)
{
	std::string end = str.substr(10, str.size());
	int	year = atoi(str.substr(0, 4).c_str());
	int	month = atoi(str.substr(5, 7).c_str());
	int	day = atoi(str.substr(8, 10).c_str());

	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day > 31)
	{
		std::cout << "The day should be in the range 01-31" << std::endl;
		std::string newOne;
		return (newOne);
	}
	if (month > 12)
	{
		std::cout << "The month should be in the range 01-12" << std::endl;
		std::string newOne;
		return (newOne);
	}
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
	if (year > 2023)
		year = 2023;
	else if (year < 2009)
	{
		std::cout << "The year should be in the range 2009-2023" << std::endl;
		std::string newOne;
		return (newOne);
	}
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

std::map<std::string, float> filldata(std::map<std::string, float> data, std::fstream &dataBase)
{
	std::string str;
	int index = 0;
	while (!dataBase.eof())
	{
		std::getline(dataBase, str);
		if (index != 0)
			data.insert(std::pair<std::string, float>(str.substr(0, 10), strtof(str.substr(11).c_str(), NULL)));
		index++;
	}
	return (data);
}

void printMap(std::map<std::string, float> data)
{
	for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++)
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