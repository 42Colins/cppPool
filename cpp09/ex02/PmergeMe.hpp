/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:19:08 by cprojean          #+#    #+#             */
/*   Updated: 2024/04/18 14:37:48 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string.h>
# include <stdlib.h>

std::vector<std::pair<int, int> > fillVector(char **argv, int size);
std::vector<int> startSorting(std::vector<std::pair<int, int> >myVector, int i);
std::vector<std::pair<int, int> > firstSort(std::vector<std::pair<int, int> >myVector);
std::vector<std::pair<int, int> > continueSorting(std::vector<std::pair<int, int> >myVector, int i);
std::vector<int> insertValues(std::vector<std::pair<int, int> >myVector, std::vector<std::pair<int, int> >newVect, int i);
std::vector<int> insertValues(std::vector<int>returned, std::vector<std::pair<int, int> >oldVect, int i, int size);
std::vector<int> vectPairToInt(std::vector<std::pair<int, int> > myVector);

std::vector<int> smallerVector(std::vector<int> myVec, int mode, int pos);
std::vector<int> shiftVector(std::vector<int> myVec, int value, int pos);
int	find(std::vector<int>::iterator value, std::vector<int> myVector);
int binarySearch(int value, std::vector<int> myVector);

void printVector(std::vector<std::pair<int, int> > myVec);
void printVector(std::vector<int> myVec);


std::vector<int> startSorting(std::vector<int> returned, std::vector<std::pair<int, int> >myVector, int i, unsigned long size);


#endif