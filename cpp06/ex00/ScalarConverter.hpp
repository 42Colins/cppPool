/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:53:19 by cprojean          #+#    #+#             */
/*   Updated: 2024/02/21 17:50:15 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{	
	private :
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &toCopy);

	public :
		~ScalarConverter(void);
		ScalarConverter & operator= (const ScalarConverter &);
		static void	convert(const std::string convert);
};

#endif