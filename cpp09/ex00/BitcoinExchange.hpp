/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:15:09 by cprojean          #+#    #+#             */
/*   Updated: 2024/05/02 17:18:36 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <sstream>
# include <iomanip>
# include <fstream>
# include <string>
# include <locale> 
# include <stdlib.h> 

# define to_string(value) static_cast<const std::ostringstream&>((\
std::ostringstream() << std::dec << value)).str()

bool	isLeapYear(int year);
std::map<std::string, float> filldata(std::map<std::string, float> data, std::fstream &dataBase);
void printMap(std::map<std::string, float> data);
int	checkDate(std::string str);
int	exchange(std::map<std::string, float> data, std::fstream &input);
void	findInData(std::string str, std::map<std::string, float> data, int index, std::string temp);
std::string lowerDate(std::string str);

#endif