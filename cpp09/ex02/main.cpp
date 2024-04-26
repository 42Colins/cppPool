/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:19:10 by cprojean          #+#    #+#             */
/*   Updated: 2024/04/26 22:46:44 by cprojean         ###   ########.fr       */
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
	std::cout << "argc = " << argc << std::endl;
	std::vector<std::pair<int, int> > myVec = fillVector(argv, argc - 1);
	std::cout << "START : " << myVec.size() << std::endl << std::endl;
	// printVector(myVec);
	std::vector<int> finalOne;
	finalOne = startSorting(finalOne, myVec, i, argc - 1);
	std::cout <<  std::endl << "AFTER : " << std::endl << std::endl;
	printVector(finalOne);
	// for (int i = 0; i < 25; i++)
	// 	std::cout << JacobsthallSequence(i) << std::endl;
	// for (int i = 0; i < 100; i++)
	// 	std::cout << JacobsthallIndex(i) << std::endl;
	// std::cout << std::endl <<  "AFTER 1st sort : " << std::endl << std::endl;
	// myVec = firstSort(myVec);
}