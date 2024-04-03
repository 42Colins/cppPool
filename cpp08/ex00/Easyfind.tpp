/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:27:22 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/29 15:18:51 by cprojean         ###   ########.fr       */
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
	typename T::iterator iter = std::find(cont.begin(), cont.end(), value);
	if (*iter != value)
		std::cout << "Error, couldn't find the value." << std::endl;
	return (iter);
}



#endif