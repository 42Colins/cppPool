/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:43:44 by cprojean          #+#    #+#             */
/*   Updated: 2024/04/11 15:12:21 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <string.h>
# include <cerrno>
# include <cstring>
# include <stdlib.h>
# include <stdio.h>
# include <sstream>

# define to_string(value) static_cast<const std::ostringstream&>((\
std::ostringstream() << std::dec << value)).str()

bool parseStack(char *argv, int size);
bool isOperand(char s);
bool isNumb(char s);
std::stack<int> fillStack(char *argv, int size);
int calculate(std::stack<int> *myStack, char c);
void doAddition(std::stack<int> *myStack);
void doSubstraction(std::stack<int> *myStack);
void doMultiplication(std::stack<int> *myStack);
int doDivision(std::stack<int> *myStack);

#endif