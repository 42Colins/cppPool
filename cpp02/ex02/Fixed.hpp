/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:06:06 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/07 17:47:54 by cprojean         ###   ########.fr       */
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
		
		Fixed & operator+(const Fixed &);
		Fixed & operator-(const Fixed &);
		Fixed & operator*(const Fixed &);
		Fixed & operator/(const Fixed &);
		
		int operator<(const Fixed &);
		int operator>(const Fixed &);
		int operator<=(const Fixed &);
		int operator>=(const Fixed &);
		int operator!=(const Fixed &);
		int operator==(const Fixed &);

		Fixed & operator++();
		Fixed & operator++(int);
		Fixed & operator--();
	
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &	operator<<(std::ostream &o, const Fixed &value);

#endif