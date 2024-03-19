/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:21:16 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/19 15:19:07 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidenial_Pardon_Form", 25, 5)
{
	_target = "target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidenial_Pardon_Form", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &toCopy) : AForm(toCopy.getName(), toCopy.getSign(), toCopy.getExec())
{
	_target = toCopy._target;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=( const PresidentialPardonForm &src )
{

	_target = src._target;
	return (*this);

}

void PresidentialPardonForm::execForm(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExec())
		throw PresidentialPardonForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

const char * PresidentialPardonForm::GradeTooLowException::what() const throw()
{

	return ("Sorry, grade too low\n");

}

const char *PresidentialPardonForm::GradeTooHighException::what() const throw()
{

	return ("Sorry, grade too high\n");

}
