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
	Base *newBase;
	srand (time(NULL));
	int	number = rand() % 3 + 1;
	switch (number % 3)
	{
		case 0 :
			newBase = new A;
			std::cout << number << " type A" << std::endl;
			break ;
		case 1 :
			newBase = new B;
			std::cout << number << " type B" << std::endl;
			break ;
		case 2 :
			std::cout << number << " type C" << std::endl;
			newBase = new C;
			break ;
	}
	return (newBase);
}

void	identify(Base *p)
{
	if (p == dynamic_cast<A*>(p))
		std::cout << "Type A" << std::endl;
	if (p == dynamic_cast<B*>(p))
		std::cout << "Type B" << std::endl;		
	if (p == dynamic_cast<C*>(p))
		std::cout << "Type C" << std::endl;
}

void	identify(Base &p)
{
	if (&p == dynamic_cast<A*>(&p))
		std::cout << "Type A" << std::endl;
	if (&p == dynamic_cast<B*>(&p))
		std::cout << "Type B" << std::endl;		
	if (&p == dynamic_cast<C*>(&p))
		std::cout << "Type C" << std::endl;
}