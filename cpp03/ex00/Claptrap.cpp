/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:36:53 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/10 18:03:49 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

Claptrap::Claptrap( void )
{

	this->_hp = 10;
	this->_ad = 10;
	this->_mana = 10;
	std::cout << "Building CL4PTP" << std::endl << "   Setting AD" << std::endl << "   Setting HP" << std::endl << "  Setting MANA" << std::endl << "      DONE" << std::endl;
	return ;

}

Claptrap::~Claptrap( void )
{

	std::cout << "Dismantling CL4PTP" << std::endl << "He's done" << std::endl;
	return ;

}

void	Claptrap::open( void )
{

	std::cout << "AAAAAAANNNNNNNDDDDDD        OOOOOOPPPEEEEEEENNNNNNNN !!!!!" << std::endl << "OH NO, STAIRS !" << std::endl << "MINION GO ON WITHOUT ME AND MAKE YOUR MASTER PROUD !" << std::endl;

}

void	Claptrap::takeDamage( unsigned int amount )
{

	std::cout << "CL4PTP gets hurt and goes from " << this->_hp << " to " << this->_hp - amount << " hp" << std::endl;
	this->_hp -= amount;

}

void	Claptrap::beRepaired( unsigned int amount )
{

	std::cout << "CL4PTP heals himself goes from " << this->_hp << " to " << this->_hp + amount << " hp" << std::endl;
	this->_hp += amount;
	this->_mana -= 1;

}

void	Claptrap::attack( const std::string &target)
{

	std::cout << "CL4PTP attacks and deals " << this->_ad << " damages to " << target << std::endl;
	this->_mana -= 1;

}
