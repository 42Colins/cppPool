/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:08:50 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/15 18:25:26 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string.h>
#include <cstdlib>
#include <string>
#include <cerrno>
#include <climits>

ScalarConverter::ScalarConverter(void){}

ScalarConverter::~ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter &toCopy){*this = toCopy;}

ScalarConverter & ScalarConverter::operator= (const ScalarConverter &){return (*this);}

void ScalarConverter::convert(const std::string convert)
{
	const char *string = convert.c_str();
	std::string nan = "nan";
	std::string nanf = "nanf";
	std::string minf = "-inf";
	std::string pinf = "+inf";
	std::string minff = "-inff";
	std::string pinff = "+inff";
	
	if (string == nan || string == nanf)
	{
		std::cout << "char : " << "impossible" << std::endl;
		std::cout << "int : " << "impossible" << std::endl;
		std::cout << "double : " << nan << std::endl;
		std::cout << "float : " << nanf << std::endl;
	}
	else if (string == pinf || string == pinff)
	{
		std::cout << "char : " << "impossible" << std::endl;
		std::cout << "int : " << "impossible" << std::endl;
		std::cout << "double : " << pinf << std::endl;
		std::cout << "float : " << pinff << std::endl;
	}
	else if (string == minf || string == minff)
	{
		std::cout << "char : " << "impossible" << std::endl;
		std::cout << "int : " << "impossible" << std::endl;
		std::cout << "double : " << minf << std::endl;
		std::cout << "float : " << minff << std::endl;
	}
	else if (strlen(string) == 1)
	{	
		if (isalpha(string[1]))
		{
			if (static_cast<double>(string[0]) - static_cast<int>(string[0]) != 0)
			{
				std::cout << "char : " << '\'' << static_cast<char>(string[0]) << '\'' << std::endl;
				std::cout << "int : " << static_cast<int>(string[0]) << std::endl;
				std::cout << "float : " << static_cast<float>(string[0]) << "f" << std::endl;
				std::cout << "double : " << static_cast<double>(string[0]) << std::endl;
			}
			else
			{
				std::cout << "char : " << '\'' << static_cast<char>(string[0]) << '\'' << std::endl;
				std::cout << "int : " << static_cast<int>(string[0]) << std::endl;
				std::cout << "float : " << static_cast<float>(string[0]) << ".0" << "f" << std::endl;
				std::cout << "double : " << static_cast<double>(string[0]) << ".0" << std::endl;
			}
		}
		else
		{
			if (static_cast<double>(string[0]) - static_cast<int>(string[0]) != 0)
			{
				std::cout << "char : " << '\'' << static_cast<char>(atoi(string)) << '\'' << std::endl;
				std::cout << "int : " << static_cast<int>(atoi(string)) << std::endl;
				std::cout << "float : " << static_cast<float>(atoi(string)) << "f" << std::endl;			
				std::cout << "double : " << static_cast<double>(atoi(string)) << std::endl;
			}
			else
			{
				std::cout << "char : " << '\'' << static_cast<char>(atoi(string)) << '\'' << std::endl;
				std::cout << "int : " << static_cast<int>(atoi(string)) << std::endl;
				std::cout << "float : " << static_cast<float>(atoi(string)) << ".0" << "f" << std::endl;
				std::cout << "double : " << static_cast<double>(atoi(string)) << ".0" << std::endl;
			}
		}
	}
	else if (convert.find(".") != std::string::npos)
	{
		if (*(convert.end() - 1) == 'f')
		{
			if (static_cast<double>(string[0]) - static_cast<int>(string[0]) != 0)
			{
				std::cout << "char : " << '\'' <<  static_cast<char>(strtof(string, NULL)) << '\'' << std::endl;
				std::cout << "int : " << static_cast<int>(strtof(string, NULL)) << std::endl;
				std::cout << "float : " << static_cast<float>(strtof(string, NULL)) << "f" << std::endl;				
				std::cout << "double : " << static_cast<double>(strtof(string, NULL)) << std::endl;
			}
			else
			{
				std::cout << "char : " << '\'' << static_cast<char>(strtof(string, NULL)) << '\'' << std::endl;
				std::cout << "int : " << static_cast<int>(strtof(string, NULL)) << std::endl;
				std::cout << "float : " << static_cast<float>(strtof(string, NULL)) << ".0" << "f" << std::endl;
				std::cout << "double : " << static_cast<double>(strtof(string, NULL)) << ".0" << std::endl;
			}
		}
		else
		{
		if (static_cast<double>(string[0]) - static_cast<int>(string[0]) != 0)
			{
				std::cout << "char : " << '\'' <<  static_cast<char>(strtod(string, NULL)) << '\'' << std::endl;
				std::cout << "int : " << static_cast<int>(strtod(string, NULL)) << std::endl;
				std::cout << "float : " << static_cast<float>(strtod(string, NULL)) << "f" << std::endl;				
				std::cout << "double : " << static_cast<double>(strtod(string, NULL)) << std::endl;
			}
			else
			{
				std::cout << "char : " << '\'' << static_cast<char>(strtod(string, NULL)) << '\'' << std::endl;
				std::cout << "int : " << static_cast<int>(strtod(string, NULL)) << std::endl;
				std::cout << "float : " << static_cast<float>(strtod(string, NULL)) << ".0" << "f" << std::endl;
				std::cout << "double : " << static_cast<double>(strtod(string, NULL)) << ".0" << std::endl;
			}
		}
	}
	else
	{
		long err = strtol(string, NULL, 10);
		(void) err;
		if (err > INT_MAX || err < INT_MIN)
		{
			std::cout << "The value overflowed" << std::endl;
			return ;
		}
		if (static_cast<double>(string[0]) - static_cast<int>(string[0]) != 0)
		{
			std::cout << "char : " << '\'' << static_cast<char>(atoi(string)) << '\'' << std::endl;
			std::cout << "int : " << static_cast<int>(atoi(string)) << std::endl;
			std::cout << "float : " << static_cast<float>(atoi(string)) << "f" << std::endl;			
			std::cout << "double : " << static_cast<double>(atoi(string)) << std::endl;
		}
		else
		{
			std::cout << "char : " << '\'' << static_cast<char>(atoi(string)) << '\'' << std::endl;
			std::cout << "int : " << static_cast<int>(atoi(string)) << std::endl;
			std::cout << "float : " << static_cast<float>(atoi(string)) << ".0" << "f" << std::endl;
			std::cout << "double : " << static_cast<double>(atoi(string)) << ".0" << std::endl;
		}
	}
}