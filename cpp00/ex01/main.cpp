/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:15:31 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/22 16:17:35 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "inc.hpp"

int main ( void ) {

	PhoneBook Phonebook;
	std::string type;

	Phonebook.init();
	std::cout << "Welcome in PhoneBook, please ADD, SEARCH or EXIT" << std::endl;
	std::cin >> type;
	if (std::cin.eof())
		return (-1);
	while (type != "EXIT" && type != "Exit" && type != "exit")
	{
		if (type == "SEARCH" || type == "Search" || type == "search")
		{	
			Phonebook.display();
			std::cout << std::endl;
			Phonebook.search();
		}
		else if (type == "ADD" || type == "Add" || type == "add")
			Phonebook.add();
		else
			std::cout << "Error, check your input" << std::endl;
		std::cout << "What do we do next ?" << std::endl;
		std::cin >> type;
		if (std::cin.eof())
			return (-1);
	}
	if (type == "EXIT" || type == "Exit" || type == "exit")
	{
		std::cout << "PhoneBook cleared, bye !" << std::endl;
		return (-1);
	}
}

int     is_nbr(std::string arr)
{
	int	index = 0;
	
	while (arr[index])
	{
		if ('0' > arr[index] || arr[index] > '9')
			return (0);
		index++;
	}
	return (1);
}
