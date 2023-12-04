/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:43:22 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/04 17:43:33 by cprojean         ###   ########.fr       */
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
	if (fd.fail())
	{
		std::cout << "Error while opening the file" << std::endl;
		return ;
	}
	fdout.open(newFile.c_str(), std::fstream::out);
	while (!fd.eof())
	{
		std::getline(fd, this->_string);
		_string = findAndReplace(replace, _string, this->_toFind, _toReplace);
		if (fd.eof())
			fdout << _string;
		else
			fdout << _string << std::endl;
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
