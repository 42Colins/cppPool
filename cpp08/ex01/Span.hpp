/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:33:14 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/11 18:08:04 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <math.h>
# include <list>
# include <algorithm>

class Span
{
	private :
		int	_max;
		int _nbr;
		std::list<int> _arr;
		
	public :
		Span(void);
		Span(int N);
		Span(const Span &toCopy);
		~Span(void);
		Span & operator= (const Span &);
		void addNumber(int value);
		void fillArray(void);
		int shortestSpan(void);
		int longestSpan(void);
		int min(void);
		int max(void);
		int getMax(void);
		std::list<int> getArray(void);
};

std::ostream &  operator<<( std::ostream & o, Span &name);

#endif