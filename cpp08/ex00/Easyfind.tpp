/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:27:22 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/06 17:32:59 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include "Easyfind.hpp"
#include <iterator>

template <typename T>
T *Easyfind(T *cont, int value)
{
	while (*cont != value)
		cont++;
	return (cont);
}



#endif