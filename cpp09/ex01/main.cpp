/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:46:09 by cprojean          #+#    #+#             */
/*   Updated: 2024/04/11 16:37:20 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error, cannot sort less than two values" << std::endl;
		return 1;
	}
	else if (parseStack(argv[1], strlen(argv[1])) == false)
	{
		std::cout << "Sorry, a problem occured with your inputs" << std::endl;
		return 1;
	}
	std::stack<int> myStack = fillStack(argv[1], strlen(argv[1]));
}