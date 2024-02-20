/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:47:06 by cprojean          #+#    #+#             */
/*   Updated: 2024/02/15 18:35:00 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include "iostream"
# include "stdexcept"
# include "AForm.hpp"

class AForm;

class Bureaucrat 
{
	private :
				std::string _name;
				int	_grade;
	public :
				Bureaucrat( void );
				Bureaucrat( int grade, std::string name );
				Bureaucrat (const Bureaucrat &toCopy );
				~Bureaucrat ( void );
				Bureaucrat & operator=( const Bureaucrat & );
				std::string getName( void ) const;
				int	getGrade( void ) const;
				void	promotion( int grade );
				void	nearlyFired( int grade );
				void	signForm(AForm &form);
				void	executeForm(AForm const &form);
				class GradeTooHighException : public std::exception
				{
					public :
							virtual const char *what() const throw();
				};
				class GradeTooLowException : public std::exception
				{
					public :
							virtual const char *what() const throw();
				};
};

std::ostream &  operator<<( std::ostream & o, const Bureaucrat &name );

#endif