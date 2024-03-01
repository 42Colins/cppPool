/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:59:21 by cprojean          #+#    #+#             */
/*   Updated: 2024/02/29 17:05:53 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Iter.hpp"
#include "string.h"
#include "stdio.h"

int main( void ) 
{
	int tab[10] = {0,1,2,3,4,5,6,7,8,9};
	std::string str = "Hello world !";
	::iter(tab, 10, printShit);
	std::cout << std::endl;
	::iter(str.c_str(), str.size(), printShit);
	return 0;
}

