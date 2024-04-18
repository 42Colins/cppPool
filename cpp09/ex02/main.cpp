/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:19:10 by cprojean          #+#    #+#             */
/*   Updated: 2024/04/18 14:55:16 by cprojean         ###   ########.fr       */
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
	int i = 0;
	std::vector<std::pair<int, int> > myVec = fillVector(argv, argc - 1);
	std::cout << "START : " << std::endl << std::endl;
	// printVector(myVec);
	std::vector<int> finalOne;
	finalOne = startSorting(finalOne, myVec, i, argc - 1);
	std::cout <<  std::endl << "AFTER : " << std::endl << std::endl;
	printVector(finalOne);
	// std::cout << std::endl <<  "AFTER 1st sort : " << std::endl << std::endl;
	// myVec = firstSort(myVec);
}