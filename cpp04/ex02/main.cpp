/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:00:09 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/10 17:41:08 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

int main()
{
	// Animal abstractAnimal;
	Dog basic;
	{
		Dog tmp = basic;
	}
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	// Animal test;
	i->makeSound();
	j->makeSound();
	delete j;//should not create a leak
	delete i;
	return 0;
}