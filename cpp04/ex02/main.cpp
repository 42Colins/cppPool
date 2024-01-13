/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:00:09 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/13 16:43:14 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

int main()
{
	std::cout << "Abstract animals :" << std::endl << std::endl;
	// Animal abstractAnimal;
	Dog basic;
	{
		Dog tmp = basic;
	}
	std::cout << std::endl;
	std::cout << "Doggo :" << std::endl << std::endl;
	const Animal* j = new Dog();
	std::cout << std::endl;
	std::cout << "Cat :" << std::endl << std::endl;
	const Animal* i = new Cat();
	// Animal test;
	std::cout << std::endl;
	std::cout << "Sounds :" << std::endl << std::endl;
	i->makeSound();
	j->makeSound();
	
	const Dog* doggo = new Dog();
	const Dog* doggo2 = new Dog(*doggo);
	
	std::cout << std::endl;	
	std::cout << "Deletes :" << std::endl << std::endl;
	
	delete doggo;
	delete doggo2;
	delete j;//should not create a leak
	delete i;
	return 0;
}