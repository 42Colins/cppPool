/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:52:04 by cprojean          #+#    #+#             */
/*   Updated: 2024/02/15 18:34:51 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void )
{

	this->_name = "John Doe";
	this->_grade = 150;
	std::cout << "Basic man was born" << std::endl;

}

Bureaucrat::Bureaucrat( int grade, std::string name )
{

	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	this->_name = name;
	std::cout << name << " was born with the grade of " << grade << std::endl;

}

Bureaucrat::Bureaucrat( const Bureaucrat &toCopy )
{

	*this = toCopy;

}

Bureaucrat::~Bureaucrat( void )
{

	std::cout << this->_name << " was found dead this morning ..." << std::endl;

}

Bureaucrat & Bureaucrat::operator=( const Bureaucrat &src )
{

	this->_name = src._name;
	this->_grade = src._grade;
	return (*this);

}

std::string	Bureaucrat::getName( void ) const
{

	return (this->_name);

}

int	Bureaucrat::getGrade( void ) const
{

	return (this->_grade);

}

void	Bureaucrat::promotion( int grade )
{

	int newGrade = this->_grade - grade;
	if (newGrade <= 0)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = newGrade;

}

void	Bureaucrat::nearlyFired( int grade )
{

	int newGrade = this->_grade + grade;
	if (newGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = newGrade;

}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{

	return ("Sorry, grade too low\n");

}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{

	return ("Sorry, grade too high\n");

}

std::ostream &  operator<<( std::ostream & o, const Bureaucrat &name )
{

	// std::cout << name.getName(); 
    o << name.getName() << " , bureaucrat grade " << name.getGrade() << std::endl;
    return o;

}