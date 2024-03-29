/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:06:06 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/18 16:22:25 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private :
		int	_value;
		static const int	_bits = 8;

	public :
		Fixed( void );
		~Fixed( void );
		Fixed(const Fixed &toCopy);
		Fixed &	operator=(const Fixed &);
		
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif