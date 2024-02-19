/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:53:46 by cprojean          #+#    #+#             */
/*   Updated: 2024/02/19 19:13:43 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("Form"), _minSignGrade(1), _minExecGrade(1)
{
	_isSigned = false;
}

Form::Form(std::string name, int minSign, int minExec) : _name(name), _minSignGrade(minSign), _minExecGrade(minExec)
{
	_isSigned = false;
	if (minSign <= 1 || minExec <= 1)
		throw Form::GradeTooLowException();
	else if (minSign >= 150 || minExec >= 150)
		throw Form::GradeTooHighException();	
}

Form::Form( const Form &toCopy ) : _name(toCopy._name), _minSignGrade(toCopy._minSignGrade), _minExecGrade(toCopy._minExecGrade)
{
	_isSigned = toCopy._isSigned;
}

Form::~Form(void)
{
}

std::string Form::getName(void) const
{
	return (_name);
}

int	Form::getSign(void) const 
{
	return (_minSignGrade);
}

int Form::getExec(void) const
{
	return (_minExecGrade);
}

bool Form::isSigned(void) const
{
	return (_isSigned);
}

void Form::beSigned(Bureaucrat *name)
{
	if (name->getGrade() <= _minSignGrade)
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

const char * Form::GradeTooLowException::what() const throw()
{

	return ("Sorry, grade too low\n");

}

const char *Form::GradeTooHighException::what() const throw()
{

	return ("Sorry, grade too high\n");

}

std::ostream &  operator<<( std::ostream & o, const Form &name )
{

	// std::cout << name.getName(); 
    o << name.getName() << " form needs grade " << name.getSign() << " to be signed and a grade of " << name.getExec() << " to be executed." << std::endl;
    return o;

}