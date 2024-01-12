/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:00:09 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/12 16:07:43 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

int main()
{
	const Animal* meta = new Animal();
	std::cout << "Meta created" << std::endl << std::endl;
	
	const Animal* doggo = new Dog();
	std::cout << "Doggo created" << std::endl << std::endl;
	
	const WrongAnimal* wCat = new WrongCat();
	std::cout << "WrongCat created" << std::endl << std::endl;
	
	const Animal* cat = new Cat();
	std::cout << "Cat created" << std::endl << std::endl;
	
	// const Animal *test;
	// test->makesound();

	std::cout << doggo->getType() << " " << std::endl;
	std::cout << wCat->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	cat->makeSound(); // Will output the cat sound !
	wCat->makeSound(); //will output the WrongCat sound!
	doggo->makeSound();
	meta->makeSound();
	
	delete meta;
	delete doggo;
	delete wCat;
	delete cat;
	
	return 0;
}