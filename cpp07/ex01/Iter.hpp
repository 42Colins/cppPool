/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:00:01 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/19 10:55:47 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T *array, size_t size, void (*func)(const T &))
{
	for (size_t i = 0; i < size; i++)
	{
		func(array[i]);
	}
}

template <typename T2>
void	printShit(T2 const & value)
{
	std::cout << value << std::endl;
}
#endif