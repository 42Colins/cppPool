/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:09:36 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/19 14:34:02 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat *Sam = new Bureaucrat(1, "Uncle Sam");
	Bureaucrat *Francois = new Bureaucrat;
	
	std::cout << std::endl;
	
	std::cout << *Sam;
	std::cout << *Francois;

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
} 