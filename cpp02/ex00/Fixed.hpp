/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:06:06 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/07 13:53:25 by cprojean         ###   ########.fr       */
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
		Fixed(const Fixed &toCopy);
		~Fixed( void );
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		Fixed &	operator=(const Fixed &);
};

#endif