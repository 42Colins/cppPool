/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:08:50 by cprojean          #+#    #+#             */
/*   Updated: 2024/04/10 13:19:09 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string.h>
#include <cstdlib>
#include <string>
#include <cerrno>
#include <climits>
#include <stdio.h>

bool	isAPreset(std::string string);
void	isPreset(std::string convert);
void	isDouble(const char *string, long oflow);
void	isInt(const char *string, long oflow);
void	isChar(const char *string);
void	isFloat(const char *string, long oflow);
int	multichars(std::string convert);
int	multidots(std::string convert);
int	ischar(std::string convert);


ScalarConverter::ScalarConverter(void){}

ScalarConverter::~ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter &toCopy){*this = toCopy;}

ScalarConverter & ScalarConverter::operator= (const ScalarConverter &){return (*this);}

void ScalarConverter::convert(const std::string convert)
{
	const char *string = convert.c_str();

	if (isAPreset(convert))
	{
		isPreset(convert);
		return ;
	}
	double err = strtod(string, NULL);
	(void) err;
	if (errno == ERANGE)
	{
		std::cout << "The value overflowed" << std::endl;
		return ;
	}
	long oflow = strtol(string, NULL, 10);
	if (strlen(string) == 1)
		isChar(string);
	else if (convert.find(".") != std::string::npos) //Floats
	{
		if (multidots(convert) == 1)
		{
			std::cout << "char : impossible" << std::endl;
			std::cout << "int : impossible" << std::endl;
			std::cout << "float : impossible" << std::endl;
			std::cout << "double : impossible" << std::endl;
			return ;
		}
		if (multichars(convert) == 1)
			return ;
		if (*(convert.end() - 1) == 'f')
			isFloat(string, oflow);
		else
			isDouble(string, oflow);
	}
	else
	{
		if (ischar(convert))
			return ;
		isInt(string, oflow);
	}
}

bool	isAPreset(std::string string)
{
	if (string == "nan" || string == "nanf" || string == "-inf" || string == "-inff" || string == "+inf" || string == "+inff")
		return (true);
	return (false);
}

void isPreset(std::string convert)
{
	std::string minf = "-inf";
	std::string pinf = "+inf";
	std::string minff = "-inff";
	std::string pinff = "+inff";
	
	if (convert == "nan" || convert == "nanf")
	{
		std::cout << "char : " << "impossible" << std::endl;
		std::cout << "int : " << "impossible" << std::endl;
		std::cout << "double : " << "nan" << std::endl;
		std::cout << "float : " << "nanf" << std::endl;
	}
	else if (convert == pinf || convert == pinff)
	{
		std::cout << "char : " << "impossible" << std::endl;
		std::cout << "int : " << "impossible" << std::endl;
		std::cout << "double : " << pinf << std::endl;
		std::cout << "float : " << pinff << std::endl;
	}
	else if (convert == minf || convert == minff)
	{
		std::cout << "char : " << "impossible" << std::endl;
		std::cout << "int : " << "impossible" << std::endl;
		std::cout << "double : " << minf << std::endl;
		std::cout << "float : " << minff << std::endl;
	}

}

void isChar(const char *string)
{
	if (isprint(string[0]) && !isspace(string[0]))
	{
		if (isprint(static_cast<char>(strtod(string, NULL))))
			std::cout << "char : " << '\'' <<  static_cast<char>(strtod(string, NULL)) << '\'' << std::endl;
		else
			std::cout << "char : impossible" << std::endl;
		std::cout << "int : " << static_cast<int>(string[0]) << std::endl;
		std::cout << "float : " << static_cast<float>(string[0]) << ".0" << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(string[0]) << ".0" << std::endl;
	}
	else //Int
	{
		if (static_cast<double>(string[0]) - static_cast<int>(string[0]) != 0)
		{
			if (isspace(string[1]))
				std::cout << "char : " << '\'' << static_cast<char>(atoi(string)) << '\'' << std::endl;
			else
				std::cout << "char : impossible" << std::endl;
			std::cout << "int : " << static_cast<int>(atoi(string)) << std::endl;
			std::cout << "float : " << static_cast<float>(atoi(string)) << "f" << std::endl;			
			std::cout << "double : " << static_cast<double>(atoi(string)) << std::endl;
		}
		else
		{
			if (isspace(string[1]))
				std::cout << "char : " << '\'' << static_cast<char>(atoi(string)) << '\'' << std::endl;
			else
				std::cout << "char : impossible" << std::endl;
			std::cout << "int : " << static_cast<int>(atoi(string)) << std::endl;
			std::cout << "float : " << static_cast<float>(atoi(string)) << ".0" << "f" << std::endl;
			std::cout << "double : " << static_cast<double>(atoi(string)) << ".0" << std::endl;
		}
	}
}

void isFloat(const char *string, long oflow)
{
	if (static_cast<double>(string[0]) - static_cast<int>(string[0]) != 0)
	{
		if (isprint(static_cast<char>(strtod(string, NULL))))
			std::cout << "char : " << '\'' <<  static_cast<char>(strtod(string, NULL)) << '\'' << std::endl;
		else
			std::cout << "char : impossible" << std::endl; 
		if (oflow > INT_MAX || oflow < INT_MIN)
		{
			std::cout << "int : value overflowed" << std::endl;
			std::cout << "float : value overflowed" << std::endl;
		}
		else
		{
			std::cout << "int : " << static_cast<int>(strtof(string, NULL)) << std::endl;
			std::cout << "float : " << static_cast<float>(strtof(string, NULL)) << "f" << std::endl;				
		}
		std::cout << "double : " << static_cast<double>(strtof(string, NULL)) << std::endl;
	}
	else
	{
		if (isprint(static_cast<char>(strtod(string, NULL))))
			std::cout << "char : " << '\'' <<  static_cast<char>(strtof(string, NULL)) << '\'' << std::endl;
		else
			std::cout << "char : impossible" << std::endl;
		if (oflow > INT_MAX || oflow < INT_MIN)
		{
			std::cout << "int : value overflowed" << std::endl;
			std::cout << "float : value overflowed" << std::endl;
		}
		else
		{
			std::cout << "int : " << static_cast<int>(strtof(string, NULL)) << std::endl;
			std::cout << "float : " << static_cast<float>(strtof(string, NULL)) << ".0" << "f" << std::endl;
		}
		std::cout << "float : " << static_cast<float>(strtof(string, NULL)) << ".0" << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(strtof(string, NULL)) << ".0" << std::endl;
	}
}

void isDouble(const char *string, long oflow)
{
	if (static_cast<double>(string[0]) - static_cast<int>(string[0]) != 0)
	{
		if (isprint(static_cast<char>(strtod(string, NULL))))
			std::cout << "char : " << '\'' <<  static_cast<char>(strtod(string, NULL)) << '\'' << std::endl;
		else
			std::cout << "char : impossible" << std::endl;
		if (oflow > INT_MAX || oflow < INT_MIN)
		{
			std::cout << "int : value overflowed" << std::endl;
			std::cout << "float : value overflowed" << std::endl;

		}
		else
		{
			std::cout << "int : " << static_cast<int>(strtod(string, NULL)) << std::endl;
			std::cout << "float : " << static_cast<float>(strtod(string, NULL)) << "f" << std::endl;				
		}
		std::cout << "double : " << static_cast<double>(strtod(string, NULL)) << std::endl;
	}
	else
	{
		if (isprint(static_cast<char>(strtod(string, NULL))))
			std::cout << "char : " << '\'' <<  static_cast<char>(strtod(string, NULL)) << '\'' << std::endl;
		else
			std::cout << "char : impossible" << std::endl;
		if (oflow > INT_MAX || oflow < INT_MIN)
		{
			std::cout << "int : value overflowed" << std::endl;
			std::cout << "float : value overflowed" << std::endl;
		}
		else
		{
			std::cout << "int : " << static_cast<int>(strtod(string, NULL)) << std::endl;
			std::cout << "float : " << static_cast<float>(strtod(string, NULL)) << ".0" << "f" << std::endl;
		}
		std::cout << "double : " << static_cast<double>(strtod(string, NULL)) << ".0" << std::endl;
	}
}

void isInt(const char *string, long oflow)
{
	if (static_cast<double>(string[0]) - static_cast<int>(string[0]) != 0)
	{
		if (isspace(string[1]))
			std::cout << "char : " << '\'' << static_cast<char>(atoi(string)) << '\'' << std::endl;
		else
			std::cout << "char : impossible" << std::endl;
		if (oflow > INT_MAX || oflow < INT_MIN)
		{
			std::cout << "int : value overflowed" << std::endl;
			std::cout << "float : value overflowed" << std::endl;
		}
		else
		{
			std::cout << "int : " << static_cast<int>(atoi(string)) << std::endl;
			std::cout << "float : " << static_cast<float>(atoi(string)) << ".0" << "f" << std::endl;
		}
		std::cout << "double : " << static_cast<double>(strtod(string, NULL)) << std::endl;
	}
	else
	{
		if (isspace(string[1]))
			std::cout << "char : " << '\'' << static_cast<char>(atoi(string)) << '\'' << std::endl;
		else
			std::cout << "char : impossible" << std::endl;
		if (oflow > INT_MAX || oflow < INT_MIN)
		{
			std::cout << "int : value overflowed" << std::endl;
			std::cout << "float : value overflowed" << std::endl;
		}
		else
		{
			std::cout << "int : " << static_cast<int>(atoi(string)) << std::endl;
			std::cout << "float : " << static_cast<float>(atoi(string)) << ".0" << "f" << std::endl;
		}
		std::cout << "double : " << static_cast<double>(strtod(string, NULL)) << ".0" << std::endl;
	}
}

int	multidots(std::string convert)
{
	const char *str = convert.c_str();
	int	index = 0;
	int	count = 0;
	while (str[index])
	{
		if (str[index] == '.')
			count++;
		index++;
	}
	if (count > 1)
		return (1);
	return (0);
}

int	multichars(std::string convert)
{
	const char *str = convert.c_str();
	int	index = 0;
	int	count = 0;
	while (str[index])
	{
		if (isalpha(str[index]))
		{
			if (str[index] == 'f')
				count++;
			else
			{
				std::cout << "char : impossible" << std::endl;
				std::cout << "int : impossible" << std::endl;
				std::cout << "float : impossible" << std::endl;
				std::cout << "double : impossible" << std::endl;
				return (1);
			}
		}
		index++;
	}
	if (count > 1)
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : impossible" << std::endl;
		std::cout << "double : impossible" << std::endl;
		return (1);
	}
	return (0);
}

int	ischar(std::string convert)
{
	const char *str = convert.c_str();
	int index = 0;
	while (str[index])
	{
		if (isalpha(str[index]))
		{
			std::cout << "char : impossible" << std::endl;
			std::cout << "int : impossible" << std::endl;
			std::cout << "float : impossible" << std::endl;
			std::cout << "double : impossible" << std::endl;
			return (1);
		}
		index++;
	}
	return (0);
}

