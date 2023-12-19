/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:03:35 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/18 16:21:35 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called !" << std::endl;
	return ;

}

Fixed::Fixed(const Fixed &toCopy )
{

	std::cout << "Copy constructor called !" << std::endl;
	this->_value = toCopy.getRawBits();
	return ;

}

Fixed::~Fixed( void )
{

	std::cout << "Destructor called" << std::endl;
	return ;

}

int Fixed::getRawBits ( void ) const
{

	std::cout << "getRawBits member function called !" << std::endl;
	return (this->_value);

}

void	Fixed::setRawBits( int const raw )
{

	std::cout << "setRawBits member function called !" << std::endl;
	this->_value = raw;

}

Fixed &	Fixed::operator=(const Fixed &src)
{

	std::cout << "Copy assignement operator called !" << std::endl;
	this->_value = src.getRawBits();
	return (*this);

}