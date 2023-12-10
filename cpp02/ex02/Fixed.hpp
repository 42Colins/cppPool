/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:06:06 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/10 17:21:17 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private :
		int	_value;
		static const int _bits = 8;

	public :
		Fixed( void );
		~Fixed( void );
		Fixed( const int data );
		Fixed( const float number );
		Fixed( const Fixed &toCopy );
		Fixed &	operator=(const Fixed &);
		
		Fixed operator+(const Fixed &);
		Fixed operator-(const Fixed &);
		Fixed operator*(const Fixed &);
		Fixed operator/(const Fixed &);
		
		int operator<(const Fixed &);
		int operator>(const Fixed &);
		int operator<=(const Fixed &);
		int operator>=(const Fixed &);
		int operator!=(const Fixed &);
		int operator==(const Fixed &);

		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);
	
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		static const Fixed	&max( const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&min( const Fixed &a, const Fixed &b);
		static Fixed	&min(Fixed &a, Fixed &b);
};

std::ostream &	operator<<(std::ostream &o, const Fixed &value);

#endif