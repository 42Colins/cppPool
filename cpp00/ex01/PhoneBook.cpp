/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:14:19 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/23 16:54:18 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {

	std::cout << "Constructor called" << std::endl;
	return;
	
}

PhoneBook::~PhoneBook( void ) {
	
	std::cout << "Destructor called" << std::endl;
	return;
	
}

void PhoneBook::search () {

	std::string str;
	int	index;
	
	str = "a";
	while (is_nbr(str) == 0)
	{
		std::cout << "Wich index of the Phonebook do you wish to see ?" << std::endl;
		std::cin >> str;
		if (std::cin.eof())
			return;
		if (str == "Exit" || str == "exit" || str == "EXIT")
			return;
	}
	index = std::atoi(str.c_str());
	if (index > 8)
	{
		std::cout << "This index is undefined ! Try another again" << std::endl;
		this->search();
		return;
	}
	index = index - 1;
	if (index < 0 || index > this->number - 1)
	{
		std::cout << "This index is undefined ! Try another again" << std::endl;
		this->search();
		return;
	}

	int	i = index;

	std::cout << std::endl;
	std::cout << "Here's the contact you wanted to see !" << std::endl;
	std::cout << std::endl;

	std::cout << "Name : " << this->_contact[i].get_first_name() << std::endl;
	std::cout << "Last name : " << this->_contact[i].get_last_name() << std::endl;
	std::cout << "Nickname : " << this->_contact[i].get_nickname() << std::endl;
	std::cout << "Phone number : " << this->_contact[i].get_phone() << std::endl;
	std::cout << "Darkest secret : " << this->_contact[i].get_secret() << std::endl;

}

void PhoneBook::add ( void ) {

	int index = this->number;
	if (index >= 7)
		index = this->number % 8;
	this->_contact[index].set_first_name();
	this->_contact[index].set_last_name();
	this->_contact[index].set_nickname();
	this->_contact[index].set_phone();
	this->_contact[index].set_secret();
	std::cout << this->_contact[index].get_first_name() << " has been added to phonebook" << std::endl;
	this->number += 1;
}

void    PhoneBook::init ( void ) {

	this->number = 0;
	return;

}

void    PhoneBook::display ( void ) {

	int	i = 0;
	std::string index;

	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|" <<std::setw(10) << std::right << "index" << "|";
	std::cout << std::setw(10) << std::right << "Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	while (i < this->number && i < 8)
	{
		std::cout << "|";
		display_info(i + 1);
		display_info(this->_contact[i].get_first_name());
		display_info(this->_contact[i].get_last_name());
		display_info(this->_contact[i].get_nickname());
		std::cout << std::endl;
		std::cout << "|__________|__________|__________|__________|" << std::endl;
		i++;
	}

}

void	PhoneBook::display_info ( std::string array) {

	if (array.length() > 10)
	{

		std::string copy = array;
		copy[9] = '.';
		std::cout << std::setw(10) << std::right << copy.substr(0, 10) << "|";
		return;
		
	}

	std::cout << std::setw(10) << std::right << array << "|";

}

void	PhoneBook::display_info ( int i ) {

	std::cout << std::setw(10) << std::right << i << "|";

}