/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:03:35 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/10 17:23:53 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{

	// std::cout << "Default constructor called !" << std::endl;
	this->_value = 0;
	return ;

}

Fixed::Fixed( const int data )
{

	// std::cout << "Int constructor called !" << std::endl;
	this->_value = data << this->_bits;
	return ;

}

Fixed::Fixed( const float number )
{

	// std::cout << "Float constructor called !" << std::endl;
	this->_value = roundf(number * (1 << this->_bits));
	return ;

}

Fixed::Fixed(const Fixed &toCopy)
{

	// this->_value = toCopy.getRawBits();
	*this = toCopy;
	return ;

}

Fixed::~Fixed( void )
{

	// std::cout << "Destructor called" << std::endl;
	return ;

}

int Fixed::getRawBits ( void ) const
{

	return (this->_value);

}

void	Fixed::setRawBits( int const raw )
{

	// std::cout << "setRawBits member function called !" << std::endl;
	this->_value = raw;

}

float	Fixed::toFloat( void ) const
{

	return (static_cast<float>(this->_value) / (1 << this->_bits));

}

int	Fixed::toInt ( void ) const 
{

	return (this->_value >> this->_bits);

}

Fixed	&Fixed::operator=(const Fixed &src)
{

	// std::cout << "Copy assignement operator called !" << std::endl;
	this->setRawBits(src.getRawBits());
	return (*this);

}

Fixed	Fixed::operator+(const Fixed &src)
{

	Fixed number(src.toFloat() + this->toFloat());
	return (number);

}

Fixed	Fixed::operator-(const Fixed &src)
{

	Fixed number(src.toFloat() - this->toFloat());
	return (number);

}

Fixed	Fixed::operator*(const Fixed &src)
{

	Fixed number(src.toFloat() * this->toFloat());
	return (number);

}

Fixed	Fixed::operator/(const Fixed &src)
{

	Fixed number(src.toFloat() / this->toFloat());
	return (number);

}

int	Fixed::operator<(const Fixed &src)
{

	if (src.toFloat() < this->toFloat())
		return (1);
	else
		return (0);

}

int	Fixed::operator>(const Fixed &src)
{

	if (src.toFloat() > this->toFloat())
		return (1);
	else
		return (0);

}

int	Fixed::operator<=(const Fixed &src)
{

	if (src.toFloat() <= this->toFloat())
		return (1);
	else
		return (0);

}

int	Fixed::operator>=(const Fixed &src)
{

	if (src.toFloat() >= this->toFloat())
		return (1);
	else
		return (0);

}

int	Fixed::operator!=(const Fixed &src)
{

	if (src.toFloat() != this->toFloat())
		return (1);
	else
		return (0);

}

int	Fixed::operator==(const Fixed &src)
{

	if (src.toFloat() == this->toFloat())
		return (1);
	else
		return (0);

}

Fixed	Fixed::operator++()
{

	float value = 1;
	this->setRawBits(this->_value + value);
	return (*this);

}

Fixed	Fixed::operator++(int)
{

	Fixed	newFix(*this);
	operator++();
	return (newFix);

}

Fixed	Fixed::operator--()
{

	float value = -1;
	this->setRawBits(this->_value + value);
	return (*this);

}

Fixed Fixed::operator--(int)
{

	Fixed	newFix(*this);
	operator--();
	return (newFix);

}

std::ostream &	operator<<( std::ostream & o, const Fixed &value )
{

	o << value.toFloat();
	return o;

}

const Fixed	&Fixed::max( const Fixed &a, const Fixed &b)
{

	if (a.toFloat() < b.toFloat())
		return (b);
	else
		return (a);

}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (b);
	else
		return (a);
}

const Fixed	&Fixed::min( const Fixed &a, const Fixed &b)
{

	if (a.toFloat() > b.toFloat())
		return (b);
	else
		return (a);

}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (b);
	else
		return (a);
}