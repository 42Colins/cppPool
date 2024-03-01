/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:00:01 by cprojean          #+#    #+#             */
/*   Updated: 2024/02/29 14:51:31 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

template <typename T> T max(T x, T y)
{
    return (x > y) ? x : y;
}

template <typename T> T min(T x, T y)
{
    return (x < y) ? x : y;
}

template <typename T> void swap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}

#endif