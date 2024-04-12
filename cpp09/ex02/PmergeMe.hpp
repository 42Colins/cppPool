/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:19:08 by cprojean          #+#    #+#             */
/*   Updated: 2024/04/12 18:32:43 by cprojean         ###   ########.fr       */
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
std::vector<std::pair<int, int> > startSorting(std::vector<std::pair<int, int> >myVector);
std::vector<std::pair<int, int> > firstSort(std::vector<std::pair<int, int> >myVector);
std::vector<std::pair<int, int> > continueSorting(std::vector<std::pair<int, int> >myVector);
std::vector<std::pair<int, int> > insertValues(std::vector<std::pair<int, int> >myVector);
void printVector(std::vector<std::pair<int, int> > myVec);

#endif