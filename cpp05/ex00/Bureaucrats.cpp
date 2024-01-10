/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrats.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:52:04 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/10 18:21:32 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrats.hpp"

Bureaucrats::Bureaucrats( void )
{

	this->_name = "John Doe";
	this->_grade = 150;
	std::cout << "Basic man was born" << std::endl;

}

Bureaucrats::Bureaucrats( int grade, std::string name )
{

	if (grade > 150 || grade < 1)
		return ;
	this->_grade = grade;
	this->_name = name;
	std::cout << name << " was born with the grade of " << grade << std::endl;

}

Bureaucrats::Bureaucrats( const Bureaucrats &toCopy )
{

	*this = toCopy;

}

Bureaucrats::~Bureaucrats( void )
{

	std::cout << this->_name << " was found dead this morning ..." << std::endl;

}

Bureaucrats & Bureaucrats::operator=( const Bureaucrats &src )
{

	this->_name = src._name;
	this->_grade = src._grade;

}

std::string	Bureaucrats::getName( void )
{

	return (this->_name);

}

int	Bureaucrats::getGrade( void )
{

	return (this->_grade);

}

std::string	Bureaucrats::promotion( int grade )
{

	int newGrade = this->_grade + grade;
	if (newGrade > 0)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = newGrade;

}

std::string	Bureaucrats::nearlyFired( int grade )
{

	int newGrade = this->_grade - grade;
	if (newGrade > 0)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = newGrade;

}

const char * Bureaucrats::GradeTooLowException::error() const throw()
{

	return ("Sorry, grade too low\n");

}

const char *Bureaucrats::GradeTooHighException::error() const throw()
{

	return ("Sorry, grade too high\n");

}
