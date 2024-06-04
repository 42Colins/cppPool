/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:19:05 by cprojean          #+#    #+#             */
/*   Updated: 2024/06/04 17:37:27 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<std::pair<long, long> > fillVector(char **argv, int size)
{
	int fval;
	int sval;
	int j = 1;
	int count = 0;
	if (size % 2 != 0)
	{
		size -= 1;
		count += 1;
	}
	std::vector<std::pair<long, long> > newVec;
	std::pair<int, int> Benoit(0, 0);
	for (int i = 0; i < size; i++)
	{
		if (i == 0 || i % 2 == 0)
		{
			fval = strtod(argv[j], NULL);
			if (errno == ERANGE)
			{
				std::cout << "An error occured with your values" << std::endl;
				std::vector<std::pair<long, long> > empty;
				return (empty);
			}
			sval = strtod(argv[j + 1], NULL);
			if (errno == ERANGE)
			{
				std::cout << "An error occured with your values" << std::endl;
				std::vector<std::pair<long, long> > empty;
				return (empty);
			}
			Benoit = std::make_pair(fval, sval);
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

std::vector<long> startSorting(std::vector<long> returned, std::vector<std::pair<long, long> > myVector, int i, unsigned long size)
{
	std::vector<std::pair<long, long> > newVect;
	if (returned.size() == 0)
		std::vector<long> returned;
	for (std::vector<std::pair<long, long> >::iterator it = myVector.begin(); it != myVector.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	if (myVector.size() != 1)
	{
		int tmp = 0;
		int count = 0;
		std::pair<int, int> Benoit(0, 0);
		for (std::vector<std::pair<long, long> >::iterator it = myVector.begin(); it != myVector.end(); it++)
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
	if (returned.size() == 0 && newVect.size() == 1)
	{
		returned = insertValues(newVect, myVector, i);
		return (returned);
	}
	if (returned.size() != 0 && returned.size() < size)
		returned = insertValues(returned, myVector, i, size);
	return (returned);
}

std::vector<long> insertValues(std::vector<std::pair<long, long> > myVector, std::vector<std::pair<long, long> > oldVect, int i)
{
	(void) i;
	int ind = 0;
	int index = 1;
	int count = 0;
	int size = oldVect.size();
	if (size % 2 == 1 || size == 1 || (size / 2) == 1)
		count = 1;
	std::vector<long> returned;
	returned = vectPairToInt(myVector);
	for (std::vector<std::pair<long, long> >::iterator it = oldVect.begin(); it != oldVect.end(); it++)
	{
		ind = JacobsthallIndex(index);
		if (ind > size - 1)
		{
			while(ind > size - 1)
			{
				index++;
				ind = JacobsthallIndex(index);				
			}
		}
		std::vector<long>::iterator itt = returned.end();
		itt--;
		if (oldVect[ind].first == 2147483647)
		{
			index++;
			continue;
		}
		if (returned[binarySearch(oldVect[ind].first, returned)] < oldVect[ind].first)
			returned.push_back(oldVect[ind].first);
		else if (oldVect[ind].first > *itt)
			returned.push_back(oldVect[ind].first);
		else
			returned = shiftVector(returned, oldVect[ind].first, binarySearch(oldVect[ind].first, returned));	
		if (ind == size - 1 && count == 1)
		{
			std::vector<long>::iterator itt = returned.end();
			itt--;
			if (oldVect[ind].second == 2147483647 || oldVect[ind].second == *itt)
			{
				index++;
				continue;
			}
			if (returned[binarySearch(oldVect[ind].second, returned)] < oldVect[ind].second)
				returned.push_back(oldVect[ind].second);
			else
				returned = shiftVector(returned, oldVect[ind].second, binarySearch(oldVect[ind].second, returned));
		}
		index++;
	}
	return (returned);
}

std::vector<long> insertValues(std::vector<long> returned, std::vector<std::pair<long, long> > oldVect, int i, int size)
{
	(void) i;
	int count = 0;
	int index = 1;
	int id = 0;
	size = oldVect.size();
	if (size % 2 == 1 || size == 1 || (size / 2) == 1)
		count = 1;
	for (std::vector<std::pair<long, long> >::iterator it = oldVect.begin(); it != oldVect.end(); it++)
	{
		id = JacobsthallIndex(index);
		if (id > size - 1)
		{
			while(JacobsthallIndex(index) > size - 1)
			{
				index++;
				id = JacobsthallIndex(index);				
			}
		}
		std::vector<long>::iterator itt = returned.end();
		itt--;
		if (returned[binarySearch(oldVect[id].first, returned)] < oldVect[id].first)
			returned.push_back(oldVect[id].first);
		else if (oldVect[id].first > *itt)
			returned.push_back(oldVect[id].first);
		else
			returned = shiftVector(returned, oldVect[id].first, binarySearch(oldVect[id].first, returned));	
		if (id == size - 1 && count == 1)
		{
			itt = returned.end();
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
	// printVector(returned);
	return (returned);
}

void printVector(std::vector<std::pair<long, long> > myVec)
{
	std::cout << "Printing Vector" << std::endl << std::endl;
	for (std::vector<std::pair<long, long> >::iterator it = myVec.begin(); it != myVec.end(); it++)
	{
		std::cout << "First : " << it->first << std::endl;
		std::cout << "Second : " << it->second << std::endl;
	}
}

int binarySearch(int value, std::vector<long> myVector)
{
	if (myVector.size() == 1)
		return 0;
	std::vector<long>::iterator it = std::lower_bound(myVector.begin(), myVector.end(), value);
	if (it == myVector.end())
		return (0);
	int itval = *it;
	int found = find(itval, myVector);
	return found;
}

int find(int value, std::vector<long> myVector)
{
	unsigned long i = 0;
	int val = value;
	for (std::vector<long>::iterator it = myVector.begin(); *it != val; it++)
	{
		if (it == myVector.end())
			break;
		i++;
	}
	if (i > myVector.size())
		return (-1);
	if (myVector[i] != val)
		return (-1);
	return (i);
}

std::vector<long> shiftVector(std::vector<long> myVec, int value, int pos)
{
	myVec.push_back(myVec[myVec.size() - 1]);
	int size = myVec.size() - 1;
	for (std::vector<long>::iterator it = myVec.end(); it != myVec.begin(); it--)
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

std::vector<long> smallerVector(std::vector<long> myVec, int mode, int pos)
{
	std::vector<long> returned;
	if (mode == 0)
	{
		int i = 0;
		for (std::vector<long>::iterator it = myVec.begin(); it != myVec.end(); it++)
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
		for (std::vector<long>::iterator it = myVec.begin(); it != myVec.end(); it++)
		{
			returned.push_back(myVec[i]);
			i++;
			if (myVec.size())
				break;
		}
	}
	return (returned);
}

void printVector(std::vector<long> myVec)
{
	int i = 0;
	for (std::vector<long>::iterator it = myVec.begin(); it != myVec.end(); it++)
	{
		std::cout << "Value on index : " << i << " : " << *it << std::endl;
		i++;
	}
}

std::vector<long> vectPairToInt(std::vector<std::pair<long, long> > myVec)
{
	std::vector<long> returned;
	for (std::vector<std::pair<long, long> >::iterator it = myVec.begin(); it != myVec.end(); it++)
	{
		if (it->second == 2147483647)
			returned.push_back(it->first);
		else if (it->first == 2147483647)
			returned.push_back(it->second);
		else if (it->second < it->first)
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
	// printVector(returned);
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
	int index = 1;
	int ind = 0;
	for (int i = 0; i < 100; i++)
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

std::deque<std::pair<long, long> > filldeque(char **argv, int size)
{
	int j = 1;
	int count = 0;
	if (size % 2 != 0)
	{
		size -= 1;
		count += 1;
	}
	std::deque<std::pair<long, long> > newVec;
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

std::deque<long> startSorting(std::deque<long> returned, std::deque<std::pair<long, long> > mydeque, int i, unsigned long size)
{
	std::deque<std::pair<long, long> > newVect;
	if (returned.size() == 0)
		std::deque<long> returned;
	for (std::deque<std::pair<long, long> >::iterator it = mydeque.begin(); it != mydeque.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	if (mydeque.size() != 1)
	{
		int tmp = 0;
		int count = 0;
		std::pair<int, int> Benoit(0, 0);
		for (std::deque<std::pair<long, long> >::iterator it = mydeque.begin(); it != mydeque.end(); it++)
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
	// printdeque(newVect);
	if (returned.size() == 0 && newVect.size() == 1)
	{
		returned = insertValues(newVect, mydeque, i);
		return (returned);
	}
	if (returned.size() != 0 && returned.size() < size)
		returned = insertValues(returned, mydeque, i, size);
	return (returned);
}

std::deque<long> insertValues(std::deque<std::pair<long, long> > mydeque, std::deque<std::pair<long, long> > oldVect, int i)
{
	(void) i;
	int ind = 0;
	int index = 1;
	int count = 0;
	int size = oldVect.size();
	// printdeque(oldVect);
	if (size % 2 == 1 || size == 1 || (size / 2) == 1)
		count = 1;
	std::deque<long> returned;
	returned = vectPairToInt(mydeque);
	for (std::deque<std::pair<long, long> >::iterator it = oldVect.begin(); it != oldVect.end(); it++)
	{
		ind = JacobsthallIndex(index);
		if (ind > size - 1)
		{
			while(ind > size - 1)
			{
				index++;
				ind = JacobsthallIndex(index);				
			}
		}
		if (oldVect[ind].first == 2147483647)
		{
			index++;
			continue;
		}
		returned = shiftdeque(returned, oldVect[ind].first, binarySearch(oldVect[ind].first, returned));
		if (ind == size - 1 && count == 1)
		{
			std::deque<long>::iterator itt = returned.end();
			itt--;
			if (oldVect[ind].second == 2147483647 || oldVect[ind].second == *itt)
			{
				index++;
				continue;
			}
			if (returned[binarySearch(oldVect[ind].second, returned)] < oldVect[ind].second)
				returned.push_back(oldVect[ind].second);
			else
				returned = shiftdeque(returned, oldVect[ind].second, binarySearch(oldVect[ind].second, returned));
		}
		index++;
	}
	// printdeque(returned);
	return (returned);
}

std::deque<long> insertValues(std::deque<long> returned, std::deque<std::pair<long, long> > oldVect, int i, int size)
{
	(void) i;
	int count = 0;
	int index = 1;
	int id = 0;
	size = oldVect.size();
	if (size % 2 == 1 || size == 1 || (size / 2) == 1)
		count = 1;
	// printdeque(oldVect);
	for (std::deque<std::pair<long, long> >::iterator it = oldVect.begin(); it != oldVect.end(); it++)
	{
		id = JacobsthallIndex(index);
		if (id > size - 1)
		{
			while(JacobsthallIndex(index) > size - 1)
			{
				index++;
				id = JacobsthallIndex(index);				
			}
		}
		std::deque<long>::iterator itt = returned.end();
		itt--;
		if ((unsigned int) binarySearch(oldVect[id].first, returned) <= returned.size())
		{
			index++;
			continue ;
		}
		if (returned[binarySearch(oldVect[id].first, returned)] < oldVect[id].first)
			returned.push_back(oldVect[id].first);
		else if (oldVect[id].first > *itt)
			returned.push_back(oldVect[id].first);
		else
			returned = shiftdeque(returned, oldVect[id].first, binarySearch(oldVect[id].first, returned));	
		if (id == size - 1 && count == 1)
		{
			if (oldVect[id].second == 2147483647 || oldVect[id].second == *itt)
			{
				index++;
				continue;
			}
			if (returned[binarySearch(oldVect[id].second, returned)] < oldVect[id].second)
				returned.push_back(oldVect[id].second);
			else
				returned = shiftdeque(returned, oldVect[id].second, binarySearch(oldVect[id].second, returned));
		}
		index++;
	}
	// printdeque(returned);
	return (returned);
}

void printdeque(std::deque<std::pair<long, long> > myVec)
{
	std::cout << "Printing deque" << std::endl << std::endl;
	for (std::deque<std::pair<long, long> >::iterator it = myVec.begin(); it != myVec.end(); it++)
	{
		std::cout << "First : " << it->first << std::endl;
		std::cout << "Second : " << it->second << std::endl;
	}
}

int binarySearch(int value, std::deque<long> mydeque)
{
	if (mydeque.size() == 1)
		return 0;
	std::deque<long>::iterator it = std::lower_bound(mydeque.begin(), mydeque.end(), value);
	if (it == mydeque.end())
		return (0);
	int itval = *it;
	int found = find(itval, mydeque);
	return (found);
}

int find(long value, std::deque<long> mydeque)
{
	unsigned long i = 0;
	for (std::deque<long>::iterator it = mydeque.begin(); *it != value; it++)
	{
		if (it == mydeque.end())
			break;
		i++;
	}
	if (i > mydeque.size())
		return (-1);
	if (mydeque[i] != value)
		return (-1);
	return (i);
}

std::deque<long> shiftdeque(std::deque<long> myVec, int value, int pos)
{
	myVec.push_back(myVec[myVec.size() - 1]);
	int size = myVec.size() - 1;
	for (std::deque<long>::iterator it = myVec.end(); it != myVec.begin(); it--)
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

std::deque<long> smallerdeque(std::deque<long> myVec, int mode, int pos)
{
	std::deque<long> returned;
	if (mode == 0)
	{
		int i = 0;
		for (std::deque<long>::iterator it = myVec.begin(); it != myVec.end(); it++)
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
		for (std::deque<long>::iterator it = myVec.begin(); it != myVec.end(); it++)
		{
			returned.push_back(myVec[i]);
			i++;
			if (myVec.size())
				break;
		}
	}
	return (returned);
}

void printdeque(std::deque<long> myVec)
{
	int i = 0;
	for (std::deque<long>::iterator it = myVec.begin(); it != myVec.end(); it++)
	{
		std::cout << "Value on index : " << i << " : " << *it << std::endl;
		i++;
	}
}

std::deque<long> vectPairToInt(std::deque<std::pair<long, long> > myVec)
{
	std::deque<long> returned;
	for (std::deque<std::pair<long, long> >::iterator it = myVec.begin(); it != myVec.end(); it++)
	{
		if (it->second == 2147483647)
			returned.push_back(it->first);
		else if (it->first == 2147483647)
			returned.push_back(it->second);
		else if (it->second < it->first)
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
	// printdeque(returned);
	return (returned);
}
