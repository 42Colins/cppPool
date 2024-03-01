/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:43:26 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/01 16:00:02 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private :
		unsigned int _n;
		T *_array;
	public :
		Array(void);	
		~Array(void);	
		Array(const Array &toCopy);	
		Array(unsigned int n);
 		Array & operator= (const Array &);
		
		unsigned int size(void);
	    int& operator [](int idx);
		
		class OutOfBoundsException : public std::exception
		{
			public :
					virtual const char *what() const throw();
		};
};

# include "Array.tpp"

#endif