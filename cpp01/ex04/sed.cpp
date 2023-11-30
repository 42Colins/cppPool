/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:43:22 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/30 18:54:50 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed ( char **argv )
{

	this->_fileName = argv[1];
	this->_toFind = argv[2];
	this->_toReplace = argv[3];
	return ;

}

Sed::~Sed ( void )
{

	return ;

}

void	Sed::sed_this( void )
{

	std::string	newFile;
	std::string	replace;
	std::fstream	fd;
	newFile = _fileName + ".replace";
	fd.open(_fileName.c_str(), std::fstream::in);
	std::getline(fd, this->_string);
	// std::cout << _string << std::endl;
	// fd.open(newFile.c_str(), std::fstream::out);
	while (!_string.empty())
	{
		findAndReplace(replace, _string, this->_toFind, _toReplace);
		std::getline(fd, this->_string);
	}

}

std::string	findAndReplace( std::string returned, std::string find, std::string toFind, std::string toReplace)
{

	size_t	pos = 0;
	size_t	index = 0;
	size_t	jdex = 0;
	pos = find.find(toFind);
	std::cout << pos << std::endl;
	if (pos >= 0)
	{
		while (find[index])
		{
			if (index < pos)
			{
				returned.push_back(find[index]);
				index++;
				jdex++;
			}
			else if (index == pos)
			{
				for(size_t	i = 0; i < toReplace.length(); i++)
				{
					returned.push_back(toReplace[i]);
					index++;
				}
				jdex += toFind.length();
			}
			else if (index > pos)
			{
				findAndReplace(returned, find, toFind, toReplace);
				break ;
			}
		}
	}
	pos = returned.find(toFind);
	if (pos )
	std::cout << returned << std::endl;
	return (returned);

}
