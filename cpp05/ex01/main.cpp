/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:09:36 by cprojean          #+#    #+#             */
/*   Updated: 2024/02/19 21:39:17 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat *Sam = new Bureaucrat(20, "Uncle Sam");
	Bureaucrat *Francois = new Bureaucrat;
	
	std::cout << std::endl;
	
	try
	{
		Sam->promotion(21);
		std::cout << "New grade " << Sam->getGrade() << std::endl; 

	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Sam->promotion(18);
		std::cout << "New grade " << Sam->getGrade() << std::endl; 
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Francois->nearlyFired(1);
		std::cout << "New grade " << Sam->getGrade() << std::endl; 
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << *Sam;
	std::cout << *Francois;
	try
	{
		Form *form = new Form("Samere", 2, 2);
		form->beSigned(Sam);
		std::cout << "Sam" << std::endl;
		form->beSigned(Francois);
		std::cout << "Francois" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}