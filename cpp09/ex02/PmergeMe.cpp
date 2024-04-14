/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:19:05 by cprojean          #+#    #+#             */
/*   Updated: 2024/04/14 16:24:12 by cprojean         ###   ########.fr       */
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

std::vector<int> startSorting(std::vector<std::pair<int, int> >myVector, int i)
{
	std::vector<std::pair<int, int> > newVect = myVector;
	std::vector<int> returned;
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
		newVect = continueSorting(myVector, i);
		// std::cout << "continueSorting returned on cycle : " << i << " vect size : " << newVect.size() << std::endl;
		// printVector(newVect);
	}
	if (newVect.size() == 1)
		returned = insertValues(newVect, myVector, i);
	std::cout << "Cycle n : " << i << std::endl;
	printVector(returned);
	return (returned);
}

std::vector<std::pair<int, int> > continueSorting(std::vector<std::pair<int, int> >myVector, int i)
{
	std::vector<std::pair<int, int> > newVect;
	int tmp = 0;
	int count = 0;
	std::pair<int, int> Benoit(0, 0);
	// printVector(myVector);
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
	if (newVect.size() > 1)
		startSorting(newVect, i + 1);
	// std::cout << "Cycle n : " << i << " BEFORE RETURNING, NEWVECT IS : " <<  std::endl;
	// printVector(newVect);
	return (newVect);
}

std::vector<int> insertValues(std::vector<std::pair<int, int> >myVector, std::vector<std::pair<int, int> >oldVect, int i)
{
	std::cout << "Cycle number : "<< i << " STARTING TO INSERT VALUES !!!!" << std::endl << std::endl;
	// if ()
	std::vector<int> returned;
	returned = vectPairToInt(myVector);
	// printVector(returned);
	for (std::vector<std::pair<int, int> >::iterator it = oldVect.begin(); it != oldVect.end(); it++)
	{
		std::cout << "elem : " << it->first << "Needs to be inserted at index : " << binarySearch(it->second, returned) << std::endl;
		returned = shiftVector(returned, it->first, binarySearch(it->second, returned));
	}
	std::cout << "After shifting" << std::endl;
	printVector(returned);
	(void) oldVect;
	// printVector(myVector);
	// printVector(oldVect);
	return (returned);
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

int binarySearch(int value, std::vector<int> myVector)
{	
    if (myVector.size() == 1)
		return 0;
	int pos = (myVector.size() / 2);
	if (myVector[pos] == value)
		return (pos);
	else if (myVector[pos] > value)
		return (binarySearch(value, smallerVector(myVector, 0, pos)));
	else
		return (pos + binarySearch(value, smallerVector(myVector, 1, pos)));
}

std::vector<int> shiftVector(std::vector<int> myVec, int value, int pos)
{
	// printVector(myVec);
	// printVector(myVec);
	myVec.push_back(myVec[myVec.size() - 1]);
	int size = myVec.size() - 1;
	for (std::vector<int>::iterator it = myVec.end(); it != myVec.begin(); it--)
	{
		if (it == myVec.end())
			it--;
		myVec[size] = myVec[size - 1];
		if (size == pos)
		{
			myVec[pos] = value;
			break;
		}
		size--;
	}
	if (size == 0 && pos == 0)
		myVec[pos] = value;
	return (myVec);
}

std::vector<int> smallerVector(std::vector<int> myVec, int mode, int pos)
{
	std::vector<int> returned;
	if (mode == 0)
	{
		int i = 0;
		for (std::vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++)
		{
			returned.push_back(*it);
			i++;
			if (i == pos)
				break;
		}
	}
	else
	{
		int i = pos;
		for (std::vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++)
		{
			returned.push_back(myVec[i]);
			i++;
			if (myVec.size())
				break;
		}
	}
	return (returned);
}

void printVector(std::vector<int> myVec)
{
	int i = 0;
	for (std::vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++)
	{
		std::cout << "Value on index : " << i << " : " << *it << std::endl;
		i++;
	}
}

std::vector<int> vectPairToInt(std::vector<std::pair<int, int> > myVec)
{
	std::vector<int> returned;
	for (std::vector<std::pair<int, int> >::iterator it = myVec.begin(); it != myVec.end(); it++)
	{
		returned.push_back(it->second);
		returned.push_back(it->first);
	}
	return (returned);
}