/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:03:44 by cprojean          #+#    #+#             */
/*   Updated: 2024/03/20 16:25:43 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm;

class Intern
{
	private :
	public :
		Intern(void);
		Intern(const Intern &toCopy);
		~Intern(void);
		Intern & operator= (const Intern &);
		
		class NoSuchForm : public std::exception
				{
					public :
							virtual const char *what() const throw();
				};

		AForm *makeForm(std::string nameForm, std::string target);
};

#endif