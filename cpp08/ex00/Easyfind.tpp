/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:27:22 by cprojean          #+#    #+#             */
/*   Updated: 2024/04/09 13:03:32 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "Easyfind.hpp"
# include <iterator>
# include <algorithm>
# include <iostream>

template <typename T>
typename T::iterator	Easyfind(T &cont, int value)
{
	if (cont.size() <= 1)
		throw std::runtime_error("Needs more than one element in the container");
	typename T::iterator iter = std::find(cont.begin(), cont.end(), value);
	if (*iter != value)
		throw std::runtime_error("Error, couldn't find the value in the container");
	return (iter);
}



#endif