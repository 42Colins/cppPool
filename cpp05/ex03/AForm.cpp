/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:53:46 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/19 15:47:01 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("AForm"), _minSignGrade(1), _minExecGrade(1)
{
	_isSigned = false;
}

AForm::AForm(std::string name, int minSign, int minExec) : _name(name), _minSignGrade(minSign), _minExecGrade(minExec)
{
	_isSigned = false;
	if (minSign < 1 || minExec < 1)
		throw AForm::GradeTooLowException();
	else if (minSign > 150 || minExec > 150)
		throw AForm::GradeTooHighException();
}

AForm::AForm( const AForm &toCopy ) : _name(toCopy._name), _minSignGrade(toCopy._minSignGrade), _minExecGrade(toCopy._minExecGrade)
{
	_isSigned = toCopy._isSigned;
}

AForm::~AForm(void)
{
}

AForm & AForm::operator=( const AForm &src )
{

	this->_isSigned = src._isSigned;
	return (*this);

}

std::string AForm::getName(void) const
{
	return (_name);
}

int	AForm::getSign(void) const 
{
	return (_minSignGrade);
}

int AForm::getExec(void) const
{
	return (_minExecGrade);
}

bool AForm::isSigned(void) const
{
	return (_isSigned);
}

void AForm::beSigned(Bureaucrat *name)
{
	if (name->getGrade() <= _minSignGrade)
		_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

const char * AForm::GradeTooLowException::what() const throw()
{

	return ("Sorry, grade too low\n");

}

const char *AForm::GradeTooHighException::what() const throw()
{

	return ("Sorry, grade too high\n");

}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= getExec())
		execForm(executor);
	else
		throw AForm::GradeTooLowException();
}

std::ostream &  operator<<( std::ostream & o, const AForm &name )
{

	// std::cout << name.getName(); 
    o << name.getName() << " form needs grade " << name.getSign() << " to be signed and a grade of " << name.getExec() << " to be executed." << std::endl;
	if (name.isSigned() == true)
		o << "This form is signed" << std::endl;
	else
		o << "This form is not signed" << std::endl;
    return o;

}