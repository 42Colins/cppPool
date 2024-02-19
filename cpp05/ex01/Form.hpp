/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:47:54 by cprojean          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:06 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
	private :
				const std::string _name;
				bool	_isSigned;
				const int _minSignGrade;
				const int _minExecGrade;
	public :
				Form(void);
				Form( std::string name, int minSign, int minExec);
				Form( const Form &toCopy);
				~Form(void);
				Form & operator= (const Form &);
				
				void beSigned(Bureaucrat *name);
				std::string getName(void) const;
				int getSign(void) const;
				int getExec(void) const;
				bool isSigned(void) const;
				
				void setName(std::string name);
				void setSign(int minSign);
				void setExec(int minExec);
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

std::ostream &  operator<<( std::ostream & o, const Form &name );

#endif