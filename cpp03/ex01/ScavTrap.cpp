/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:47:22 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/20 12:38:22 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{

	return ;

}

ScavTrap::ScavTrap( std::string name )
{
	this->_name = name;
	this->_hp = 100;
	this->_ad = 20;
	this->_mana = 50;
	std::cout << "Building " << this->_name << std::endl << "   Setting AD" << std::endl << "   Setting HP" << std::endl << "  Setting MANA" << std::endl << "      DONE" << std::endl;
	return ;

}

ScavTrap::ScavTrap( const ScavTrap &toCopy)
{

	*this = toCopy;
	return ;
	
}

ScavTrap::~ScavTrap( void )
{

	std::cout << "Dismantling " << this->_name << std::endl << "He's dead" << std::endl;

}

void	ScavTrap::guardGate()
{

	std::cout << this->_name << "Scavvy is now a GUARDIAN !" << std::endl;

}

void	ScavTrap::attack( const std::string &target )
{

	std::cout << "BOOM ! " << this->_name << " attacks and deals " << this->_ad << " damages to " << target << std::endl;
	this->_mana -= 1;

}

ScavTrap &	ScavTrap::operator=(const ScavTrap &src)
{

	std::cout << "Copy assignement operator called !" << std::endl;
	this->_name = src._name;
	this->_ad = src._ad;
	this->_hp = src._hp;
	this->_mana = src._mana;
	return (*this);

}