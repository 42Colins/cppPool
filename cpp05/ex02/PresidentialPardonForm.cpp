/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:21:16 by cprojean          #+#    #+#             */
/*   Updated: 2024/02/20 14:29:23 by cprojean         ###   ########.fr       */
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

void PresidentialPardonForm::execForm(void) const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}