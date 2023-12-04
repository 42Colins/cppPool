/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:06:06 by cprojean          #+#    #+#             */
/*   Updated: 2023/12/04 15:26:54 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private :
		int	_value;
		static const int _bits;

	public :
		Fixed( void );
		~Fixed( void );
		Fixed( Fixed toCopy );
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		void	operator=(const Fixed &);
}

#endif