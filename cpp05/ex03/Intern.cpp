/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:07:44 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/19 15:59:53 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

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
	int index = 3;
	const std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < 3; i++)
	{
		if (forms[i].compare(nameForm) == 0)
			index = i;
	}
	AForm *createForm[] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};
	if (index == 3)
		return NULL;
	return (createForm[index]);
}