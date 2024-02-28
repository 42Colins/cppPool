/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:34:27 by cprojean          #+#    #+#             */
/*   Updated: 2024/02/28 16:47:06 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "stdint.h"

Serializer::Serializer(void)
{
}

Serializer::Serializer(const Serializer &toCopy)
{
	*this = toCopy;
}

Serializer::~Serializer(void){}

Serializer & Serializer::operator= (const Serializer &){return (*this);}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t	castValue = reinterpret_cast<uintptr_t>(ptr);
	return (castValue);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *newData = reinterpret_cast<Data *>(raw);
	return (newData);
}