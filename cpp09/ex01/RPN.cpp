/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:46:01 by cprojean          #+#    #+#             */
/*   Updated: 2024/05/22 18:28:14 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool parseStack(char *argv, int size)
{
	int count = 0;
	int op = 0;
	int numb = 0;
	for (int i = 0; i < size; i++)
	{
		if (count < 2 && isOperand(argv[i]) == true)
		{
			std::cout << "Error, operand too early in the expression" << std::endl;
			return false; 
		}
		if (isOperand(argv[i]) == true)
		{
			op++;
			count++;
			continue ;
		}
		else if (isNumb(argv[i]) == true)
		{
			numb++;
			count++;
			continue ;	
		}
		else if (argv[i] != ' ')
		{
			std::cout << "Error with this value : " << argv[i] << std::endl;
			return false;
		}
	}
	if (isNumb(argv[size]) == true)
		return false;
	if (op != numb - 1)
		return false;
	return true;
}

bool isOperand(char s)
{
	if (s == '+' || s == '-' || s == '/' || s == '*')
		return true;
	return false;
}

bool isNumb(char s)
{	
	if (s < 48 || s > 57)
		return false;
	return true;
}

std::stack<int> fillStack(char *argv, int size)
{
	std::stack<int> myStack;
	std::stack<int> newOne;
	int i = 0;
	
	std::cout << argv << std::endl;
	while (i < size)
	{
		if (argv[i] == ' ')
			i++;
		if (isNumb(argv[i]))
		{	
			myStack.push(argv[i] - '0');
			// i++;
		}
		if (isOperand(argv[i]))
		{	
			if (calculate(&myStack, argv[i]) == -1)
				return (newOne);
		}
		i++;
	}
	std::cout << "RESULT : " <<  myStack.top() << std::endl;
	return myStack;
}

int calculate(std::stack<int> *myStack, char c)
{
	if (myStack->size() < 2)
	{
		std::cout << "An error occured with your inputs" << std::endl;	
		return (-1);
	}
	if (c == '+')
		doAddition(myStack);
	else if (c == '-')
		doSubstraction(myStack);
	else if (c == '*')
		doMultiplication(myStack);
	else if (c == '/')
	{
		if (doDivision(myStack) == -1)
			return (-1);
	}
	return 0;
}

void doAddition(std::stack<int> *myStack)
{
	int tmp = myStack->top();
	myStack->pop();
	tmp += myStack->top();
	myStack->pop();
	myStack->push(tmp);
}

void doSubstraction(std::stack<int> *myStack)
{
	int tmp = myStack->top();
	myStack->pop();
	int temp = myStack->top();
	myStack->pop();
	myStack->push(temp - tmp);
}

void doMultiplication(std::stack<int> *myStack)
{
	int tmp = myStack->top();
	myStack->pop();
	int temp = myStack->top();
	myStack->pop();
	myStack->push(temp * tmp);
}

int doDivision(std::stack<int> *myStack)
{
	int tmp = myStack->top();
	if (tmp == 0)
	{
		std::cout << "Error, cannot divide by 0 !" << std::endl;
		return (-1);
	}
	myStack->pop();
	int temp = myStack->top();
	myStack->pop();
	myStack->push(temp / tmp);
	return 0; 
}