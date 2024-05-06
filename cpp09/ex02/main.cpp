/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:19:10 by cprojean          #+#    #+#             */
/*   Updated: 2024/05/06 15:28:05 by cprojean         ###   ########.fr       */
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
	
	if (argc == 3)
		return smallerSort(argv, argc);
	std::vector<int> finalOne;
	std::deque<int> finalDeque;
	gettimeofday(&start_time, NULL);
	std::vector<std::pair<int, int> > myVec = fillVector(argv, argc - 1);
	finalOne = startSorting(finalOne, myVec, i, argc - 1);
	gettimeofday(&end_time, NULL);
	timeV = (double) (end_time.tv_usec - start_time.tv_usec);	
	
	gettimeofday(&start_time, NULL);
	std::deque<std::pair<int, int> > myDeque = filldeque(argv, argc - 1);
	finalDeque = startSorting(finalDeque, myDeque, i, argc - 1);
	gettimeofday(&end_time, NULL);
	timeD = (double) (end_time.tv_usec - start_time.tv_usec);
	if (timeD < 0)
		timeD *= -1;
	if (timeV < 0)
		timeV *= -1;
	
	std::cout << "START : ";
	displayContainer(argv, argc - 1);
	std::cout << "AFTER : ";
	displayContainer(finalOne);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << std::fixed << std::setprecision(0) << timeV << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << std::fixed << std::setprecision(0) << timeD << " us" << std::endl;

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
	for(int i = 1; i <= argc; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
}

int smallerSort(char **argv, int argc)
{
	struct timeval start_time;
	struct timeval end_time;
	double timeV;
	gettimeofday(&start_time, NULL);
	std::cout << "START : " << argv[1] << " " << argv[2] << std::endl;
	if (atoi(argv[1]) < atoi(argv[2]))
		std::cout << "END : " << argv[1] << " " << argv[2] << std::endl;
	else
		std::cout << "END : " << argv[2] << " " << argv[1] << std::endl;
	gettimeofday(&end_time, NULL);
	timeV = (double) (end_time.tv_usec - start_time.tv_usec) / 100000;	
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << timeV << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << timeV << " us" << std::endl;
	return (1);
}