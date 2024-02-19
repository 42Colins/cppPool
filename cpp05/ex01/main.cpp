/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:09:36 by cprojean          #+#    #+#             */
/*   Updated: 2024/02/19 18:04:50 by cprojean         ###   ########.fr       */
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
		Sam->promotion(1);
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
}