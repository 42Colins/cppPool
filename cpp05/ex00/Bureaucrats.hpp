/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrats.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:47:06 by cprojean          #+#    #+#             */
/*   Updated: 2024/01/10 18:21:58 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATS_HPP
# define BUREAUCRATS_HPP

# include "iostream"
# include "stdexcept"

class Bureaucrats 
{
	public :
				std::string _name;
				int	_grade;
	private :
				Bureaucrats( void );
				Bureaucrats( int grade, std::string name );
				Bureaucrats (const Bureaucrats &toCopy );
				~Bureaucrats ( void );
				Bureaucrats & operator=( const Bureaucrats & );
				std::string getName( void );
				int	getGrade( void );
				std::string	promotion( int grade );
				std::string	nearlyFired( int grade );
				class GradeTooHighException : public std::exception
				{
					public :
							virtual const char *error() const throw();
				};
				class GradeTooLowException : public std::exception
				{
					public :
							virtual const char *error() const throw();
				};
};

#endif