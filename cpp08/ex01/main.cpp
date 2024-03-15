/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:13:57 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/12 15:50:48 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	// Span newOne(15);
	// newOne.addNumber(1);
	// newOne.addNumber(2);
	// newOne.addNumber(3);
	// newOne.addNumber(4);
	// newOne.addNumber(5);
	// newOne.addNumber(6);
	// newOne.addNumber(7);
	// newOne.addNumber(8);
	// newOne.addNumber(9);
	// newOne.addNumber(10);
	// newOne.addNumber(11);
	// newOne.addNumber(12);
	// newOne.addNumber(13);
	// newOne.addNumber(14);
	// newOne.addNumber(15);
	Span newOne(1000);
	newOne.fillArray();
	std::list<int> lst = newOne.getArray();
	std::cout << newOne << std::endl;
	int sspan = newOne.shortestSpan();
	std::cout << sspan << std::endl;
	sspan = newOne.longestSpan();
	std::cout << sspan << std::endl;
	
}