/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:33:14 by cprojean          #+#    #+#             */
/*   Updated: 2024/04/04 13:07:26 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <math.h>
# include <vector>
# include <algorithm>

class Span
{
	private :
		int	_max;
		int _nbr;
		std::vector<int> _arr;
		
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
		std::vector<int> getArray(void);
};

std::ostream &  operator<<( std::ostream & o, Span &name);

#endif