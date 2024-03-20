/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:47:54 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/20 15:51:20 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
	private :
				const std::string _name;
				bool	_isSigned;
				const int _minSignGrade;
				const int _minExecGrade;
	public :
				AForm(void);
				AForm( std::string name, int minSign, int minExec);
				AForm( const AForm &toCopy);
				~AForm(void);
				AForm & operator= (const AForm &);
				
				virtual void execForm(Bureaucrat const & executor) const = 0;
				void execute(Bureaucrat const & executor) const;

				void beSigned(Bureaucrat *name);
				std::string getName(void) const;
				int getSign(void) const;
				int getExec(void) const;
				bool isSigned(void) const;
				
				void sign(void);
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

std::ostream &  operator<<( std::ostream & o, const AForm &name );

#endif