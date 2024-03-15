/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:09:36 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/15 16:38:08 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	srand (time(NULL));
	Bureaucrat *Sam = new Bureaucrat(1, "Uncle Sam");
	Bureaucrat *Francois = new Bureaucrat;
	Intern *JohnDoe = new Intern;
	
	std::cout << std::endl;
	
	std::cout << *Sam;
	std::cout << *Francois;

	try
	{
		AForm *shrug = JohnDoe->makeForm("ShrubberyCreationForm", "brieuc");
		Sam->signForm(*shrug);
		std::cout << *shrug << std::endl;
		Francois->executeForm(*shrug);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "---------------------------" << std::endl << std::endl;
	
	try
	{
		ShrubberyCreationForm shrug("LeZeph");
		Sam->signForm(shrug);
		std::cout << shrug << std::endl;
		Sam->executeForm(shrug);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "---------------------------" << std::endl << std::endl;

	try
	{
		RobotomyRequestForm shrug("LeBaddy");
		Sam->signForm(shrug);
		std::cout << shrug << std::endl;
		Francois->executeForm(shrug);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "---------------------------" << std::endl << std::endl;
	
	try
	{
		RobotomyRequestForm shrug("LeBaddy");
		Sam->signForm(shrug);
		std::cout << shrug << std::endl;
		Sam->executeForm(shrug);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "---------------------------" << std::endl << std::endl;

	try
	{
		PresidentialPardonForm shrug("LeNiens");
		Sam->signForm(shrug);
		std::cout << shrug << std::endl;
		Francois->executeForm(shrug);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "---------------------------" << std::endl << std::endl;
	
	try
	{
		PresidentialPardonForm shrug("LeNiens");
		Sam->signForm(shrug);
		std::cout << shrug << std::endl;
		Sam->executeForm(shrug);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "NEXT" << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
		Sam->signForm(*rrf);
		Sam->executeForm(*rrf);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
} 