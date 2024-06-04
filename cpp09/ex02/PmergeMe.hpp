/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:19:08 by cprojean          #+#    #+#             */
/*   Updated: 2024/06/04 17:33:15 by cprojean         ###   ########.fr       */
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
# include <cerrno>
# include <climits>

std::vector<std::pair<long, long> > fillVector(char **argv, int size);
std::vector<long> startSorting(std::vector<std::pair<long, long> >myVector, int i);
std::vector<std::pair<long, long> > firstSort(std::vector<std::pair<long, long> >myVector);
std::vector<std::pair<long, long> > continueSorting(std::vector<std::pair<long, long> >myVector, int i);
std::vector<long> insertValues(std::vector<std::pair<long, long> >myVector, std::vector<std::pair<long, long> >newVect, int i);
std::vector<long> insertValues(std::vector<long>returned, std::vector<std::pair<long, long> >oldVect, int i, int size);
std::vector<long> vectPairToInt(std::vector<std::pair<long, long> > myVector);

std::vector<long> smallerVector(std::vector<long> myVec, int mode, int pos);
std::vector<long> shiftVector(std::vector<long> myVec, int value, int pos);

int find(long value, std::deque<long> mydeque);
int find(int value, std::vector<long> myVector);

int binarySearch(int value, std::vector<long> myVector);

void printVector(std::vector<std::pair<long, long> > myVec);
void printVector(std::vector<long> myVec);

std::vector<long> startSorting(std::vector<long> returned, std::vector<std::pair<long, long> >myVector, int i, unsigned long size);

std::deque<std::pair<long, long> > filldeque(char **argv, int size);
std::deque<long> startSorting(std::deque<std::pair<long, long> >myDeque, int i);
std::deque<std::pair<long, long> > firstSort(std::deque<std::pair<long, long> >myDeque);
std::deque<std::pair<long, long> > continueSorting(std::deque<std::pair<long, long> >myDeque, int i);
std::deque<long> insertValues(std::deque<std::pair<long, long> >myDeque, std::deque<std::pair<long, long> >newVect, int i);
std::deque<long> insertValues(std::deque<long>returned, std::deque<std::pair<long, long> >oldVect, int i, int size);
std::deque<long> vectPairToInt(std::deque<std::pair<long, long> > myDeque);

std::deque<long> smallerdeque(std::deque<long> myVec, int mode, int pos);
std::deque<long> shiftdeque(std::deque<long> myVec, int value, int pos);
int	find(std::deque<long>::iterator value, std::deque<long> myDeque);
int binarySearch(int value, std::deque<long> myDeque);

void printdeque(std::deque<std::pair<long, long> > myVec);
void printdeque(std::deque<long> myVec);
void displayContainer(std::vector<long> cont);
void displayContainer(char **argv, int argc);

std::deque<long> startSorting(std::deque<long> returned, std::deque<std::pair<long, long> >mydeque, int i, unsigned long size);

int smallerSort(char **argv, int argc);


bool parseError(char **argv);

int JacobsthallSequence(int n);
int JacobsthallIndex(int n);

#endif