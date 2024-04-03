/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:45:34 by cprojean          #+#    #+#             */
/*   Updated: 2024/04/03 19:47:46 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
	_nbr = 0;
	_max = 0;
}

Span::Span(int N)
{
	_max = N;
	_nbr = 0;
}

Span::~Span(void){}

Span::Span(const Span &toCopy)
{
	_max = toCopy._max;
	_nbr = toCopy._nbr;
	std::list<int> tmp = this->getArray();
	for (std::list<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
		_arr.push_back(*it);
}

Span & Span::operator=(const Span &src)
{
	_max = src._max;
	_nbr = src._nbr;
	std::list<int> lst = this->getArray();
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		_arr.push_back(*it);
	return (*this);
}

void Span::addNumber(int value)
{
	_arr.push_back(value);
	_nbr = _nbr + 1;
}

int Span::shortestSpan(void)
{
	int value = 0;
	int tmp = 0;
	int span;
	int shortSpan = 2147483647;
	this->_arr.sort();
	int	index = 0;
	std::list<int> lst = this->getArray();
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)	{
		if (index == 0)
		{
			tmp = 0;
			value = *it;
		}
		else
		{
			value = tmp;
			tmp = *it;
		}
		span = value - tmp;
		if (span < 0)
			span = span * -1;
		if (index != 0 && span < shortSpan)
			shortSpan = span;
		index++;
	}
	return (shortSpan);
}

int Span::longestSpan(void)
{
	int max = this->max();
	int min = this->min();
	return (max - min);
}

int Span::min(void)
{
	int value = 2147483647;
	std::list<int> lst = this->getArray();
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)	{
		if (*it < value)
			value = *it;
	}
	return (value);
}

int Span::max(void)
{
	int value = 0;
	std::list<int> lst = this->getArray();
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)	{
		if (*it > value)
			value = *it;
	}
	return (value);
}

void	Span::fillArray(void)
{
	srand (time(NULL));
	int value;
	for (int i = 0; i < _max; i++)
	{
		value = rand() % 2147483647;
		_arr.push_back(value);
	}
}

int	Span::getMax(void)
{
	return (_max);
}

std::list<int> Span::getArray(void)
{
	return (_arr);
}

std::ostream &  operator<<( std::ostream & o, Span &name)
{

	// std::cout << name.getName();
	int	index = 0;
	std::list<int> lst = name.getArray();
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		o << index << " : " << *it << std::endl;
		index++; 
	}
	return o;
}