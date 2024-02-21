/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:43:26 by cprojean          #+#    #+#             */
/*   Updated: 2024/02/20 14:28:34 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery_Creation_Form", 25, 5)
{
	_target = "target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery_Creation_Form", 25, 5)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &toCopy) : AForm(toCopy.getName(), toCopy.getSign(), toCopy.getExec())
{
	_target = toCopy._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( const ShrubberyCreationForm &src )
{

	_target = src._target;
	return (*this);

}

void ShrubberyCreationForm::execForm(void) const
{
	std::fstream	fd;
	std::fstream	fdout;
	std::string		str;
	std::string		fileName;
	
	fd.open("Tree.txt", std::fstream::in);
	if (fd.fail())
	{
		std::cout << "Error while opening the file" << std::endl;
		return ;
	}
	fileName = _target;
	fileName += "_shrubbery";
	fdout.open(fileName.c_str(), std::fstream::out);
	while (!fd.eof())
	{
		std::getline(fd, str);
		if (fd.eof())
			fdout << str;
		else
			fdout << str << std::endl;
	}
}