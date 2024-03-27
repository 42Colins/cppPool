/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:15:09 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/19 16:16:09 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <sstream>

# define to_string(value) static_cast<const std::ostringstream&>((\
std::ostringstream() << std::dec << value)).str()

class BitcoinExchange 
{
	private :
	
	public :
		
};

#endif