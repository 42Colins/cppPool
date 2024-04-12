/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:19:10 by cprojean          #+#    #+#             */
/*   Updated: 2024/04/12 16:01:13 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc <= 2)
	{
		std::cout << "Error, not enough values to sort !" << std::endl;
		return (-1);
	}
	std::vector<std::pair<int, int> > myVec = fillVector(argv, argc - 1);
	std::cout << "BEFORE : " << std::endl << std::endl;
	printVector(myVec);
	myVec = startSorting(myVec);
	std::cout <<  std::endl << "AFTER : " << std::endl << std::endl;
	printVector(myVec);
	// std::cout << std::endl <<  "AFTER 1st sort : " << std::endl << std::endl;
	// myVec = firstSort(myVec);
}