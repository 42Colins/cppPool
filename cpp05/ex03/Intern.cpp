/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:07:44 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/20 16:29:03 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <algorithm>


Intern::Intern(void)
{
}

Intern::Intern(const Intern &toCopy)
{
	*this = toCopy;
}

Intern::~Intern(void)
{
}

Intern & Intern::operator=( const Intern &src )
{

	(void) src;
	return (*this);

}

AForm *Intern::makeForm(std::string nameForm, std::string target)
{
	std::transform(nameForm.begin(), nameForm.end(), nameForm.begin(), toupper);
	std::string newForm = nameForm += "FORM";
	AForm *arr[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	const std::string forms[3] = {"SHRUBBERY CREATIONFORM", "ROBOTOMY REQUESTFORM", "PRESIDENTIAL PARDONFORM"};
	for (int i = 0; i < 3; i++)
	{
		if (forms[i].compare(nameForm) == 0)
			return (arr[i]);
	}
	throw Intern::NoSuchForm();
	return (NULL);
}

const char * Intern::NoSuchForm::what() const throw()
{

	return ("Sorry, this form doesn't exist\n");

}