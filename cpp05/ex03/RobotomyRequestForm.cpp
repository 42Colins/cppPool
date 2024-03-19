/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:15:57 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/19 15:40:39 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "stdlib.h"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy_Request_Form", 25, 5)
{
	_target = "target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy_Request_Form", 25, 5)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &toCopy) : AForm(toCopy.getName(), toCopy.getSign(), toCopy.getExec())
{
	_target = toCopy._target;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=( const RobotomyRequestForm &src )
{

	_target = src._target;
	return (*this);

}

void RobotomyRequestForm::execForm(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExec())
		throw RobotomyRequestForm::GradeTooLowException();
	int	number = rand() % 100 + 1;
	std::cout << "***** UNBELIEVEBLY ANNOYING NOISE *****" << std::endl;
	if (number <= 50)
		std::cout << _target << " has successfully been robotomized !" << std::endl;
	else
		std::cout << _target << " has not been robotomized !" << std::endl;
		
}

const char * RobotomyRequestForm::GradeTooLowException::what() const throw()
{

	return ("Sorry, grade too low\n");

}

const char *RobotomyRequestForm::GradeTooHighException::what() const throw()
{

	return ("Sorry, grade too high\n");

}