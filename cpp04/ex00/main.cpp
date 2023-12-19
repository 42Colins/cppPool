/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:00:09 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/18 13:59:54 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorphism.h"

int main()
{
	const Animal* meta = new Animal();
	const Animal* doggo = new Dog();
	const WrongAnimal* wCat = new WrongCat();
	const Animal* cat = new Cat();

	std::cout << doggo->getType() << " " << std::endl;
	std::cout << wCat->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	cat->makeSound(); // Will output the cat sound !
	wCat->makeSound(); //will output the WrongCat sound!
	doggo->makeSound();
	meta->makeSound();
	return 0;
}