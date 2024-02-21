/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:08:50 by cprojean          #+#    #+#             */
/*   Updated: 2024/02/21 18:13:42 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string.h>
#include <cstdlib>
#include <string>

ScalarConverter::ScalarConverter(void){}

ScalarConverter::~ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter &toCopy){*this = toCopy;}

ScalarConverter & ScalarConverter::operator= (const ScalarConverter &){return (*this);}

void ScalarConverter::convert(const std::string convert)
{
	const char *string = convert.c_str();
	
	if (strlen(string) == 1)
	{	
		if (isalpha(string[1]))
		{
			std::cout << "char : " << '\'' << static_cast<char>(string[0]) << '\'' << std::endl;
			std::cout << "int : " << static_cast<int>(string[0]) << std::endl;
			std::cout << "float : " << static_cast<float>(string[0]) << "f" << std::endl;
			std::cout << "double : " << static_cast<double>(string[0]) << std::endl;
		}
		else
		{
			std::cout << "char : " << '\'' << static_cast<char>(atoi(string)) << '\'' << std::endl;
			std::cout << "int : " << static_cast<int>(atoi(string)) << std::endl;
			std::cout << "float : " << static_cast<float>(atoi(string)) << "f" << std::endl;			
			std::cout << "double : " << static_cast<double>(atoi(string)) << std::endl;
		}
	}
	else if (convert.find(".") != std::string::npos)
	{
		if (*(convert.end() - 1) == 'f')
		{
			std::cout << "char : " << '\'' <<  static_cast<char>(strtof(string, NULL)) << '\'' << std::endl;
			std::cout << "int : " << static_cast<int>(strtof(string, NULL)) << std::endl;
			std::cout << "float : " << static_cast<float>(strtof(string, NULL)) << "f" << std::endl;				
			std::cout << "double : " << static_cast<double>(strtof(string, NULL)) << std::endl;
		}
		else
		{
			std::cout << "char : " << '\'' << static_cast<char>(strtod(string, NULL)) << '\'' << std::endl;
			std::cout << "int : " << static_cast<int>(strtod(string, NULL)) << std::endl;
			std::cout << "float : " << static_cast<float>(strtod(string, NULL)) << "f" << std::endl;	
			std::cout << "double : " << static_cast<double>(strtod(string, NULL)) << std::endl;
		}
	}
	else
	{
		std::cout << "char : " << '\'' << static_cast<char>(atoi(string)) << '\'' << std::endl;
		std::cout << "int : " << static_cast<int>(atoi(string)) << std::endl;
		std::cout << "float : " << static_cast<float>(atoi(string)) << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(atoi(string)) << std::endl;
	}
}