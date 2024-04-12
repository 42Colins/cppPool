/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:19:05 by cprojean          #+#    #+#             */
/*   Updated: 2024/04/12 18:37:09 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<std::pair<int, int> > fillVector(char **argv, int size)
{
	int j = 1;
	int count = 0;
	if (size % 2 != 0)
	{
		size -= 1;
		count += 1;
	}
	std::vector<std::pair<int, int> > newVec;
	std::pair<int, int> Benoit(0, 0);
	for (int i = 0; i < size; i++)
	{
		if (i == 0 || i % 2 == 0)
		{
			Benoit = std::make_pair(atoi(argv[j]), atoi(argv[j+1]));
			newVec.push_back(Benoit);
		}
		j++;
	}
	if (count == 1)
	{
		Benoit= std::make_pair(atoi(argv[size + 1]), 2147483647);
		newVec.push_back(Benoit);		
	}
	return (newVec);
}

std::vector<std::pair<int, int> > startSorting(std::vector<std::pair<int, int> >myVector)
{
		std::vector<std::pair<int, int> > newVect;
	for (std::vector<std::pair<int, int> >::iterator it = myVector.begin(); it != myVector.end(); it++)
	{
		if (it->first > it->second)
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
	if (myVector.size() != 1)
	{
		std::vector<std::pair<int, int> > newVect = continueSorting(myVector);
		printVector(newVect);
	}
	myVector = insertValues(newVect, myVector);
	return (myVector);
}

std::vector<std::pair<int, int> > continueSorting(std::vector<std::pair<int, int> >myVector)
{
	std::vector<std::pair<int, int> > newVect;
	int tmp = 0;
	int count = 0;
	std::pair<int, int> Benoit(0, 0);
	std::cout << "Inside continue sorting" << std::endl;
	printVector(myVector);
	for (std::vector<std::pair<int, int> >::iterator it = myVector.begin(); it != myVector.end(); it++)
	{
		if (count % 2 == 0)
			tmp = it->second;
		if (count % 2 == 1)
		{
			Benoit = std::make_pair(tmp, it->second);
			newVect.push_back(Benoit);
		}
		count++;
	}
	if (newVect.size() != 1)
		startSorting(newVect);
	return (newVect);
}

std::vector<std::pair<int, int> > insertValues(std::vector<std::pair<int, int> >myVector, std::vector<std::pair<int, int> >newVect)
{
	
}

void printVector(std::vector<std::pair<int, int> > myVec)
{
	std::cout << "Printing Vector" << std::endl << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it = myVec.begin(); it != myVec.end(); it++)
	{
		std::cout << "First : " << it->first << std::endl;
		std::cout << "Second : " << it->second << std::endl;
	}
}