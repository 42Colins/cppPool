/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:03:06 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/19 11:04:04 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
{
	_n = 0;
	_array = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_n = n;
	_array = new T[n];
}

template <typename T>
Array<T>::~Array(void)
{
main.cpp, RPN.{cpp, hp	delete[] this->_array;
}

template <typename T>
Array<T>::Array(const Array &toCopy)
{
	_n = toCopy._n;
	_array = new T[_n];
	for (unsigned int i = 0; i < _n; i++)
		_array[i] = toCopy._array[i];
}

template <typename T>
Array<T> & Array<T>::operator= (const Array &cpy)
{
	delete[] _array;
	_n = cpy._n;
	_array = new T[_n];
	for (int i = 0; i < _n; i++)
		_array[i] = cpy._array[i];
	return (*this);
}

template <typename T>
unsigned int Array<T>::size(void)
{
	return (_n);
}

template <typename T>
int& Array<T>::operator [](int idx)
{
	if (idx < 0 || (unsigned int)idx >= _n)
		throw (OutOfBoundsException());
    return (_array[idx]);
}

template <typename T>
const char * Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Sorry, index out ouf bounds");
}


#endif