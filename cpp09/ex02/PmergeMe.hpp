/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:19:08 by cprojean          #+#    #+#             */
/*   Updated: 2024/05/02 17:53:32 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <vector>
# include <deque>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>

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

std::deque<std::pair<int, int> > filldeque(char **argv, int size);
std::deque<int> startSorting(std::deque<std::pair<int, int> >myDeque, int i);
std::deque<std::pair<int, int> > firstSort(std::deque<std::pair<int, int> >myDeque);
std::deque<std::pair<int, int> > continueSorting(std::deque<std::pair<int, int> >myDeque, int i);
std::deque<int> insertValues(std::deque<std::pair<int, int> >myDeque, std::deque<std::pair<int, int> >newVect, int i);
std::deque<int> insertValues(std::deque<int>returned, std::deque<std::pair<int, int> >oldVect, int i, int size);
std::deque<int> vectPairToInt(std::deque<std::pair<int, int> > myDeque);

std::deque<int> smallerdeque(std::deque<int> myVec, int mode, int pos);
std::deque<int> shiftdeque(std::deque<int> myVec, int value, int pos);
int	find(std::deque<int>::iterator value, std::deque<int> myDeque);
int binarySearch(int value, std::deque<int> myDeque);

void printdeque(std::deque<std::pair<int, int> > myVec);
void printdeque(std::deque<int> myVec);
void displayContainer(std::vector<int> cont);
void displayContainer(char **argv, int argc);

std::deque<int> startSorting(std::deque<int> returned, std::deque<std::pair<int, int> >mydeque, int i, unsigned long size);

int smallerSort(char **argv, int argc);


bool parseError(char **argv);

int JacobsthallSequence(int n);
int JacobsthallIndex(int n);

#endif