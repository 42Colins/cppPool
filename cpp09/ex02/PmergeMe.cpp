/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:19:05 by cprojean          #+#    #+#             */
/*   Updated: 2024/04/26 17:55:25 by cprojean         ###   ########.fr       */
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
			Benoit = std::make_pair(atoi(argv[j]), atoi(argv[j + 1]));
			newVec.push_back(Benoit);
		}
		j++;
	}
	if (count == 1)
	{
		Benoit = std::make_pair(atoi(argv[size + 1]), 2147483647);
		newVec.push_back(Benoit);
	}
	return (newVec);
}

std::vector<int> startSorting(std::vector<int> returned, std::vector<std::pair<int, int> > myVector, int i, unsigned long size)
{
	std::vector<std::pair<int, int> > newVect;
	if (returned.size() == 0)
		std::vector<int> returned;
	for (std::vector<std::pair<int, int> >::iterator it = myVector.begin(); it != myVector.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	// printVector(myVector);
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
	std::cout << "MYVECTOR SIZE " << myVector.size() << std::endl
			  << std::endl;
	if (returned.size() == 0 && newVect.size() == 1)
	{
		returned = insertValues(newVect, myVector, i);
		return (returned);
	}
	if (returned.size() != 0 && returned.size() < size)
		returned = insertValues(returned, myVector, i, size);
	return (returned);
}

std::vector<int> insertValues(std::vector<std::pair<int, int> > myVector, std::vector<std::pair<int, int> > oldVect, int i)
{
	std::cout << "Cycle number : " << i << " STARTING TO INSERT VALUES !!!!" << std::endl
			  << std::endl;
	int index = 1;
	int count = 0;
	int size = oldVect.size();
	printVector(oldVect);
	if (size % 2 == 1 || size == 1 || (size / 2) % 2 == 1)
		count = 1;
	std::cout << "size : " << size << " count : " << count << std::endl;
	std::vector<int> returned;
	returned = vectPairToInt(myVector);
	for (std::vector<std::pair<int, int> >::iterator it = oldVect.begin(); it != oldVect.end(); it++)
	{
		if (it->first == 2147483647)
		{
			index++;
			continue;
		}
		std::cout << "pair pair elem : " << it->first << "Needs to be inserted at index : " << binarySearch(it->first, returned) << std::endl;
		returned = shiftVector(returned, it->first, binarySearch(it->first, returned));
		if (index == size && count == 1)
		{
			std::cout << "elem : " << it->second << "Needs to be inserted at index : " << binarySearch(it->second, returned) << std::endl;
			std::cout << "elem : " << it->second << std::endl;
			std::vector<int>::iterator itt = returned.end();
			itt--;
			if (it->second == 2147483647 || it->second == *itt)
			{
				index++;
				continue;
			}
			if (returned[binarySearch(it->second, returned)] < it->second)
				returned.push_back(it->second);
			else
				returned = shiftVector(returned, it->second, binarySearch(it->second, returned));
		}
		index++;
	}
	std::cout << "After shifting " << *returned.end() << std::endl;
	printVector(returned);
	return (returned);
}

// std::vector<int> insertValues(std::vector<int>returned, std::vector<std::pair<int, int> >oldVect, int i, int size)
// {
// 	int count = 0;
// 	int index = 1;
// 	size = oldVect.size();
// 	if (size  % 2 == 1 || size == 1 || (size / 2) % 2 == 1)
// 		count = 1;
// 	std::cout << "size : " << size << " " << std::endl;
// 	printVector(oldVect);
// 	std::cout << "We're on cycle number " << i << std::endl;
// 	for (std::vector<std::pair<int, int> >::iterator it = oldVect.begin(); it != oldVect.end(); it++)
// 	{
// 		std::cout << "elem : " << it->first << "Needs to be inserted at index : " << binarySearch(it->first, returned) << " returned has "  << std::endl;
// 		if (returned[binarySearch(it->first, returned)] < it->first)
// 			returned.push_back(it->first);
// 		else if (returned[binarySearch(it->first, returned)] == it->first)
// 			continue;
// 		else
// 			returned = shiftVector(returned, it->first, binarySearch(it->first, returned));
// 		if (index == size && count == 1)
// 		{
// 			std::cout << " int pair elem : " << it->second << "Needs to be inserted at index : " << binarySearch(it->second, returned) << std::endl;
// 		std::vector<int>::iterator itt = returned.end();
// 		itt--;
// 		if (it->second == 2147483647 || it->second == *itt)
// 		{
// 			index++;
// 			continue;
// 		}
// 		if (returned[binarySearch(it->second, returned)] < it->second)
// 				returned.push_back(it->second);
// 			else
// 				returned = shiftVector(returned, it->second, binarySearch(it->second, returned));
// 		}
// 		index++;
// 	}
// 	std::cout << "is My Vector Sorted ???" << std::endl;
// 	printVector(returned);
// 	return (returned);
// }

std::vector<int> insertValues(std::vector<int> returned, std::vector<std::pair<int, int> > oldVect, int i, int size)
{
	int count = 0;
	int index = 1;
	int id = 0;
	size = oldVect.size();
	if (size % 2 == 1 || size == 1 || (size / 2) % 2 == 1)
		count = 1;
	std::cout << "size : " << size << " " << std::endl;
	printVector(oldVect);
	std::cout << "We're on cycle number " << i << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it = oldVect.begin(); it != oldVect.end(); it++)
	{
		id = JacobsthallIndex(index);
		std::cout << id << " index : " << index << std::endl;
		std::cout << "elem : " << oldVect[id].first << "Needs to be inserted at index : " << binarySearch(oldVect[id].first, returned) << " returned has " << std::endl;
		if (returned[binarySearch(oldVect[id].first, returned)] < oldVect[id].first)
			returned.push_back(oldVect[id].first);
		else if (returned[binarySearch(oldVect[id].first, returned)] == oldVect[id].first)
		{
			index++;
			continue;
		}
		else
			returned = shiftVector(returned, oldVect[id].first, binarySearch(oldVect[id].first, returned));
		if (index - 1 == size && count == 1)
		{
			std::cout << " int pair elem : " << oldVect[id].second << "Needs to be inserted at index : " << binarySearch(oldVect[id].second, returned) << std::endl;
			std::vector<int>::iterator itt = returned.end();
			itt--;
			if (oldVect[id].second == 2147483647 || oldVect[id].second == *itt)
			{
				index++;
				continue;
			}
			if (returned[binarySearch(oldVect[id].second, returned)] < oldVect[id].second)
				returned.push_back(oldVect[id].second);
			else
				returned = shiftVector(returned, oldVect[id].second, binarySearch(oldVect[id].second, returned));
		}
		index++;
	}
	std::cout << "is My Vector Sorted ???" << std::endl;
	printVector(returned);
	return (returned);
}

