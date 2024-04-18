/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:19:05 by cprojean          #+#    #+#             */
/*   Updated: 2024/04/18 15:14:17 by cprojean         ###   ########.fr       */
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

std::vector<int> startSorting(std::vector<int> returned, std::vector<std::pair<int, int> >myVector, int i, unsigned long size)
{
	std::vector<std::pair<int, int> > newVect;
	if (returned.size() == 0)
		std::vector<int> returned;
	for (std::vector<std::pair<int, int> >::iterator it = myVector.begin(); it != myVector.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	printVector(myVector);
	if (myVector.size() != 1)
	{
		int tmp = 0;
		int count = 0;
		std::pair<int, int> Benoit(0, 0);
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
			returned = startSorting(returned, newVect, i + 1, size);
	}
	std::cout << "MYVECTOR SIZE " << myVector.size() << std::endl << std::endl;
	if (myVector.size() == 1 || myVector.size() == 2 || myVector.size() == 3)
	{
		printVector(myVector);
		if (myVector[1].second < myVector[0].second)
			std::swap(myVector[0].first, myVector[0].second);
		printVector(myVector);
	}
	if (returned.size() == 0 && newVect.size() == 1)
	{
		returned = insertValues(newVect, myVector, i);
		return returned;
	}
	if (returned.size() != 0 && returned.size() < size)
		returned = insertValues(returned, myVector, i, size);
	return (returned);
}


// std::vector<int> startSorting(std::vector<std::pair<int, int> >myVector, int i)
// {
// 	std::vector<std::pair<int, int> > newVect = myVector;
// 	std::vector<int> returned;
// 	for (std::vector<std::pair<int, int> >::iterator it = myVector.begin(); it != myVector.end(); it++)
// 	{
// 		if (it->first > it->second)
// 		{
// 			int tmp = it->first;
// 			it->first = it->second;
// 			it->second = tmp;
// 		}
// 	}
// 	if (myVector.size() != 1)
// 	{
// 		newVect = continueSorting(myVector, i);
// 		// std::cout << "continueSorting returned on cycle : " << i << " vect size : " << newVect.size() << std::endl;
// 		// printVector(newVect);
// 	}
// 	if (newVect.size() == 1)
// 		returned = insertValues(newVect, myVector, i);
// 	std::cout << "Cycle n : " << i << " returned is full" << std::endl << std::endl;
// 	printVector(returned);
// 	if (returned.size() != 0)
// 	{
// 		printVector(returned);
// 		printVector(myVector);
// 		returned = insertValues(returned, myVector, i);
// 	}
// 	return (returned);
// }

// std::vector<std::pair<int, int> > continueSorting(std::vector<std::pair<int, int> >myVector, int i)
// {
// 	std::vector<std::pair<int, int> > newVect;
// 	int tmp = 0;
// 	int count = 0;
// 	std::pair<int, int> Benoit(0, 0);
// 	// printVector(myVector);
// 	for (std::vector<std::pair<int, int> >::iterator it = myVector.begin(); it != myVector.end(); it++)
// 	{
// 		if (count % 2 == 0)
// 			tmp = it->second;
// 		if (count % 2 == 1)
// 		{
// 			Benoit = std::make_pair(tmp, it->second);
// 			newVect.push_back(Benoit);
// 		}
// 		count++;
// 	}
// 	if (newVect.size() > 1)
// 		startSorting(newVect, i + 1);
// 	// std::cout << "Cycle n : " << i << " BEFORE RETURNING, NEWVECT IS : " <<  std::endl;
// 	// printVector(newVect);
// 	return (newVect);
// }

std::vector<int> insertValues(std::vector<std::pair<int, int> >myVector, std::vector<std::pair<int, int> >oldVect, int i)
{
	std::cout << "Cycle number : "<< i << " STARTING TO INSERT VALUES !!!!" << std::endl << std::endl;
	// if ()
	std::vector<int> returned;
	returned = vectPairToInt(myVector);
	// printVector(returned);
	for (std::vector<std::pair<int, int> >::iterator it = oldVect.begin(); it != oldVect.end(); it++)
	{
		std::cout << "elem : " << it->first << "Needs to be inserted at index : " << binarySearch(it->first, returned) << std::endl;
		returned = shiftVector(returned, it->first, binarySearch(it->first, returned));
	}
	std::cout << "After shifting" << std::endl;
	printVector(returned);
	return (returned);
}

std::vector<int> insertValues(std::vector<int>returned, std::vector<std::pair<int, int> >oldVect, int i, int size)
{
	int count = 0;
	int index = 1;
	std::cout << "size : " << size << "size / 2" << size / 2 << " " << std::endl;
	if ((size / 2) % 2 == 1)
		count = 1;
	std::cout << "We're on cycle number " << i << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it = oldVect.begin(); it != oldVect.end(); it++)
	{
		std::cout << "elem : " << it->first << "Needs to be inserted at index : " << binarySearch(it->first, returned) << std::endl;
		returned = shiftVector(returned, it->first, binarySearch(it->first, returned));
		if (index == size / 2 && count == 1)
		{
			std::cout << "elem : " << it->second << "Needs to be inserted at index : " << binarySearch(it->second, returned) << std::endl;
			returned = shiftVector(returned, it->second, binarySearch(it->second, returned));
		}
		index++;
	}
	printVector(returned);
	// std::cout << "is My Vector Sorted ???" << std::endl;
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
	std::vector<int>::iterator it = std::lower_bound(myVector.begin(), myVector.end(), value);
	if (*it == value)
		it = std::upper_bound(myVector.begin(), myVector.end(), value);
	return find(it, myVector);
	// int pos = (myVector.size() / 2);
	// if (*it == value)
	// 	return (-1);
	// std::cout << "value : " << value << "iterator :: " << *it << std::endl;
	// if (myVector[pos] == value)
	// 	return (pos);
	// else if (myVector[pos] > value)
	// 	return (binarySearch(value, smallerVector(myVector, 0, pos)));
	// else
	// 	return (pos + binarySearch(value, smallerVector(myVector, 1, pos)));
}

int	find(std::vector<int>::iterator value, std::vector<int> myVector)
{
	int i = 0;
	for(std::vector<int>::iterator it = myVector.begin(); *it != *value; it++)
		i++;
	if (myVector[i] != *value)
		return (-1);
	return (i);
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
		returned.push_back(it->first);
		returned.push_back(it->second);
		printVector(returned);
	}
	return (returned);
}