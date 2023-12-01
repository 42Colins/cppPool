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
	std::fstream	fdout;
	newFile = _fileName + ".replace";
	fd.open(_fileName.c_str(), std::fstream::in);
	std::getline(fd, this->_string);
	fdout.open(newFile.c_str(), std::fstream::out);
	while (!fd.eof())
	{
		_string = findAndReplace(replace, _string, this->_toFind, _toReplace);
		fdout << _string << std::endl;
		std::getline(fd, this->_string);
	}

}

std::string	findAndReplace( std::string returned, std::string find, std::string toFind, std::string toReplace)
{

	size_t	index = 0;
	while (find[index])
	{
		if ((find.substr(index).find(toFind) == 0))
		{
			for(size_t	i = 0; i < toReplace.length(); i++)
				returned.push_back(toReplace[i]);
			index += toFind.length() - 1;
		}
		else
			returned.push_back(find[index]);
		index++;
	}
	return (returned);
}
