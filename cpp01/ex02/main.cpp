/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:16:51 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/24 12:11:49 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{

	std::string	array = "HI THIS IS BRAIN";
	std::string	*stringPTR = &array;
	std::string	&stringREF = array;

	std::cout << &array << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << array << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

}