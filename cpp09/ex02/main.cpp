/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:19:10 by cprojean          #+#    #+#             */
/*   Updated: 2024/04/29 15:52:46 by cprojean         ###   ########.fr       */
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
	else if (parseError(argv) == 1)
	{
		std::cout << "Error with one of your values !" << std::endl;
		return (-1);
	}
	int i = 0;
	struct timeval start_time;
	struct timeval end_time;
	double timeV;
	double timeD;
	
	std::vector<int> finalOne;
	std::deque<int> finalDeque;
	std::vector<std::pair<int, int> > myVec = fillVector(argv, argc - 1);
	gettimeofday(&start_time, NULL);
	finalOne = startSorting(finalOne, myVec, i, argc - 1);
	gettimeofday(&end_time, NULL);
	timeV = (double) (end_time.tv_usec - start_time.tv_usec) / 100000;	
	
	std::deque<std::pair<int, int> > myDeque = filldeque(argv, argc - 1);
	gettimeofday(&start_time, NULL);
	finalDeque = startSorting(finalDeque, myDeque, i, argc - 1);
	gettimeofday(&end_time, NULL);
	timeD = (double) (end_time.tv_usec - start_time.tv_usec) / 100000;
	if (timeD < 0)
		timeD *= -1;
	if (timeV < 0)
		timeV *= -1;
	
	std::cout << "START : ";
	displayContainer(argv, argc - 1);
	std::cout << "AFTER : ";
	displayContainer(finalOne);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << timeV << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << timeD << " us" << std::endl;

}

bool parseError(char **argv)
{
	int j = 0;
	int index = 1;
	int size = 0;
	while (argv[index])
	{
		size = strlen(argv[index]);
		j = 0;
		while (j < size)
		{
			if (isdigit(argv[index][j]) == 0)
				return (1);
			j++;
		}
		index++;
	}
	return (0);
}

void displayContainer(std::vector<int> cont)
{
	if (cont.size() > 5)
	{
		int index = 0;
		for(std::vector<int>::iterator it = cont.begin(); it != cont.end(); it++)
		{
			if (index == 4)
			{
				std::cout << "[. . .]" << std::endl;
				return ;
			}
			std::cout << *it << " ";
			index++;
		}
	}
	for(std::vector<int>::iterator it = cont.begin(); it != cont.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void displayContainer(char **argv, int argc)
{
	if (argc > 5)
	{
		int index = 0;
		for(int i = 1; i < 6; i++)
		{
			if (index == 4)
			{
				std::cout << "[. . .]" << std::endl;
				return ;
			}
			std::cout << argv[i] << " ";
			index++;
		}
	}
	for(int i = 1; i < 6; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
}