/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:00:09 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/12 16:14:45 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

int main()
{
	Dog basic;
	{
		Dog tmp = basic;
	}
	const Dog* j = new Dog();
	std::cout << "Doggo" << std::endl;
	const Animal* i = new Cat();
	std::cout << "Cat" << std::endl;
	const Dog* test = new Dog(*j);
	std::cout << "Test" << std::endl;
	(void) test;
	i->makeSound();
	j->makeSound();
	delete j;//should not create a leak
	delete test;
	delete i;
	return 0;
}