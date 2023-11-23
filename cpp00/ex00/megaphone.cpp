/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:40:00 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/15 12:09:31 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (-1);
    }
    for(size_t size = 1; argv[size]; size++)
    {
        std::string mystring = argv[size];
        for (size_t i = 0; i < mystring.length(); i++)
            std::cout << (char)toupper(mystring[i]);
    }
    std::cout << std::endl;
}
