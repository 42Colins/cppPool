/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:47:22 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/20 12:36:50 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name )
{

	this->_name = name;
	this->_hp = 10;
	this->_ad = 10;
	this->_mana = 10;
	std::cout << "Building CL4PTP" << std::endl << "   Setting AD" << std::endl << "   Setting HP" << std::endl << "  Setting MANA" << std::endl << "      DONE" << std::endl;
	return ;

}

ClapTrap::ClapTrap( const ClapTrap &toCopy )
{

	*this = toCopy;
	return ;

}

ClapTrap::ClapTrap( void )
{

	this->_hp = 10;
	this->_ad = 10;
	this->_mana = 10;
	std::cout << "Building CL4PTP" << std::endl << "   Setting AD" << std::endl << "   Setting HP" << std::endl << "  Setting MANA" << std::endl << "      DONE" << std::endl;
	return ;

}

ClapTrap::~ClapTrap( void )
{

	std::cout << "Dismantling CL4PTP" << std::endl << "He's done" << std::endl;
	return ;

}

void	ClapTrap::open( void )
{

	std::cout << "AAAAAAANNNNNNNDDDDDD        OOOOOOPPPEEEEEEENNNNNNNN !!!!!" << std::endl << "OH NO, STAIRS !" << std::endl << "MINION GO ON WITHOUT ME AND MAKE YOUR MASTER PROUD !" << std::endl;

}

void	ClapTrap::takeDamage( unsigned int amount )
{

	std::cout << this->_name << " gets hurt and goes from " << this->_hp << " to " << this->_hp - amount << " hp" << std::endl;
	this->_hp -= amount;

}

void	ClapTrap::beRepaired( unsigned int amount )
{

	std::cout << this->_name << " heals himself goes from " << this->_hp << " to " << this->_hp + amount << " hp" << std::endl;
	this->_hp += amount;
	this->_mana -= 1;

}

void	ClapTrap::attack( const std::string &target)
{

	std::cout << this->_name << " attacks and deals " << this->_ad << " damages to " << target << std::endl;
	this->_mana -= 1;

}

ClapTrap &	ClapTrap::operator=(const ClapTrap &src)
{

	std::cout << "Copy assignement operator called !" << std::endl;
	this->_name = src._name;
	this->_ad = src._ad;
	this->_hp = src._hp;
	this->_mana = src._mana;
	return (*this);

}