void printVector(std::vector<std::pair<int, int> > myVec)
{
	std::cout << "Printing Vector" << std::endl
			  << std::endl;
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
	return find(it, myVector);
}

int find(std::vector<int>::iterator value, std::vector<int> myVector)
{
	unsigned long i = 0;
	for (std::vector<int>::iterator it = myVector.begin(); *it != *value; it++)
	{
		if (it == myVector.end())
			break;
		i++;
	}
	if (i > myVector.size())
		return (-1);
	if (myVector[i] != *value)
		return (-1);
	return (i);
}

std::vector<int> shiftVector(std::vector<int> myVec, int value, int pos)
{
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
	std::cout << "Vec pair to int" << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it = myVec.begin(); it != myVec.end(); it++)
	{
		if (it->second < it->first)
		{
			returned.push_back(it->second);
			returned.push_back(it->first);
		}
		else
		{
			returned.push_back(it->first);
			returned.push_back(it->second);
		}
	}
	printVector(returned);
	return (returned);
}

int JacobsthallSequence(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	else
		return (JacobsthallSequence(n - 1) + (2 * JacobsthallSequence(n - 2)));
}

int JacobsthallIndex(int n)
{
	// if (n == 0)
	// 	return (0);
	// if (n == 1)
	// 	return (1);
	int index = 1;
	int ind = 0;
	// std::cout << "Searching for index : " << n << "JacobsthallSequence" << JacobsthallSequence(index - 1) << std::endl;
	for (int i = 0; i < 15; i++)
	{
		int prevJ = JacobsthallSequence(index - 1);
		int JacobInd = JacobsthallSequence(index);
		for (int j = JacobInd; j > prevJ; j--)
		{
			if (j == n)
				return (ind);
			ind++;
		}
		index++;
	}
	return (-1);
}