/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:44:07 by cprojean          #+#    #+#             */
/*   Updated: 2024/02/28 18:19:00 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "math.h"


Base::~Base(void){}

Base *generate(void)
{
	std::cout << "Generating base :" << std::endl;
	Base *newBase;
	srand (time(NULL));
	int	number = rand() % 3 + 1;
	switch (number % 3)
	{
		case 0 :
			newBase = new A;
			std::cout << "Generated base has type A" << std::endl;
			break ;
		case 1 :
			newBase = new B;
			std::cout << "Generated base has type B" << std::endl;
			break ;
		case 2 :
			std::cout << "Generated base has type C" << std::endl;
			newBase = new C;
			break ;
	}
	std::cout << "----------------------------------" << std::endl;
	return (newBase);
}

void	identify(Base *p)
{
	std::cout << "Identify(Base *p) :" << std::endl;
	if (p == dynamic_cast<A*>(p))
		std::cout << "Type A" << std::endl;
	if (p == dynamic_cast<B*>(p))
		std::cout << "Type B" << std::endl;		
	if (p == dynamic_cast<C*>(p))
		std::cout << "Type C" << std::endl;
	std::cout << "----------------------------------" << std::endl;
}

void	identify(Base &p)
{
	std::cout << "Identify(Base &p) :" << std::endl;
	try
	{
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "Base has type A !" << std::endl;
	} catch (std::exception &e)	{std::cout << e.what() << std::endl;}
	try
	{
		static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "Base has type B !" << std::endl;
	} catch (std::exception &e)	{std::cout << e.what() << std::endl;}
	try
	{
		static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "Base has type C !" << std::endl;
	} catch (std::exception &e)	{std::cout << e.what() << std::endl;}
}